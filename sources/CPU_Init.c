#define  _CPUINIT_GLOBALS
#define  _DataManage_GLOBALS
#include "CPU_Init.h"
#include "STC15F2K48AS.h"

#include <intrins.h>  
//5ms软件计时，调试用
void Delay5ms(void)		//@11.0592MHz
{
	unsigned char i, j;
	i = 54;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}

void InitTimer0(void)
{
	TMOD &= 0xf0;
	TMOD |= 0x01;
	TH0 = 0xed;
	TL0 = 0xff;
	ET0 = 1;
	TR0 = 1;
}

//中断服务，时基：5ms
void Timer0Interrupt(void) interrupt 1
{
	TH0 = 0xed;
	TL0 = 0xff;
	//test
//	if(P04)
//		P04 = 0;
//	else
//		P04 = 1;
		
	Sample_timing ++;
	Key_timing ++;
	Display_timing ++;
	//25ms
	if(Sample_timing > 4){
		Sample_timing = 0;
		Sample_25 = 1;
	}
	
	//100ms
	if(Key_timing > 19){
		Key_timing = 0;
		Key_100ms = 1;
	}
	
	//100ms
	if(Display_timing > 18){
		Display_timing = 0;
		Display_100ms = 1;
	}
}

