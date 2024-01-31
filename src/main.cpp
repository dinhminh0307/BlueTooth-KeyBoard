
#if 1
#include <keyboard_ble.h>

void setup() {
  Serial.begin(115200);
  button_config();
  BLE_Config();
}

void loop() {
  uint8_t test = button_scan();
  onDataSent(test);
}
#endif
