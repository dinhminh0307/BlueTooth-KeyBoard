#include "./keyboard_ble.h"

BleKeyboard bleKeyboard("Dinh Minh Keyboard");


volatile int i = 0;

void BLE_Config(void) {
    bleKeyboard.begin();
}

void onDataSent(uint8_t tmp) {
    if (bleKeyboard.isConnected() && buttonInitCheck != 0) {
        while(i < numButtons) {
             if(tmp == (char)allButtons[i]) {
                // Special handling for the "Enter" button
                if (allButtons[i] == BTN_ENTER) {
                    bleKeyboard.write(KEY_RETURN); // Send "Enter" keypress
                } else {
                    Serial.println(" Please work");
                    bleKeyboard.print((char)allButtons[i]); // Print the character corresponding to the button pressed
                }
                break;
            } else {
                i++;
            }
        }
        i = 0;
        buttonInitCheck = 0;
      }
}