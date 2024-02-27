#include <BleKeyboard.h>
#include "./Button.h"


extern uint8_t matrix[20];

extern BleKeyboard bleKeyboard;


//-------------------------
//      Init functions
//-------------------------
void BLE_Config(void);
//-------------------------
//       Logic functions
//-------------------------
void onDataSent(uint8_t tmp);