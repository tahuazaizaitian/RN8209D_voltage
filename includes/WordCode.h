/*
**--------------ÎÄ¼þÐÅÏ¢--------------------------------------------------------------------------------

*/
#include "mytype.h"

#ifndef _WordCode_H
#define _WordCode_H

#ifdef 	_WordCode_GLOBALS
#define _WordCode_EXT
#else
#define _WordCode_EXT	extern
#endif

#ifdef 	_WordCode_GLOBALS


u8 code Blankcode[4]= {0x37,0x37,0x37,0x37}; 
u8 code RUcode[4] = {0x27,0x37,0x37,0x2a};
u8 code RIcode[4] = {0x27,0x37,0x37,0x1e};

u8 code SPcode[4]   = {0x37,0x28,0x25,0x37}; //ÏÔÊ¾" SP "Ð±ÂÊµ÷Õû
u8 code SO_Tcode[4] = {0x28,0x24,0x0f,0x29}; //ÏÔÊ¾"SOFT"»º¹ØÊ±¼ä
u8 code SC_Tcode[4] = {0x28,0x0C,0x1a,0x29}; //ÏÔÊ¾"SC_T"»ºÆôÊ±¼ä
u8 code AL_Pcode[4] = {0x0a,0x21,0x1a,0x25}; //ÏÔÊ¾"AL_P"È±Ïà±¨¾¯ÔÊÐíÎ»
u8 code AL_Icode[4] = {0x0a,0x21,0x1a,0x1e}; //ÏÔÊ¾"AL_I"¹ýÁ÷±¨¾¯ÔÊÐí
u8 code IALMcode[4] = {0x1e,0x0a,0x21,0x22}; //ÏÔÊ¾"IALM"¹ýÁ÷±¨¾¯²ÎÊý
u8 code I_Hcode[4]  = {0x37,0x1e,0x1a,0x1d}; //ÏÔÊ¾"I_H"µçÁ÷ÏÞÖµ²ÎÊý
u8 code AL_Ucode[4] = {0x0a,0x21,0x1a,0x2a}; //ÏÔÊ¾"AL_U"¹ýÑ¹±¨¾¯ÔÊÐí
u8 code UALMcode[4] = {0x2a,0x0a,0x21,0x22}; //ÏÔÊ¾"UALM"¹ýÑ¹±¨¾¯²ÎÊý
u8 code U_Hcode[4]  = {0x37,0x2a,0x1a,0x1d}; //ÏÔÊ¾" U_H"µçÑ¹ÏÞÖÆ²ÎÊý
u8 code BPScode[4]  = {0x37,0x0b,0x25,0x28}; //ÏÔÊ¾" BPS"²¨ÌØÂÊ
u8 code PARIcode[4] = {0x25,0x0a,0x27,0x1e}; //ÏÔÊ¾"PARI"Ð£ÑéÎ»
u8 code UOUTcode[4] = {0x2a,0x24,0x2a,0x29}; //ÏÔÊ¾"UOUT"ÏÔÊ¾µçÑ¹
u8 code ELSEcode[4] = {0x0e,0x21,0x28,0x0e}; //ÏÔÊ¾"ELSE"ÆäËûÉèÖÃ
u8 code SBPHcode[4] = {0x28,0x0b,0x25,0x1d}; //ÏÔÊ¾"SBPH"ÉèÖÃµçÁ÷²»Æ½ºâ±¨¾¯²ÎÊýÉèÖÃ
u8 code CYCcode[4] = {0x37,0x0C,0x2e,0x0C}; //ÏÔÊ¾" CYC"ÉèÖÃÊ×Ò³Ñ­»·Ê±¼ä
u8 code LIGHTcode[4] = {0x21,0x1e,0x1C,0x1d}; //ÏÔÊ¾"Ligh"ÁÁ¶È


u8 code AOcode[4]   = {0x37,0x0A,0x24,0x37}; //ÏÔÊ¾" AO "
u8 code UHcode[4]   = {0x2A,0x35,0x31,0x31}; //ÏÔÊ¾"uh--"
u8 code UHNcode[4]  = {0x2A,0x35,0x1A,0x1A}; //ÏÔÊ¾"uh__"
u8 code UAHcode[4]  = {0x2A,0x0A,0x35,0x31}; //ÏÔÊ¾"uAh-"
u8 code UAHNcode[4] = {0x2A,0x0A,0x35,0x1A}; //ÏÔÊ¾"uAh_"
u8 code CODEcode[4] = {0x0c,0x24,0x0d,0x40}; //ÏÔÊ¾"Code"
u8 code SSETcode[4] = {0x37,0x28,0x0e,0x29}; //ÏÔÊ¾" SET"
u8 code DISPcode[4] = {0x37,0x28,0x25,0x37}; //ÏÔÊ¾" SP "
u8 code BLEDcode[4] = {0x28,0x0c,0x1a,0x29}; //ÏÔÊ¾"bLEd"
u8 code CLREcode[4] = {0x28,0x24,0x1a,0x29}; //ÏÔÊ¾"CLrE"
u8 code INPTcode[4] = {0x01,0x23,0x25,0x29}; //ÏÔÊ¾"InPT"
u8 code NETcode[4]  = {0x37,0x23,0x0e,0x29}; //ÏÔÊ¾" nET"
u8 code N33code[4]  = {0x37,0x23,0x13,0x03}; //ÏÔÊ¾" N3.3"
u8 code N34code[4]  = {0x37,0x23,0x13,0x04}; //ÏÔÊ¾" N3.4"
u8 code USCLcode[4] = {0x2a,0x28,0x34,0x21}; //ÏÔÊ¾"UScl"
u8 code ISCLcode[4] = {0x01,0x28,0x34,0x21}; //ÏÔÊ¾"IScl"
u8 code UTcode[4]   = {0x29,0x37,0x37,0x2a}; //ÏÔÊ¾"T  U"
u8 code ITcode[4]   = {0x29,0x37,0x37,0x01}; //ÏÔÊ¾"T  I"
u8 code CONNcode[4] = {0x0c,0x24,0x23,0x23}; //ÏÔÊ¾"Conn"Í¨Ñ¶
u8 code SNcode[4]   = {0x37,0x37,0x28,0x23}; //ÏÔÊ¾"  Sn"
u8 code BAUDcode[4] = {0x0b,0x0a,0x2a,0x0d}; //ÏÔÊ¾"bAUd"
u8 code DATAcode[4] = {0x0d,0x0a,0x29,0x0a}; //ÏÔÊ¾"dATA"
u8 code N81code[4]  = {0x37,0x23,0x18,0x01}; //ÏÔÊ¾" n8.1"
u8 code O81code[4]  = {0x37,0x24,0x18,0x01}; //ÏÔÊ¾" o8.1"
u8 code E81code[4]  = {0x37,0x0e,0x18,0x01}; //ÏÔÊ¾" E8.1"
u8 code PROTcode[4] = {0x25,0x27,0x24,0x29}; //ÏÔÊ¾"ProT"
u8 code WORDcode[4] = {0x2a,0x24,0x27,0x0d}; //ÏÔÊ¾"Uord"
u8 code BYTEcode[4] = {0x0b,0x2e,0x29,0x0e}; //ÏÔÊ¾"bYtE"
u8 code SAVEcode[4] = {0x05,0x0A,0x2A,0x40}; //ÏÔÊ¾"Save"
u8 code YEScode[4]  = {0x37,0x2E,0x0E,0x05}; //ÏÔÊ¾" Yes"
u8 code NOcode[4]   = {0x37,0x23,0x24,0x37}; //ÏÔÊ¾" No "
u8 code YQCode[12]  = {0x37,0x37,0x0A,0x0B,  //ÏÔÊ¾"  Ab"
                       0x08,0x00,0x04,0x0E,  //ÏÔÊ¾"804E"
                       0x2A,0x13,0x00,0x0c,  //ÏÔÊ¾"U3.0C"
                      };
u8 code ERRCode[12] = {0x31,0x31,0x31,0x0e,  //ÏÔÊ¾¡°---E¡±
                       0x27,0x27,0x24,0x27,  //ÏÔÊ¾¡°rror¡±
                       0x31,0x31,0x31,0x31,  //ÏÔÊ¾¡°----¡±
                      };
unsigned char code SMGmap[72] = {0xFC,0x60,0xDA,0xF2,	// ;0,1,2,3       ;00,01,02,03
                                 0x66,0xB6,0xBE,0xE0,	// ;4,5,6,7       ;04,05,06,07
                                 0xFE,0xF6,0xEE,0x3E,	// ;8,9,A,B       ;08,09,0A,0B
                                 0x9C,0x7A,0x9E,0x8E,	// ;C,d,E,F 	  ;0C,0D,0E,0F
                                 0xFD,0x61,0xDB,0xF3,	// ;0.,1.,2.,3.   ;10,11,12,13
                                 0x67,0xB7,0xBF,0xE1,	// ;4.,5.,6.,7.	  ;14,15,16,17
                                 0xFF,0xF7,0x10,0x11,	// ;8.,9.,_ ,_.   ;18,19,1A,1B
                                 0xbc,0x6e,0x0c,0x70,	// ;G,H,I,J       ;1C,1D,1E,1F
                                 0x0e,0x1c,0xec,0x2a,	// ;K,L,M,N       ;20,21,22,23
                                 0x3a,0xce,0xe6,0x0a,	// ;O,P,Q,R       ;24,25,26,27
                                 0xb6,0x8c,0x7c,0x38,	// ;S,T,U,V       ;28,29,2A,2B
                                 0x7c,0x64,0x76,0xda,	// ;W,X,Y,Z       ;2C,2D,2E,2F
                                 0x70,0x02,0x14,0x09,	// ;+,-,*,/       ;30,31,32,33
                                 0x1a,0x74,0x46,0x00,	// ;c,h,-1,NIL	  ;34,35,36,37
                                 0xF0,0xC0,0x94,0xD0,   // ;+.,-.,*.,R.   ;38,39,3A,3B
                                 0xD8,0xF6,0xC6,0x80,   // ;c.,H.,-1., .  ;3C,3D,3E,3F
                                 0xde,0x2b,0x7d,0x8d,	// ;e,n.U.,T.	  ;40,41,42,43
                                 0xdf,0x3b,0x0d,0xed    // ;e.,o.,I.,N.;  ;44,45,46,
                                };

#else
_WordCode_EXT u8 code Blankcode[];
_WordCode_EXT u8 code RUcode[];
_WordCode_EXT u8 code RIcode[];								
								
_WordCode_EXT u8 code SPcode[];
_WordCode_EXT u8 code SO_Tcode[];
_WordCode_EXT u8 code SC_Tcode[];
_WordCode_EXT u8 code AL_Pcode[];
_WordCode_EXT u8 code AL_Icode[];
_WordCode_EXT u8 code IALMcode[];
_WordCode_EXT u8 code I_Hcode[];
_WordCode_EXT u8 code AL_Ucode[];
_WordCode_EXT u8 code UALMcode[];
_WordCode_EXT u8 code U_Hcode[];
_WordCode_EXT u8 code BPScode[];
_WordCode_EXT u8 code PARIcode[];
_WordCode_EXT u8 code UOUTcode[];	
_WordCode_EXT u8 code ELSEcode[];	
_WordCode_EXT u8 code SBPHcode[];				
_WordCode_EXT u8 code CYCcode[];
_WordCode_EXT u8 code LIGHTcode[];							


_WordCode_EXT u8 code AOcode[];
_WordCode_EXT u8 code UHcode[];
_WordCode_EXT u8 code UHNcode[];
_WordCode_EXT u8 code UAHcode[];
_WordCode_EXT u8 code UAHNcode[];
_WordCode_EXT u8 code CODEcode[];
_WordCode_EXT u8 code SSETcode[];
_WordCode_EXT u8 code DISPcode[];
_WordCode_EXT u8 code BLEDcode[];
_WordCode_EXT u8 code CLREcode[];
_WordCode_EXT u8 code INPTcode[];
_WordCode_EXT u8 code NETcode[];
_WordCode_EXT u8 code N33code[];
_WordCode_EXT u8 code N34code[];
_WordCode_EXT u8 code USCLcode[];
_WordCode_EXT u8 code ISCLcode[];
_WordCode_EXT u8 code UTcode[];
_WordCode_EXT u8 code ITcode[];
_WordCode_EXT u8 code CONNcode[];
_WordCode_EXT u8 code SNcode[];
_WordCode_EXT u8 code BAUDcode[];
_WordCode_EXT u8 code DATAcode[];
_WordCode_EXT u8 code N81code[];
_WordCode_EXT u8 code O81code[];
_WordCode_EXT u8 code E81code[];
_WordCode_EXT u8 code PROTcode[];
_WordCode_EXT u8 code WORDcode[];
_WordCode_EXT u8 code BYTEcode[];
_WordCode_EXT u8 code SAVEcode[];
_WordCode_EXT u8 code YEScode[];
_WordCode_EXT u8 code NOcode[];
_WordCode_EXT u8 code YQCode[];
_WordCode_EXT u8 code ERRCode[];
_WordCode_EXT u8 code SMGmap[];
#endif
#endif
