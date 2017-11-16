//#define  _WordCode_GLOBALS
//#define  _DATA_MANAGE_GLOBALS
#define  _TM1629A_GLOBALS
#include "TM1629A.h"
#include "WordCode.h"
#include "DataManage.h"
#include "RN8209D.h"
void tm1629a_DIS_Open(void)
{
    tm1629_STB=0;
    tm1629aSendData(0x01|0x88);//亮度设置
    tm1629_STB=1;
}

void TM1629_OutByte(unsigned char dat)
{
    unsigned char i;

    for(i=0; i<8; i++)
    {
        TM1629_CLK_LOW();
        if((dat & 0x01) == 0x01)
            TM1629_DIO_HIGH();
        else
            TM1629_DIO_LOW();
        //nop();											
        TM1629_CLK_HIGH();											
        dat >>= 1;
    }
}

void TM1629_SendAddr(unsigned char addr)
{
    TM1629_STB_HIGH();											
    TM1629_CLK_HIGH();

    TM1629_STB_LOW();											
    //nop();													
    TM1629_OutByte(addr);
}

/**********************************************************************
功能：数码管常显示
输入：
输出：无
***********************************************************************/
void tm1629_DisAll(void)
{
    tm1629_STB=0;
//	tm1629aSendData(0x44);//ÉèÖÃÊý¾ÝÃüÁîÐ´Êý¾Ý|µØÖ·×Ô¶¯Ôö¼Ó|Õý³£Ä£Ê½
    tm1629aSendData(0x40);//设置数据命令写数据|地址自动增加|正常模式
    tm1629_STB=1;

    tm1629_STB=0;
    WICDisBuf();
    tm1629_STB=1;
}

/* 向指定起始显示寄存器写入数据块 */
void	TM1629_WriteBlock( unsigned char addr, unsigned char len, unsigned char* buf )
{
    TM1629_SendAddr( addr );
    while ( len -- ) TM1629_OutByte( *buf++ );
    TM1629_STB_HIGH();
}

/**********************************************************
共阴代码转换成共阳代码
pSrcBuf：存放共阴代码
pDstBuf：存放共阳代码
n：转换长度
**********************************************************/
//void convert1(unsigned char*pSrcBuf,unsigned char*pDstBuf,unsigned char n)
//{
//    unsigned char i,j,s,tmp,count,index;

//    count = 0x01;
//    s=0x01;
//    for(i=0; i<n; i++)
//    {
//        tmp = *(pSrcBuf+i);    //转换第i个byte
//        for(j = 0; j<8; j++)
//        {
//            if(i<8) index = 2*j; //每一字节的8位都转换在不同的显示地址中
//				else index=2*j+1;
//            if((tmp&count)==count)	 *(pDstBuf+index) = *(pDstBuf+index) | (s);   //置1
//				else pDstBuf[index] = *(pDstBuf+index) & (~s);                      //置0
//            if(count==0x80) count=0x01;
//				else count <<= 1;
//        }
//        if(s==0x80) s=0x01;
//        else s <<= 1;
//    }
//}

/***********************************************************************
功能：逐个点亮数码管
输入：
输出：无
***********************************************************************/
void WICDisBuf(void)
{
    /*u8 i;

    switch (DspBit)
        {
                //ÊýÂë¹Ü
                case 1: //ÏÔÊ¾µÚÒ»¸öÊýÂë¹Ü
        	        tm1629_STR=0;
    		tm1629aSendData(0xc9);//µÚ9 11 13 15 ¸öÏÔ´æµØÖ· ¶ÔÓ¦ÊýÂë¹Ü  8  9  10  11
    		tm1629aSendData(SMGmap[SMGBuf[2]]); //³ýÈ¥×îµÍÎ»ÔÙÐ´
    		tm1629_STR=1;
    		tm1629_STR=0;
    		tm1629aSendData(0xcb);//µÚ9 11 13 15 ¸öÏÔ´æµØÖ· ¶ÔÓ¦ÊýÂë¹Ü  8  9  10  11
    		tm1629aSendData(SMGmap[SMGBuf[3]]); //³ýÈ¥×îµÍÎ»ÔÙÐ´
    		tm1629_STR=1;
    		tm1629_STR=0;
    		tm1629aSendData(0xcd);//µÚ9 11 13 15 ¸öÏÔ´æµØÖ· ¶ÔÓ¦ÊýÂë¹Ü  8  9  10  11
    		tm1629aSendData(SMGmap[SMGBuf[1]]); //³ýÈ¥×îµÍÎ»ÔÙÐ´
    		tm1629_STR=1;
    		tm1629_STR=0;
    		tm1629aSendData(0xcf);//µÚ9 11 13 15 ¸öÏÔ´æµØÖ· ¶ÔÓ¦ÊýÂë¹Ü  8  9  10  11
    		tm1629aSendData(SMGmap[SMGBuf[0]]); //³ýÈ¥×îµÍÎ»ÔÙÐ´
    		tm1629_STR=1;
                break;
    	case 2: //ÏÔÊ¾µÚÒ»¸öÊýÂë¹Ü
        	        for (i=4;i<8;i++)
    		{
    			tm1629_STR=0;
    			tm1629aSendData(0xc0|(((i-4)<<1)+1));//µÚ1 3 5 7 ¸öÏÔ´æµØ
    			tm1629aSendData(SMGmap[SMGBuf[i]]); //³ýÈ¥×îµÍÎ»ÔÙÐ´
    			tm1629_STR=1;
    		}
                break;
    	case 3: //ÏÔÊ¾µÚÒ»¸öÊýÂë¹Ü
        	        for (i=8;i<12;i++)
    		{
    			tm1629_STR=0;
    			tm1629aSendData(0xc0|(i-8)<<1);//µÚ0 2 4 6 8 10 12 14 ¸öÏÔ´æµØÖ· ¼ûdatasheet ×óÒÆÒ»Î»Ïàµ±ÓÚ³Ë2
    			tm1629aSendData(SMGmap[SMGBuf[i]]);//×éºÏµ±Ç°Êý¾ÝºÍ¶ÔÓ¦Êý¾Ý£¬×î¸ßÎ»»»Îª¶ÔÓ¦Êý¾ÝµÄµÄ×îµÍÎ»¡£
    			tm1629_STR=1;
    		}
                break;
    	case 4: //ÏÔÊ¾µÚÒ»¸öÊýÂë¹Ü
    		tm1629_STR=0;
    		tm1629aSendData(0xc8);//µÚ9 11 13 15 ¸öÏÔ´æµØÖ· ¶ÔÓ¦ÊýÂë¹Ü  8  9  10  11
    		tm1629aSendData(LED1Buf); //³ýÈ¥×îµÍÎ»ÔÙÐ´
    		tm1629_STR=1;
    		tm1629_STR=0;
    		tm1629aSendData(0xca);//µÚ9 11 13 15 ¸öÏÔ´æµØÖ· ¶ÔÓ¦ÊýÂë¹Ü  8  9  10  11
    		tm1629aSendData(LED0Buf); //³ýÈ¥×îµÍÎ»ÔÙÐ´
    		tm1629_STR=1;
    	break;
                default:
    		DspBit = 0;
    	break;
    }
    DspBit++;

    */
	u8 i,j;
	u8 temp;
    unsigned char BUF[18]= {0xfF,0xff,0xff,0xfF,0xff,0xfF,0xff,0xff,0xff,
                            0xfF,0xff,0xff,0xfF,0xff,0xff,0xff,0xff,0xff
                           };
    unsigned char BUF1[18]=	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    BUF[0]=SMGmap[SMGBuf[8]];
    BUF[1]=SMGmap[SMGBuf[0]];
    BUF[2]=SMGmap[SMGBuf[9]];
    BUF[3]=SMGmap[SMGBuf[1]];

    BUF[4]=SMGmap[SMGBuf[10]];
    BUF[5]=SMGmap[SMGBuf[2]];
    BUF[6]=SMGmap[SMGBuf[11]];
    BUF[7]=SMGmap[SMGBuf[3]];

    BUF[8]=SMGmap[SMGBuf[4]];
    BUF[9]=SMGmap[0x37];
    BUF[10]=SMGmap[SMGBuf[5]];
    BUF[11]=SMGmap[0x37];
	BUF[12]=SMGmap[SMGBuf[6]];
    BUF[13]=SMGmap[0x37];
	BUF[14]=SMGmap[SMGBuf[7]];
    BUF[15]=SMGmap[0x37];
	
	for(i=0;i<16;i++){
		temp = 0;
		for(j=0;j<8;j++){
			temp = temp<<1;
			if(BUF[i]&0x01)	temp |=0x01;
				else;
			BUF[i] = BUF[i]>>1;
		}
		BUF[i] = temp;
	}
	
	
//    BUF[12]=LED0Buf;
//    BUF[13]=LED1Buf;


//    convert1(BUF,BUF1,16);//共阳转共阴

    TM1629_WriteBlock(0xc0,16,BUF);
}

/**********************************************************************
功能：向TM1629A芯片写入一个命令字
输入：
输出：无
***********************************************************************/
void tm1629aSendData(u8 a)
{
    u8 i;
    for(i=0; i<8; i++)
    {
        tm1629_CLK=0;
        tm1629_DATA=(a&0x01==1)?1:0;
        a>>=1;
        tm1629_CLK=1;
    }
}

//在特定行显示数值，0~999
void SEG_LINE(u16 Data,u8 Line){
	u8 temp;
	temp = Line*4;
//	if(SetJM==1){
//		if(Data >999)
//			SMGBuf[temp] = Data/1000;
//		else
//			SMGBuf[temp] = 0x37;
//	}
//	else
	SMGBuf[temp] = Data/1000;
	SMGBuf[temp+1] = Data/100%10;
	SMGBuf[temp+2] = Data/10%10;
	SMGBuf[temp+3] = Data%10;
}


//在特定行显示字符
void WORD_LINE(u8 *word,u8 Line){
	u8 temp;
	temp = Line*4;
	SMGBuf[temp] = *word;
	SMGBuf[temp+1] = *(word+1);
	SMGBuf[temp+2] = *(word+2);
	SMGBuf[temp+3] = *(word+3);
}

//获取特定行整数值
int GET_NUM_LINE(u8 Line){
	u16 temp;
	temp = SMGBuf[Line*4]*1000 + SMGBuf[Line*4+1]*100 + SMGBuf[Line*4+2]*10 + SMGBuf[Line*4+3];
	return temp;
}