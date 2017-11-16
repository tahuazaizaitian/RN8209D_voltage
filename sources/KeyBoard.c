#define _KeyBoard_GLOBALS
//#define _DATA_MANAGE_GLOBALS
//#include "Mytype.h"
#include "DataManage.h"
#include "TM1629A.h"
#include "KeyBoard.h"
#include "WordCode.h"
#include "CPU_Init.h"

//按键初始化
void key_init(void){
	SetJM = 1;//电压电流显示界面
	KeyBuf = 0xff;
	KEY_Back_State = 1;
	KEY_Set_State = 1;
	KEY_Up_State = 1;
	KEY_Move_State = 1;
}

//按键检测
void key_check(void){
	if(Key_100ms){
		Key_100ms = 0;//清楚标志位
		//KEY1
		if(!KEY_Up){//低电平
			if(KEY_Up_State){
				KEY_Up_Deal();
				KEY_Up_State = 0;
			}
			else	return;
		}
		else
			KEY_Up_State = 1;
		
		//KEY2
		if(!KEY_Move){//低电平
			if(KEY_Move_State){
				KEY_Move_Deal();
				KEY_Move_State = 0;
			}
			else	return;
		}
		else
			KEY_Move_State = 1;
		
		//KEY3
		if(!KEY_Set){//低电平
			if(KEY_Set_State){
				KEY_Set_Deal();
				KEY_Set_State = 0;
			}
			else	return;
		}
		else
			KEY_Set_State = 1;
		
		//KEY4
		if(!KEY_Back){//低电平
			if(KEY_Back_State){
				KEY_Back_Deal();
				KEY_Back_State = 0;
			}
			else	return;
		}
		else
			KEY_Back_State = 1;
	}
}


void KEY_Back_Deal(void){
	if(SetJM > 1)//在任何界面都可返回数据显示界面
		SetJM = 1;
}


void KEY_Set_Deal(void){
	u16 SetCode;
	u16 temp;
	if(SetJM==1){//进入密码设置界面
		SetJM = 2;
		SetCode = 9999;
		WORD_LINE(&CODEcode,0);
		WORD_LINE(&Blankcode,1);
		SEG_LINE(SetCode,2);
	}
	else if(SetJM == 2){//判断密码是否正确
		temp = GET_NUM_LINE(2);
		if(temp == 1){//密码正确,进入电压参数设置界面
			SetJM = 3;
			WORD_LINE(&INPTcode,0);
			WORD_LINE(&RUcode,1);
			SEG_LINE(5438,2);
		}
		else{
			SetJM = 1;
		}
	}
	else if(SetJM == 3){//进入电流参数设置界面
		SetJM = 4;
		WORD_LINE(&INPTcode,0);
		WORD_LINE(&RIcode,1);
		SEG_LINE(3856,2);
	}
	else if(SetJM == 4){
		SetJM = 1;
	}
}


void KEY_Up_Deal(void){
	u16 temp;
	if(SetJM == 2){//调整密码
		temp = GET_NUM_LINE(2);
		if(temp == 9999) temp=0;
		else temp = temp+1;
		SEG_LINE(temp,2);
	}	
}


void KEY_Move_Deal(void){
	
}

