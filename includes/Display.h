#ifndef _Display_H
#define _Display_H

#include "Mytype.h"

#ifdef 	_Display_GLOBALS
#define _Display_EXT
#else
#define _Display_EXT	extern
#endif




_Display_EXT	void Display_U(void);
_Display_EXT	void Display_I(void);
_Display_EXT	void WriteToDisp(u16 intData,u8 DecBit,u8 *buf);
#endif