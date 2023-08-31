/*
 * Keypad.h
 *
 * Created: 19-Aug-23 7:53:48 PM

 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "Keypad_Cfg.h"
typedef enum{
	PRESSED,
	NOT_PRESSED
	}KEYPAD_ERROR_T;
	
void keyPad_Init (void);
KEYPAD_ERROR_T  KeyPad_GetValue(void);

#endif /* KEYPAD_H_ */