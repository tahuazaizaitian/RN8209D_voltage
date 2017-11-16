#ifndef _RN8209D_H_
#define _RN8209D_H_

#include "Mytype.h"

#ifdef 	_RN8209D_GLOBALS
#define _RN8209D_EXT
#else
#define _RN8209D_EXT	extern
#endif


#define CMD_RN8209D_SYSCON	0x00	//系统控制寄存器，写保护
#define CMD_RN8209D_EMUCON	0x01	//计量控制寄存器，写保护
#define CMD_RN8209D_HFConst 0x02	//脉冲频率寄存器，写保护
#define CMD_RN8209D_PStart	0x03	//有功启动功率设置，写保护
#define CMD_RN8209D_DStart	0x04	//自定义电能启动功率设置，写保护

#define CMD_RN8209D_DCIAH	0x13	//IA通道直流offset补偿高16bit，写保护
#define CMD_RN8209D_DCIBH	0x14	//IA通道直流offset补偿高16bit，写保护
#define CMD_RN8209D_DCICH	0x15	//IA通道直流offset补偿高16bit，写保护
#define CMD_RN8209D_DCL		0x16	//三个直流offet校正寄存器的低4bit

#define CMD_RN8209D_EMUCON2 0x17	//计量控制寄存器2，写保护

#define CMD_RN8209D_IARms	0x22	//IA有效值
#define CMD_RN8209D_IBRms	0x23	//IB有效值
#define CMD_RN8209D_ICRms	0x24	//U有效值
#define CMD_RN8209D_IARMSOS 0x0e	//电流通道A有效值Offset补偿，写保护
#define CMD_RN8209D_IBRMSOS 0x0f	//电流通道B有效值Offset补偿，写保护
#define CMD_RN8209D_SPL_IA	0x30
#define CMD_RN8209D_SPL_IB	0x31

#define CMD_RN8209D_IEReg		0x40	//中断配置和允许寄存器
#define CMD_RN8209D_IEF			0x41	//中断状态寄存器，only read
#define CMD_RN8209D_EMUStatus	0x2D	//计量状态寄存器，only read
#define CMD_RN8209D_SysStatus	0x43	//系统状态寄存器
	


_RN8209D_EXT	void Write_RN8209D_Command(u8 addr);
_RN8209D_EXT	void Read_RN8209D_Command(u8 addr);
_RN8209D_EXT	void Write_RN8209D_DATA(u8 dat);
_RN8209D_EXT	u8 Read_RN8209D_DATA(void);
_RN8209D_EXT	void RN8209D_Init(void);
_RN8209D_EXT	u32 Read_IRMS(u8 addr);

_RN8209D_EXT	u32 get_ten_ave_IAMS(u8 addr);
_RN8209D_EXT	void DCL_OFFSET(u8 addr);
_RN8209D_EXT	void IRMS_OFFSET(u8 addr);
_RN8209D_EXT	void Get_IRMS(void);
_RN8209D_EXT	void bubble_sort(u32 *array,u16 num);
#endif