#define  _UartDeal_GLOBALS

//#include "STC15F2K48AS.h"
#include "Mytype.h"
#include "UartDeal.h"
#include "CPU_Init.h"
#include "KeyBoard.h"


void UartRunInit(void)
{
	SCON = 0x50;            //8ä½å¯å˜æ³¢ç‰¹çŽ‡
	T2L = (65536-(11059200/4/4800));	//65536-(FOSC/4/BAUD)
	T2H = (65536-(11059200/4/4800))>>8;
    AUXR = 0x14;
	AUXR |= 0x01;
	ES = 1;
	EA = 1;
}


#ifdef DEBUG_OUT
Bool Debug_Print(u8 *ptr,u8 Length)
{
    u8 i;
    //
    if(Uart_Tx_Mgr.TxState==FALSE)
    {
        for(i=0; i<Length; i++)
        {
            Uart_Tx_Mgr.TxBuf[i] = ptr[i];
        }
        //
        Uart_Tx_Mgr.TxInPtr = 0;
        Uart_Tx_Mgr.TxDtLth = (Length-1);
        Uart_Tx_Mgr.TxState = TRUE;
        if ((PARITYBIT == ODD_PARITY) || (PARITYBIT == EVEN_PARITY))
        {
            Chenck_fun(Uart_Tx_Mgr.TxBuf[0]);
        }
        SBUF = Uart_Tx_Mgr.TxBuf[0];
        //
        return TRUE;
    }
    //
    return FALSE;
}
#endif


void UartSend(u8 dat)
{
    while(busy);
	busy = 1;
	ACC = dat; 
	SBUF = ACC;
}


void Serialint() interrupt 4 //´®¿ÚÖÐ¶Ï
{
    //2012-02-04 15:23 ñÒÖÇ±¦
    if (TI){
		TI = 0;
		busy = 0;
	}
	if (RI){
		RI = 0;
		
	}
}












