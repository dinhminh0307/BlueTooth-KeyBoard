#include "./OLED.h"

/*Author: Dinh Minh*/

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
volatile int isWelcomeMenuDis = 0;
volatile int function_ctr = 0;
String txt = "BLE Calculator";

void clearDisplay(void) {
  txt = "";
}

text_struct calculateDesiredAlignment(int size, String tmp) {
    text_struct cleaner;


    int textWidth = 6 * size * tmp.length(); // 6 is the approximate width of a character in pixels
    int textHeight = 8 * size; // 8 is the approxim7ate height of a charac23ter in pixels
    

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
      // reset flag
        isWelcomeMenuDis = 1;
        isEnterClick = 0;
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
  Serial.println("ok");
  displayWelcomeMsg();
  // while(button_enter.mode == 0); // error is here
  // Serial.println("Work2");
  // button_enter.mode = NONE;
  // displayDev();
  // while(button_enter.mode == 0);
  // button_enter.mode = NONE;
}

void displayDev(void) {
  Serial.println("Work");
  // if(isEnterClick < 2 && isEnterClick > 0) { // after welcome menu displayed
  //   while(function_ctr > 0);
    
  //   function_ctr++;
  // }
  display.clearDisplay();
    // String dev_txt = "Author: Minh Dinh";
    // for(int i = 0; i < dev_txt.length(); i++) { 
    //   displayData(dev_txt.charAt(i), 1);
    // }
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setCursor(0, 0);     // Start at top-left corner 
  display.print("Author: Minh Dinh");
  display.display(); 
}