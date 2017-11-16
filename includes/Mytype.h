#ifndef _Mytype_H
#define _Mytype_H

#ifdef 	_Mytype_GLOBALS
#define _Mytype_EXT
#else
#define _Mytype_EXT	extern
#endif
#include "STC15F2K48AS.h"
typedef	float        s64;
typedef signed long  s32;
typedef signed short s16;
typedef signed char  s8;

typedef signed long  code sc32;  /* Read Only */
typedef signed short code sc16;  /* Read Only */
typedef signed char  code sc8;   /* Read Only */

typedef volatile signed long  vs32;
typedef volatile signed short vs16;
typedef volatile signed char  vs8;

typedef volatile signed long  code vsc32;  /* Read Only */
typedef volatile signed short code vsc16;  /* Read Only */
typedef volatile signed char  code vsc8;   /* Read Only */

typedef unsigned long  u32;
typedef unsigned short u16;
typedef unsigned char  u8;

typedef unsigned long  code uc32;  /* Read Only */
typedef unsigned short code uc16;  /* Read Only */
typedef unsigned char  code uc8;   /* Read Only */

typedef volatile unsigned long  vu32;
typedef volatile unsigned short vu16;
typedef volatile unsigned char  vu8;

typedef volatile unsigned long  code vuc32;  /* Read Only */
typedef volatile unsigned short code vuc16;  /* Read Only */
typedef volatile unsigned char  code vuc8;   /* Read Only */

typedef enum {FALSE = 0, TRUE = 1, NONE = 2} Bool;


//***************************************************************************
//          管脚配置
//***************************************************************************

//TM1629A
sbit tm1629_STB = P5^4;	//片选
sbit tm1629_CLK = P5^5;	//时钟信号
sbit tm1629_DATA = P1^3;//数据信号

#define TM1629_STB_HIGH()		tm1629_STB = 1
#define TM1629_STB_LOW()		tm1629_STB = 0

#define TM1629_CLK_HIGH()		tm1629_CLK = 1
#define TM1629_CLK_LOW()		tm1629_CLK = 0

#define TM1629_DIO_HIGH()		tm1629_DATA = 1
#define TM1629_DIO_LOW()		tm1629_DATA = 0
#define CMD_TM1629_WRITE				0x40
#define CMD_TM1629_READ 				0x42
#define CMD_TM1629_ADDRMODE 			0x44

//RN8209D
sbit RN8209D_SCSN = P0^0;	//片选
sbit RN8209D_SCLK = P0^1;	//时钟信号
sbit RN8209D_SDO = P0^2;	//发送数据
sbit RN8209D_SDI = P0^3;	//接收数据
#define RN8209D_SCSN_HIGH()		RN8209D_SCSN = 1
#define RN8209D_SCSN_LOW()		RN8209D_SCSN = 0
#define RN8209D_SCLK_HIGH()		RN8209D_SCLK = 1
#define RN8209D_SCLK_LOW()		RN8209D_SCLK = 0
#define RN8209D_SDO_HIGH()		RN8209D_SDO = 1
#define RN8209D_SDO_LOW()		RN8209D_SDO = 0

//KEY configure
sbit KEY_Back = P3^5;
sbit KEY_Set = P3^2;
sbit KEY_Up = P3^4;
sbit KEY_Move = P3^3;


#endif