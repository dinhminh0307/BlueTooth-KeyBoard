#include "./OLED.h"

/*Author: Dinh Minh*/

volatile int isWelcomeMenuDis = 0;
volatile int function_ctr = 0;
String txt = "BLE Calculator";


void displayWelcomeMsg(void) {
  displayData("BLE calculator");
}

void OLED_Init(void) {
  displayWelcomeMsg();
}



