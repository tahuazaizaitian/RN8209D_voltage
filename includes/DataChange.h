/*
**--------------τݾхϢ--------------------------------------------------------------------------------
**τ   ݾ   Ļ: DataManage.h
**Դ   ݨ   ɋ: 񒖇Ѧ	
**خ۳ўلɕǚ: 2012Ū2Ղ5ɕ
**Ĩ        ˶: 
**
**--------------zʷѦѾхϢ----------------------------------------------------------------------------
** Դݨɋ: 񒖇Ѧ	
** Ѧ  Ѿ: V0.10
** ɕaǚ: 2012Ū1Ղ3ɕ
** Ĩa˶: ԭʼѦѾ
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

		code float	voltagePmA	= 904.88;//A���ѹ����ϵ��
		code float	voltagePmB	= 904.88;//B���ѹ����ϵ��
		code float	voltagePmC	= 904.88;//C���ѹ����ϵ�� 
		
		code float	currentPmA	= 0.10;//1020.66;//A���������ϵ��
		code float	currentPmB	= 15;//B���������ϵ��
		code float	currentPmC	= 1020.66;//C���������ϵ��
		//Ƶ�ʼ���ϵ��
		code u32	SysHzPm		= 3834;//Ƶ�ʼ���ϵ��
		//code u32	SysHzPm		= 3813;//Ƶ�ʼ���ϵ��  
		
	#endif

		//���������ַ������Ĺ�����   
		union int_char   
		{   
			 u16 data16;   
			 u8 data8[2];   
		};   
		//���������ַ������Ĺ�����   
		union float_char   
		{   
			 float fdata32;   
			 u8 data8[4];   
		};     
		//�����������ַ������Ĺ�����   
		union long_char   
		{   
			 u32 data32;   
			 u8 data8[4];   
		};   
			
		 
		//�������д�����Ĵ�7758�����ĵ����,Ҳ��һ��������ģʽ�µ�ͨѶ���ͻ�����   
		struct all_data   
		{   
			union float_char      voltage[3];//�������ߵ�ѹֵ,����ֵ                12bytes   
			   
			union float_char      voltageLL[3];//�������ߵ�ѹѹֵ,����ֵ          	12bytes   
			   
			union float_char      current[3];//�������ֵ,����ֵ                  	12bytes   
			   
			union float_char      watt[4];//�����й����ʣ����һ���������ܺ�,����ֵ 16bytes   
			   
			union float_char      var[4];//�����޹����ʣ����һ���������ܺ�,����ֵ   16bytes   
			   
			union float_char      va[4];//�������ڹ��ʣ����һ���������ܺ�,����ֵ    16bytes  
			
			union float_char      sys_PF[4];//���๦�����أ����һ���������ܺ�       16bytes  
			
			union int_char        sys_AO;//ϵͳƵ��                                  2bytes 
			   
			union long_char       watt_hour[2];//�����й�����ֵ,����ֵ����ʼ��ʱӦ�ý�E2PROM�е����ݶ�������8bytes   
			   
			union long_char       var_hour[2];//�����޹�����ֵ,����ֵ�� ��ʼ��ʱӦ�ý�E2PROM�е����ݶ�������8bytes  
			 
		};
		
		//��ѹ�����м����
		typedef  struct 
		{
			union long_char		Tvoltage[3];
			union long_char		Tcurrent[3];
			union int_char		Hz;
			u8	VIReadCn;
		}VITEMPDATA;
		
		//��ʼ��ʱ��Ҫ�����ݴ�E2PROM�е����ݶ�������ÿ��1���Ӽ��һ�θ������Ƿ���ȷ
		typedef struct {
			union int_char Crc16;					//����У��						  
			union int_char Ks_VA_Span;				//A���ѹ����������ϵ��	  
			union int_char Ks_VB_Span;				//B���ѹ����������ϵ��	  
			union int_char Ks_VC_Span;				//C���ѹ����������ϵ�� 
			union int_char Ks_IA_Span;				//A���������������ϵ��	  
			union int_char Ks_IB_Span;				//B���������������ϵ��	  
			union int_char Ks_IC_Span;				//C���������������ϵ��
			s8 APHCAL_Span;		                //A����λ����ϵ������߹��ʾ���
			s8 BPHCAL_Span;		                //B����λ����ϵ������߹��ʾ���
			s8 CPHCAL_Span;	                        //C����λ����ϵ������߹��ʾ���
		}CALIBRATION; 

		typedef struct {					  	
			union int_char Ks_DA1_Max;				//4-20mA����1����У׼ϵ��
			union int_char Ks_DA1_Mid;				//4-20mA����1�м�ֵУ׼ϵ��
			union int_char Ks_DA1_Min;				//4-20mA����1��ֵУ׼ϵ��	  
			union int_char Ks_DA2_Max;				//4-20mA����2����У׼ϵ��
			union int_char Ks_DA2_Mid;				//4-20mA����2�м�ֵУ׼ϵ��
			union int_char Ks_DA2_Min;				//4-20mA����2��ֵУ׼ϵ��	  
			union int_char Ks_DA3_Max;				//4-20mA����3����У׼ϵ��
			union int_char Ks_DA3_Mid;				//4-20mA����3�м�ֵУ׼ϵ��
			union int_char Ks_DA3_Min;				//4-20mA����3��ֵУ׼ϵ��  
			union int_char Crc16;
		}MATRANSPAN;
		
		_DataChange_EXT		struct all_data	xdata		All_data;
		_DataChange_EXT		VITEMPDATA 	xdata 		VITempData;
		_DataChange_EXT		CALIBRATION	xdata		Calibration;

#endif 
