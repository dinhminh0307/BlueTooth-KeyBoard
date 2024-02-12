#include "./Debug.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

text_struct calculateDesiredAlignment(int size, String tmp) {
    text_struct cleaner;


    int textWidth = 6 * size * tmp.length(); // 6 is the approximate width of a character in pixels
    int textHeight = 8 * size; // 8 is the approxim7ate height of a charac23ter in pixels
    

    cleaner.x = (128 - textWidth) / 2;
    cleaner.y = (64 - textHeight) / 2;
    return cleaner;
}

void LCD_Init(void) {
    // Initialize with the I2C addr 0x3C (for the 128x64)
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
}

void displayData(String tmp) {
  text_struct currentText;
  currentText = calculateDesiredAlignment(1, tmp);
  display.clearDisplay();
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Set the text color to white
  display.setCursor(currentText.x, currentText.y);     // Start at top-left corner 
  display.print(tmp);
  display.display();
}