#ifndef _KeyBoard_H
#define _KeyBoard_H

#ifdef 	_KeyBoard_GLOBALS
#define _KeyBoard_EXT
#else
#define _KeyBoard_EXT	extern
#endif


_KeyBoard_EXT	void key_init(void);
_KeyBoard_EXT	void key_check(void);
_KeyBoard_EXT 	void KEY_Back_Deal(void);
_KeyBoard_EXT 	void KEY_Set_Deal(void);
_KeyBoard_EXT 	void KEY_Up_Deal(void);
_KeyBoard_EXT 	void KEY_Move_Deal(void);

#endif



