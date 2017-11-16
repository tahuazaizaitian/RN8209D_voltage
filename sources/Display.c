#define _Display_GLOBALS
#define _DataChange_GLOBALS

#include "Display.h"
#include "DataManage.h"
#include "TM1629A.h"
#include "RN8209D.h"
#include "UartDeal.h"
#include "DataChange.h"
#include "CPU_Init.h"


void Display_U(void){
	
}


void Display_I(void){
	u32 temp_IA = 0;
	if(Display_100ms){
		Display_100ms = 0;
		if(SetJM == 1){
			WriteToDisp(All_data.current[0].fdata32,0,&SMGBuf[0]);
			
		}
	}
}

/**********************************************************************
功能：显示数值转换函数
输入：
	intData：数据
	DecBit：0：显示3位小数
			1：显示2位小数
			2：显示1位小数
			3：不显示小数
	*buf：缓存指针
***********************************************************************/
void WriteToDisp(u16 intData,u8 DecBit,u8 *buf)
{
        u8 i;
        if (DecBit == 0) //显示3位小数
        {
                for(i=0;i<4;i++)
                {
                        *(buf+3-i) = (intData%10);         
                        if(DecBit == 3-i)
                                *(buf+3-i) = (intData%10)+0x10;             
                        intData /= 10;
                }         
        }
        else if (DecBit == 1) //显示2位小数
        {
                for(i=0;i<3;i++)
                {
                        *(buf+3-i) = intData%10;         
                        if(DecBit == 3-i)
                                *(buf+3-i) = intData%10+0x10;             
                        intData /= 10;
                }    
                if (intData == 0) //intData <= 999      
                        *buf = 0x37; //Ö±½ÓÃðÁã
                else 
                        *buf = intData%10;       
                }
        else if (DecBit == 2) //显示1位小数
        {
                for(i=0;i<2;i++)
                {
                        *(buf+3-i) = intData%10;         
                        if(DecBit == 3-i)
                                *(buf+3-i) = intData%10+0x10;             
                        intData /= 10;
                }    
                if (intData == 0) //intData <= 99
                {
                        *(buf+1) = 0x37; //Ö±½ÓÃðÁã
                        *buf = 0x37; //Ö±½ÓÃðÁã            
                }
                else 
                {
                        *(buf+1) = intData%10;
                        intData /= 10;
                        if (intData == 0)
                                *buf = 0x37; //Ö±½ÓÃðÁã            
                        else 
                                *buf = intData%10;       
                }
        }
        else if (DecBit == 3)//不显示小数
        {
                for(i=0;i<4;i++) //×¨ÎªÏÔÊ¾¹¦ÂÊÒòÊýÉè¼Æ
                {
                        *(buf+3-i) = intData%10;         
                        intData /= 10;
                }               

        }
        else if (DecBit == 4) //×¨ÎªÏÔÊ¾¹¦ÂÊÒòÊýÉè¼Æ
        {
                for(i=0;i<3;i++) 
                {
                        *(buf+3-i) = intData%10;         
                        intData /= 10;
                }               
        }
        else if (DecBit == 5) //×¨ÎªÏÔÊ¾ÄÜÁ¿Éè¼Æ
        {
                for(i=0;i<4;i++)
                {
                        *(buf+3-i) = intData%10;         
                        if(DecBit == 7-i)
                                *(buf+3-i) = intData%10+0x10; //ÏÖÊµÁ½Î»Ð¡Êý             
                        intData /= 10;
                }         
        }
}

