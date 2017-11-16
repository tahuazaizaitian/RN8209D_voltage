/*
**--------------蟿菥褏息--------------------------------------------------------------------------------
**蟿   菥   幕: DataManage.h
**源   莰   蓩: 駫枃薛	
**禺鄢褳賱蓵菤: 2012弄2諅5蓵
**抹        硕: 
**
**--------------z史薛丫褏息----------------------------------------------------------------------------
** 源莰蓩: 駫枃薛	
** 薛  丫: V0.10
** 蓵a菤: 2012弄1諅3蓵
** 抹a硕: 原始薛丫
**-----------------------------------------------------------------------------------------------------
*/
#include "Mytype.h"

#ifndef _DataChange_H
	#define _DataChange_H

	#ifdef 	_DataChange_GLOBALS
		#define _DataChange_EXT
	#else 
		#define _DataChange_EXT	extern 
	#endif
	//---------------------------------------------------------

	#ifdef 	_DataChange_GLOBALS

		code float	voltagePmA	= 904.88;//A相电压计算系数
		code float	voltagePmB	= 904.88;//B相电压计算系数
		code float	voltagePmC	= 904.88;//C相电压计算系数 
		
		code float	currentPmA	= 0.10;//1020.66;//A相电流计算系数
		code float	currentPmB	= 15;//B相电流计算系数
		code float	currentPmC	= 1020.66;//C相电流计算系数
		//频率计算系数
		code u32	SysHzPm		= 3834;//频率计算系数
		//code u32	SysHzPm		= 3813;//频率计算系数  
		
	#endif

		//整型数和字符型数的共用体   
		union int_char   
		{   
			 u16 data16;   
			 u8 data8[2];   
		};   
		//浮点数和字符型数的共用体   
		union float_char   
		{   
			 float fdata32;   
			 u8 data8[4];   
		};     
		//长整型数和字符型数的共用体   
		union long_char   
		{   
			 u32 data32;   
			 u8 data8[4];   
		};   
			
		 
		//保存所有处理过的从7758中来的电参量,也是一个在正常模式下的通讯发送缓冲区   
		struct all_data   
		{   
			union float_char      voltage[3];//三相四线电压值,二次值                12bytes   
			   
			union float_char      voltageLL[3];//三相三线电压压值,二次值          	12bytes   
			   
			union float_char      current[3];//三相电流值,二次值                  	12bytes   
			   
			union float_char      watt[4];//三相有功功率，最后一个是三相总和,二次值 16bytes   
			   
			union float_char      var[4];//三相无功功率，最后一个是三相总和,二次值   16bytes   
			   
			union float_char      va[4];//三相视在功率，最后一个是三相总和,二次值    16bytes  
			
			union float_char      sys_PF[4];//三相功率因素，最后一个是三相总和       16bytes  
			
			union int_char        sys_AO;//系统频率                                  2bytes 
			   
			union long_char       watt_hour[2];//正负有功电能值,二次值，初始化时应该将E2PROM中的数据读出来。8bytes   
			   
			union long_char       var_hour[2];//正负无功电能值,二次值， 初始化时应该将E2PROM中的数据读出来。8bytes  
			 
		};
		
		//电压电流中间变量
		typedef  struct 
		{
			union long_char		Tvoltage[3];
			union long_char		Tcurrent[3];
			union int_char		Hz;
			u8	VIReadCn;
		}VITEMPDATA;
		
		//初始化时需要将数据从E2PROM中的数据读出来，每隔1分钟检查一次该数据是否正确
		typedef struct {
			union int_char Crc16;					//数据校验						  
			union int_char Ks_VA_Span;				//A相电压满量程增益系数	  
			union int_char Ks_VB_Span;				//B相电压满量程增益系数	  
			union int_char Ks_VC_Span;				//C相电压满量程增益系数 
			union int_char Ks_IA_Span;				//A相电流满量程增益系数	  
			union int_char Ks_IB_Span;				//B相电流满量程增益系数	  
			union int_char Ks_IC_Span;				//C相电流满量程增益系数
			s8 APHCAL_Span;		                //A相相位补偿系数，提高功率精度
			s8 BPHCAL_Span;		                //B相相位补偿系数，提高功率精度
			s8 CPHCAL_Span;	                        //C相相位补偿系数，提高功率精度
		}CALIBRATION; 

		typedef struct {					  	
			union int_char Ks_DA1_Max;				//4-20mA变送1满度校准系数
			union int_char Ks_DA1_Mid;				//4-20mA变送1中间值校准系数
			union int_char Ks_DA1_Min;				//4-20mA变送1零值校准系数	  
			union int_char Ks_DA2_Max;				//4-20mA变送2满度校准系数
			union int_char Ks_DA2_Mid;				//4-20mA变送2中间值校准系数
			union int_char Ks_DA2_Min;				//4-20mA变送2零值校准系数	  
			union int_char Ks_DA3_Max;				//4-20mA变送3满度校准系数
			union int_char Ks_DA3_Mid;				//4-20mA变送3中间值校准系数
			union int_char Ks_DA3_Min;				//4-20mA变送3零值校准系数  
			union int_char Crc16;
		}MATRANSPAN;
		
		_DataChange_EXT		struct all_data	xdata		All_data;
		_DataChange_EXT		VITEMPDATA 	xdata 		VITempData;
		_DataChange_EXT		CALIBRATION	xdata		Calibration;

#endif 
