#include "./keyboard_ble.h"

BleKeyboard bleKeyboard("Dinh Minh Keyboard");
ButtonId allButtons[] = {NUM_0, NUM_1, NUM_2, NUM_3, NUM_4, NUM_5, NUM_6, NUM_7, 
                        NUM_8, NUM_9, BTN_ENTER, BTN_PLUS, BTN_MINUS, BTN_MULTIPLY, BTN_DIVIDE, NUM_MAX};

volatile int i = 0;

void BLE_Config(void) {
    bleKeyboard.begin();
}

void onDataSent(uint8_t tmp) {
    int numButtons = sizeof(allButtons) / sizeof(allButtons[0]); // Calculate the number of elements in the array
    
    // Serial.print(" Button2 mode: ");
    // Serial.print(button_2.mode);
    // Serial.print(" Button9 mode: ");
    // Serial.println(button_9.mode);
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
      }
    i = 0;
    buttonInitCheck = 0;
}