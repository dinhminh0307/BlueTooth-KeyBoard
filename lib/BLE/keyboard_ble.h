#include <BleKeyboard.h>
#include "./OLED.h"
#include <Arduino.h>



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