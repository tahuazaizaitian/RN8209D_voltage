#ifndef _CPU_Init_H
#define _CPU_Init_H

#include "Mytype.h"

#ifdef 	_CPUINIT_GLOBALS
#define _CPUINIT_EXT
#else
#define _CPUINIT_EXT	extern
#endif


_CPUINIT_EXT	u8	Sample_25;
_CPUINIT_EXT	u8	Sample_timing;
_CPUINIT_EXT	u8	Key_100ms;
_CPUINIT_EXT	u8	Key_timing;
_CPUINIT_EXT	u8	Display_100ms;
_CPUINIT_EXT	u8	Display_timing;
_CPUINIT_EXT	void Delay5ms(void);
_CPUINIT_EXT	void InitTimer0(void);

#endif