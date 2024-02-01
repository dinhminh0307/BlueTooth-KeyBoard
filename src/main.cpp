
#if 1
#include <keyboard_ble.h>
#include <OLED.h>

void setup() {
  Serial.begin(115200);
  button_config();
  BLE_Config();
  LCD_Init();
}

void loop() {
  uint8_t test = button_scan();
  onDataSent(test);
  delay(100);
}
#endif
