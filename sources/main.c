#define _WordCode_GLOBALS
#define _DATA_MANAGE_GLOBALS
//#define _DataChange_GLOBALS

//#include "STC15F2K48AS.h"
#include "TM1629A.h"
//#include "Mytype.h"
#include "DataManage.h"
#include "WordCode.h"
#include "CPU_Init.h"
#include "KeyBoard.h"
#include "Display.h"
#include "RN8209D.h"
#include "UartDeal.h"
#include "DataChange.h"

void sysDataInit(void){
	Calibration.Ks_IC_Span.data16 = 10000;
}

void main(){
	//io口初始化
	P1ASF = 0x00;//P1口模拟功能关闭
	P0M0 = 0x00;
	P0M1 = 0x00;
	RN8209D_SCSN_HIGH();
	
	WDT_CONTR = 0;//喂狗
	
	key_init();//按键初始化
	InitTimer0();
	UartRunInit();
	sysDataInit();
	RN8209D_Init();
	
	
	tm1629a_DIS_Open();
    WDT_CONTR |= 0x10;
    tm1629_DisAll();
	
	EA = 1;//全局中断使能

	
	while(1){
		Get_IRMS();
		key_check();
		tm1629_DisAll();
		Display_U();
		Display_I();
		WDT_CONTR |= 0x10;
	}
}