//UartDeal.h
/*
**--------------文件信息--------------------------------------------------------------------------------
**文   件   名: UartDeal.h
**创   建   人: 褚智宝
**最后修改日期: 2012年2月5日
**描        述:
**
**--------------历史版本信息----------------------------------------------------------------------------
** 创建人:褚智宝
** 版  本: V0.10
** 日　期: 2012年1月3日
** 描　述: 原始版本
**-----------------------------------------------------------------------------------------------------
*/
#ifndef _UartDeal_H
#define _UartDeal_H

#ifdef 	_UartDeal_GLOBALS
#define _UartDeal_EXT
#else
#define _UartDeal_EXT	extern
#endif
//

//=============================通讯功能码预定义============================
#define Com_ZeroV	 0x41
#define Com_SetKsU	 0x43
#define Com_SetKsI	 0x46
#define Com_SetKsP   0x49


#define Com_Zero_Out 	 0x51
#define Com_Tran_Step	 0x52
#define Com_Full_Out	 0x58
#define Com_RomClear     0x53
#define Com_ReadERAdr    0x54
#define Com_ReadVer      0x55


#define Com_RDLoadform01 	 0x01

#define Com_RDLoadform02	 0x02

#define Com_Loadform03 	 0x03

#define Com_Loadform04 	 0x04

#define Com_Loadform05 	 0x05

#define Com_Loadform06 	 0x06
#define Com_Loadform15   0x15
#define Com_Loadform16   0x16




//
#define UART_RX_BUF_LEN  40
#define UART_TX_BUF_LEN  130

/*Define UART parity mode*/
#define NONE_PARITY   1                  //None parity
#define ODD_PARITY    2                  //Odd parity(奇)
#define EVEN_PARITY   3                  //Even parity（偶）
#define MARK_PARITY   4                  //Mark parity
#define SPACE_PARITY  5			 //Space parity	 

//串口接收数据结构类型定义
typedef  struct
{
    Bool 	RxState;                //0--空闲　1--接收到数据等待处理
    u8   	RxBuf[UART_RX_BUF_LEN]; //串口数据接收缓冲
    vu16  	RxInPtr;                //串口接收缓冲写指针

    u16     timer0_cn;              //通讯等待时间
    u16     RxMsgLen;  		//待处理命令消息字节长度
} UART_RX_MGR;

//串口发送数据结构类型定义
typedef  struct
{
    Bool 	TxState;                //0--空闲　1--串口数据发送中
    u8   	TxBuf[UART_TX_BUF_LEN]; //串口数据发送缓冲
    vu16  	TxInPtr;                //串口发送缓冲读指针

    u16	TxDtLth;	        //串口发送数据块长度
} UART_TX_MGR;

typedef struct
{
    u8 RegBuf[124]; //串口映射
} REGBUF;

_UartDeal_EXT	UART_TX_MGR	xdata   Uart_Tx_Mgr;
_UartDeal_EXT	UART_RX_MGR	xdata   Uart_Rx_Mgr;
_UartDeal_EXT	REGBUF  	xdata   SysRegBuf;
_UartDeal_EXT 	bit busy;

_UartDeal_EXT   u8 PARITYBIT;    //奇偶校验位
_UartDeal_EXT	void UartRunInit(void);
_UartDeal_EXT	void UartSend(u8 dat);

#ifdef DEBUG_OUT
_UartDeal_EXT	Bool Debug_Print(u8 *ptr,u8 Length);
#endif


#endif
