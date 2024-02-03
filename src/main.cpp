
#if 1
#include <keyboard_ble.h>

void setup() {
  Serial.begin(115200);
  button_config();
  BLE_Config();
  LCD_Init();
}

void loop() {
  displayDev();
  uint8_t test = button_scan();
  // Serial.print("Button mode: ");
  // Serial.println(button_enter.mode);
  onDataSent(test);
  delay(100);
}
#endif
