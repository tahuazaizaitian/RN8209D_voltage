#ifndef _TM1629A_H
#define _TM1629A_H

#ifdef 	_TM1629A_GLOBALS
#define _TM1629A_EXT
#else
#define _TM1629A_EXT	extern
#endif


#include "Mytype.h"

_TM1629A_EXT u8 xdata DspBit;			  
_TM1629A_EXT void tm1629a_DIS_Open(void);
_TM1629A_EXT void tm1629a_DIS_Close(void);
_TM1629A_EXT void tm1629_DisAll(void);
_TM1629A_EXT void WICDisBuf(void);
_TM1629A_EXT void tm1629aSendData(u8 a);
_TM1629A_EXT void SEG_LINE(u16 Data,u8 Line);
_TM1629A_EXT void WORD_LINE(u8 *word,u8 Line);
_TM1629A_EXT int GET_NUM_LINE(u8 Line);
#endif