#include "./OLED.h"

/*Author: Dinh Minh*/

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
volatile int isWelcomeMenuDis = 0;

text_struct calculateDesiredAlignment(int size, String tmp) {
    text_struct cleaner;
    int textWidth = 6 * size * tmp.length(); // 6 is the approximate width of a character in pixels
    int textHeight = 8 * size; // 8 is the approximate height of a character in pixels

    cleaner.x = (128 - textWidth) / 2;
    cleaner.y = (64 - textHeight) / 2;
    return cleaner;
}

void displayData(char key, int size) {
  static String tmp = "";
  tmp+= key;
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE); // Draw white text
  if(gameState == DISCONNECT) { // when the board plays as the calculator
    if(isWelcomeMenuDis == 0) {
      text_struct currentText;
      currentText = calculateDesiredAlignment(size, tmp);
      display.setTextSize(1);      // Normal 1:1 pixel scale
      display.setCursor(currentText.x, currentText.y);     // Start at top-left corner
      if(isEnterClick >= 2) { // if user see the authorization, the welcome screen will be off
        isWelcomeMenuDis = 1;
      }  
    } else {
      display.setTextSize(size);      // The calculator will be calculate on the top right of the screen
      display.setCursor(128, 0);     
    }
  } else {
    display.setTextSize(size);      // Normal 1:1 pixel scale
    display.setCursor(0, 0);     // Start at top-left corner 
  }
  display.print(tmp);
  display.display(); 
}

void displayWelcomeMsg(void) {
  String txt = "NCT BLE Calculator";
  for(int i = 0; i < txt.length(); i++) {
    displayData(txt.charAt(i), 1);
  }
}

void LCD_Init(void) {
    // Initialize with the I2C addr 0x3C (for the 128x64)
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  displayWelcomeMsg();
}

void displayDev(void) {
  if(isEnterClick) {
    String txt = "Developed by Minh Dinh";
    for(int i = 0; i < txt.length(); i++) {
      displayData(txt.charAt(i), 1);
    }
  }
}