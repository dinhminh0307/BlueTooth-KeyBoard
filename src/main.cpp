
#if 1
#include <Calculator.h>
/*For error: Failed to connect to ESP32: Invalid head of packet (0x5B): Possible serial noise or corruption
hold the boot when it is uploading then the chill will be in bootloader mode*/
void setup() {
  Serial.begin(115200);
  button_config();
  BLE_Config();
  LCD_Init();
  delay(100);
  clearScreen(); // Clear
}

void loop() {
  uint8_t test = button_scan();
  onDataSent(test);
  // if(gameState == allState[4]) {
  //   displayMenu(currentSelection);
  //   //displayData(currentSelection);
  // } else if(gameState == allState[0]){
  //   clearScreen();
  //   displayData("This is sleep mode");
  // } else if(gameState == allState[1]){
  //   clearScreen();
  //   displayData("This is bluetooth mode");
  //   onDataSent(test);
  // } else if(gameState == allState[2]){
  //   clearScreen();
  //   displayData("This is calculator mode");
  // } else if(gameState == allState[3]){
  //   clearScreen();
  //   displayData("This is game mode");
  // }

  //displayMenu(1);





  // if(gameState == CONNECT) {
  //   if(isModeSwitch) {
  //     clearScreen();
  //     isModeSwitch = 0;
  //   }
  //   displayData(gameState);
  //   onDataSent(test);
  // } else {
  //   if(isModeSwitch) {
  //     clearScreen();
  //     isModeSwitch = 0;
  //     calculatorCounter = 1;
  //   }
  //   // calculating functio7n
  //   //printNumber(test);
  //   RTC_Display();
  //   //displayData(gameState);
  // }
  // delay(500);
}

#endif
