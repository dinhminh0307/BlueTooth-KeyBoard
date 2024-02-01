#include "./OLED.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void displayKeyState(char key) {
  static char tmp = ' ';
  tmp+= key;
  display.clearDisplay();
  display.setTextSize(2);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0,0);     // Start at top-left corner
  display.print(F(tmp));
  display.display(); 
}

void LCD_Init(void) {
    // Initialize with the I2C addr 0x3C (for the 128x64)
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  String txt = "ok";
  for(int i = 0; i < txt.length(); i++) {
    displayKeyState(txt.charAt(i));
  }
}

