#define _RN8209D_GLOBALS
#include "RN8209D.h"
#include <intrins.h> 
#include "CPU_Init.h"
#include "TM1629A.h"
#include "DataChange.h"
#include "DataManage.h"
#include "Display.h"
//RN8209D初始化
void RN8209D_Init(void){
	//软复位
	Write_RN8209D_Command(0xEA);
	Write_RN8209D_DATA(0xFA);
	
	//写使能命令
	Write_RN8209D_Command(0xEA);
	Write_RN8209D_DATA(0xE5);
	
	//功率及有效值寄存器更新频率设为13.982Hz
	Write_RN8209D_Command(CMD_RN8209D_EMUCON2);
	Write_RN8209D_DATA(0x00);
	Write_RN8209D_DATA(0x80);
	
	//数据更新时，中断标志位开启(0:DUPDIE)
	Write_RN8209D_Command(CMD_RN8209D_IEReg);
	Write_RN8209D_DATA(0x01);
	
	//步骤1：B通道打开，增益全部设为1
	Write_RN8209D_Command(CMD_RN8209D_SYSCON);
	Write_RN8209D_DATA(0x00);//高字节：0x00   低字节：0b0100 0000
	Write_RN8209D_DATA(0x40);
	
	//步骤1：关闭IA通道数字高通滤波器，关闭U通道数字高通滤波器
	Write_RN8209D_Command(CMD_RN8209D_EMUCON);
	Write_RN8209D_DATA(0x40);
	Write_RN8209D_DATA(0x60);
	
	//步骤2：直流offset校正
	DCL_OFFSET(CMD_RN8209D_IARms);
	
	//步骤3：有效值Offset补偿
	IRMS_OFFSET(CMD_RN8209D_IARms);
	
	
//	SEG_LINE(temp_IRMSOS>>8,0);
//	SEG_LINE(temp_IRMSOS&0xff,1);
}

//写命令寄存器，输入地址
void Write_RN8209D_Command(u8 addr){
	u8 i;
	u8 temp;
	temp = addr|0x80;//最高位为1
	RN8209D_SCSN_HIGH();
	RN8209D_SCLK_HIGH();
	RN8209D_SCSN_LOW();
	for(i=0;i<8;i++){
//		Delay1ms();
		if((temp&0x80)==0x80)
			RN8209D_SDO_HIGH();
		else
			RN8209D_SDO_LOW();
		RN8209D_SCLK_HIGH();
//		Delay1ms();
		RN8209D_SCLK_LOW();
		temp = temp << 1;
	}
	RN8209D_SCSN_LOW();
}

//写读寄存器，输入地址
void Read_RN8209D_Command(u8 addr){
	u8 i;
	u8 temp;
	temp = addr & 0xef;//最高位为0
	RN8209D_SCSN_HIGH();
	RN8209D_SCLK_HIGH();
	RN8209D_SCSN_LOW();
	for(i=0;i<8;i++){
//		Delay1ms();
		if((temp&0x80)==0x80)
			RN8209D_SDO_HIGH();
		else
			RN8209D_SDO_LOW();
		RN8209D_SCLK_HIGH();
		RN8209D_SCLK_LOW();
		temp = temp<< 1;
	}
}

//写数据
void Write_RN8209D_DATA(u8 dat){
	u8 i;
	for(i=0;i<8;i++){
//		Delay1ms();
		if((dat&0x80)==0x80)
			RN8209D_SDO_HIGH();
		else
			RN8209D_SDO_LOW();
		RN8209D_SCLK_HIGH();
//		Delay1ms();
		RN8209D_SCLK_LOW();
		dat = dat<< 1;
	}
//	Delay1ms();
}

//读数据,读一个字节
u8 Read_RN8209D_DATA(void){
	u8 i;
	u8 temp;
	temp = 0;
	for(i=0;i<8;i++){
		temp = temp << 1;
//		Delay1ms();
		RN8209D_SCLK_HIGH();
//		Delay1ms();
		RN8209D_SCLK_LOW();
		if(RN8209D_SDI)
			temp = temp | 0x01;
	}
//	Delay1ms();
	return temp;
}

//读有效值，输入地址
u32 Read_IRMS(u8 addr){
	u32 temp;
	u32 temp_H;
	u32 temp_N;
	u32 temp_L;
	Read_RN8209D_Command(addr);
	temp_H = Read_RN8209D_DATA();
	temp_N = Read_RN8209D_DATA();
	temp_L = Read_RN8209D_DATA();
	temp = (temp_H<<16) + (temp_N<<8) + temp_L;
	return temp;
}

//获得十次有效值，并计算平均值
u32 get_ten_ave_IAMS(u8 addr){
	u8 i;
	u32 temp;
	temp = 0;
	for(i=0;i<10;i++){
		while(!(Read_RN8209D_DATA()&0x01))
			Read_RN8209D_Command(CMD_RN8209D_IEF);
		temp = temp + Read_IRMS(addr);
		Delay5ms();
	}
	temp = temp/10;		//求平均值
	return temp;
}

//DC_OFFSET校正
void DCL_OFFSET(u8 addr){
	u16 i;
	u32 IARMS_ave_first;
	u32 IARMS_ave_second;
	IARMS_ave_first = get_ten_ave_IAMS(addr);
	//1第一次写入
	Write_RN8209D_Command(CMD_RN8209D_DCIAH);
	Write_RN8209D_DATA(IARMS_ave_first>>16);
	Write_RN8209D_DATA((IARMS_ave_first>>8)&0xff);
	
	Write_RN8209D_Command(CMD_RN8209D_DCL);
	Write_RN8209D_DATA((IARMS_ave_first>>4)&0x0f);
	
	//2s delay
	for(i=0;i<400;i++)	Delay5ms();
	
	//2验证
	IARMS_ave_second = get_ten_ave_IAMS(addr);
	if(IARMS_ave_first>IARMS_ave_second);
	else{
		IARMS_ave_first = ~IARMS_ave_first;
		Write_RN8209D_Command(CMD_RN8209D_DCIAH);
		Write_RN8209D_DATA(IARMS_ave_first>>16);
		Write_RN8209D_DATA((IARMS_ave_first>>8)&0xff);
		
		Write_RN8209D_Command(CMD_RN8209D_DCL);
		Write_RN8209D_DATA((IARMS_ave_first>>4)&0x0f);
	}
}

//校正IARMS寄存器
void IRMS_OFFSET(u8 addr){
	u32 temp;	//存放返回值
	u32 Iave;
	temp = 0;
	Iave = 0;

	Iave = get_ten_ave_IAMS(addr);		//求平均值
	
//	WriteToDisp(Iave>>16,3,&SMGBuf[0]);
//	WriteToDisp((Iave>>8)&0xff,3,&SMGBuf[1]);
//	WriteToDisp(Iave&0xff,3,&SMGBuf[2]);
	Iave = Iave*Iave;	//求平方
	Iave = ~Iave;		//求反码
	temp = (u16)(Iave>>8);
	Write_RN8209D_Command(CMD_RN8209D_IARMSOS);
	Write_RN8209D_DATA(temp>>8);
	Write_RN8209D_DATA(temp&0xff);
}

//周期获得采样值
void Get_IRMS(void){
	u8 i;
	u32 temp_IARMS = 0;
	u32 IA_SUM = 0;
	float f32;
	if(Sample_25){
		Sample_25 = 0;	//清楚标志位
		Read_RN8209D_Command(CMD_RN8209D_IEF);
		if(Read_RN8209D_DATA()&0x01){
			temp_IARMS = Read_IRMS(CMD_RN8209D_IARms);
			//test
//			WriteToDisp(temp_IARMS>>16,3,&SMGBuf[0]);
//			WriteToDisp((temp_IARMS>>8)&0xff,3,&SMGBuf[4]);
//			WriteToDisp(temp_IARMS&0xff,3,&SMGBuf[8]);
			
			IABUF[IARMS_Counter] = temp_IARMS;
			IARMS_Counter ++;
			if(IARMS_Counter > 9){
				IARMS_Counter = 0;
//				bubble_sort(&IABUF[0],10);
				for(i=2;i<8;i++){
					IA_SUM = IA_SUM + IABUF[i];
				}
				VITempData.Tcurrent[0].data32 = IA_SUM/6;
			}
			f32 = ((float)(VITempData.Tcurrent[0].data32)*1.147/10000);//128
			All_data.current[0].fdata32 = f32;
		}
	}
}

//冒泡排序
void bubble_sort(u32 *array,u16 num)
{
	u16 i = 0;
	u16 j = 0;
	u16 temp;
	for(;j < num;++j)
	{
		for(i= num;i >j ;--i)
		{
			if(array[i] < array[i-1])
			{
				temp =array[i];
				array[i] = array[i-1];
				array[i-1] = temp;
			}
		}
	}
}