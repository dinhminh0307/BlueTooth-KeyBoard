
#if 1
#include <keyboard_ble.h>
/*For error: Failed to connect to ESP32: Invalid head of packet (0x5B): Possible serial noise or corruption
hold the boot when it is uploading*/
void setup() {
  Serial.begin(115200);
  button_config();
  BLE_Config();
  LCD_Init();
}

void loop() {

  uint8_t test = button_scan();

  if(gameState = CONNECT) {
    onDataSent(test);
  } else {
    // calculating function
  }
  delay(500);
}
#endif

#if 0
#include <Arduino.h>
void setup() {
  Serial.begin(115200);
  Serial.print("OK");
}

void loop() {

}
#endif