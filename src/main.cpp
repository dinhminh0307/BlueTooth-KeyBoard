
#if 1
#include <Calculator.h>
/*For error: Failed to connect to ESP32: Invalid head of packet (0x5B): Possible serial noise or corruption
hold the boot when it is uploading*/
void setup() {
  Serial.begin(115200);
  button_config();
  BLE_Config();
  RTC_config();
  LCD_Init();
  delay(100);
  clearScreen();
}

void loop() {
  uint8_t test = button_scan();
  if(gameState == CONNECT) {
    if(isModeSwitch) {
      clearScreen();
      isModeSwitch = 0;
    }
    displayData(gameState);
    onDataSent(test);
  } else {
    if(isModeSwitch) {
      clearScreen();
      isModeSwitch = 0;
      calculatorCounter = 1;
    }
    // calculating functio7n
    //printNumber(test);
    RTC_Display();
    //displayData(gameState);
  }
  delay(500);
}
#endif
