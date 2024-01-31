#include <BleKeyboard.h>
#include "./Button.h"
#include <Arduino.h>

typedef enum {
    NUM_0 = '0', // ASCII value for character '0'
    NUM_1 = '1', // ASCII value for character '1'
    NUM_2 = '2', // ASCII value for character '2'
    NUM_3 = '3', // ASCII value for character '3'
    NUM_4 = '4', // ASCII value for character '4'
    NUM_5 = '5', // ASCII value for character '5'
    NUM_6 = '6', // ASCII value for character '6'
    NUM_7 = '7', // ASCII value for character '7'
    NUM_8 = '8', // ASCII value for character '8'
    NUM_9 = '9', // ASCII value for character '9'
    NUM_MAX // loop limit
} ButtonId;


extern uint8_t matrix[20];

extern BleKeyboard bleKeyboard;

void BLE_Config(void);
void onDataSent(uint8_t tmp);