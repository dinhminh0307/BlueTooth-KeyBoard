#include "./keyboard_ble.h"

BleKeyboard bleKeyboard("Dinh Minh Keyboard");

void BLE_Config(void) {
    bleKeyboard.begin();
}

void onDataSent(void) {
  static unsigned long lastDebounceTime = 0; // Stores the last time the button was toggled
  unsigned long debounceDelay = 100; // the debounce time; increase if the output flickers

  // Check if the button is pressed (assuming button_1.mode is set elsewhere when the button is pressed)
  if (button_1.mode) {
    // Check if enough time has passed since the last debounce time
    if ((millis() - lastDebounceTime) > debounceDelay) {
      // Enough time has passed since the last press
      if (bleKeyboard.isConnected()) {
        bleKeyboard.print("e");
      }

      lastDebounceTime = millis(); // Reset the debouncing timer
    }

    button_1.mode = NONE; // Reset the button mode
  }
}