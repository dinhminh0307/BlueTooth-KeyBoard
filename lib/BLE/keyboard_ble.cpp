#include "./keyboard_ble.h"

BleKeyboard bleKeyboard("Dinh Minh Keyboard");
ButtonId allButtons[] = {NUM_0, NUM_1, NUM_2, NUM_3, NUM_4, NUM_5, NUM_6, NUM_7, NUM_8, NUM_9};

volatile int i = 0;

void BLE_Config(void) {
    bleKeyboard.begin();
}

void onDataSent(uint8_t tmp) {
    int numButtons = sizeof(allButtons) / sizeof(allButtons[0]); // Calculate the number of elements in the array
    Serial.println(buttonInitCheck);
    if (bleKeyboard.isConnected() && buttonInitCheck != 0) {
        while(i < numButtons) {
            if(tmp == (char)allButtons[i]) {
                bleKeyboard.print((char)allButtons[i]);
                break;
            } else {
                i++;
            }
        }
      }
    i = 0;
    buttonInitCheck = 0;
}