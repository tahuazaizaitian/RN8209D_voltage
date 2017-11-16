//UartDeal.h
/*
**--------------�ļ���Ϣ--------------------------------------------------------------------------------
**��   ��   ��: UartDeal.h
**��   ��   ��: ���Ǳ�
**����޸�����: 2012��2��5��
**��        ��:
**
**--------------��ʷ�汾��Ϣ----------------------------------------------------------------------------
** ������:���Ǳ�
** ��  ��: V0.10
** �ա���: 2012��1��3��
** �衡��: ԭʼ�汾
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

//=============================ͨѶ������Ԥ����============================
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
#define ODD_PARITY    2                  //Odd parity(��)
#define EVEN_PARITY   3                  //Even parity��ż��
#define MARK_PARITY   4                  //Mark parity
#define SPACE_PARITY  5			 //Space parity	 

//���ڽ������ݽṹ���Ͷ���
typedef  struct
{
    Bool 	RxState;                //0--���С�1--���յ����ݵȴ�����
    u8   	RxBuf[UART_RX_BUF_LEN]; //�������ݽ��ջ���
    vu16  	RxInPtr;                //���ڽ��ջ���дָ��

    u16     timer0_cn;              //ͨѶ�ȴ�ʱ��
    u16     RxMsgLen;  		//������������Ϣ�ֽڳ���
} UART_RX_MGR;

//���ڷ������ݽṹ���Ͷ���
typedef  struct
{
    Bool 	TxState;                //0--���С�1--�������ݷ�����
    u8   	TxBuf[UART_TX_BUF_LEN]; //�������ݷ��ͻ���
    vu16  	TxInPtr;                //���ڷ��ͻ����ָ��

    u16	TxDtLth;	        //���ڷ������ݿ鳤��
} UART_TX_MGR;

typedef struct
{
    u8 RegBuf[124]; //����ӳ��
} REGBUF;

_UartDeal_EXT	UART_TX_MGR	xdata   Uart_Tx_Mgr;
_UartDeal_EXT	UART_RX_MGR	xdata   Uart_Rx_Mgr;
_UartDeal_EXT	REGBUF  	xdata   SysRegBuf;
_UartDeal_EXT 	bit busy;

_UartDeal_EXT   u8 PARITYBIT;    //��żУ��λ
_UartDeal_EXT	void UartRunInit(void);
_UartDeal_EXT	void UartSend(u8 dat);

#ifdef DEBUG_OUT
_UartDeal_EXT	Bool Debug_Print(u8 *ptr,u8 Length);
#endif


#endif
