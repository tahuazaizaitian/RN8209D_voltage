#ifndef _DATA_MANAGE_H
	#define _DATA_MANAGE_H

//#include "Mytype.h"
#include "Mytype.h"
#ifdef 	_DATA_MANAGE_GLOBALS
	#define _DATA_MANAGE_EXT
#else
	#define _DATA_MANAGE_EXT	extern
#endif

	#ifdef  _DATA_MANAGE_GLOBALS
		u8 xdata LED0Buf = 0xff;
		u8 xdata LED1Buf = 0xff;
		u8 xdata SMGBuf[12];
		u8 xdata SetJM = 0;
		u8 xdata KeyBuf = 0;
		u8 xdata KEY_Back_State = 0;
		u8 xdata KEY_Set_State = 0;
		u8 xdata KEY_Up_State = 0;
		u8 xdata KEY_Move_State = 0;
	
		u8 xdata IARMS_Counter = 0;
		u8 xdata IBRMS_Counter = 0;
		u8 xdata ICRMS_Counter = 0;
		u32 xdata IABUF[10];
		u32 xdata IBBUF[10];
		u32 xdata ICBUF[10];
	#else
		_DATA_MANAGE_EXT	u8 xdata SMGBuf[]; 	  //显示缓存
		_DATA_MANAGE_EXT	u8 xdata LED0Buf;
		_DATA_MANAGE_EXT	u8 xdata LED1Buf;
		_DATA_MANAGE_EXT	u8 xdata SetJM;
		_DATA_MANAGE_EXT	u8 xdata KeyBuf;
		_DATA_MANAGE_EXT	u8 xdata KEY_Back_State;
		_DATA_MANAGE_EXT	u8 xdata KEY_Set_State;
		_DATA_MANAGE_EXT	u8 xdata KEY_Up_State;
		_DATA_MANAGE_EXT	u8 xdata KEY_Move_State;
		
		_DATA_MANAGE_EXT	u8 xdata IARMS_Counter;
		_DATA_MANAGE_EXT	u8 xdata IBRMS_Counter;
		_DATA_MANAGE_EXT	u8 xdata ICRMS_Counter;
		_DATA_MANAGE_EXT	u32 xdata IABUF[];
		_DATA_MANAGE_EXT	u32 xdata IBBUF[];
		_DATA_MANAGE_EXT	u32 xdata ICBUF[];
	#endif

#endif

