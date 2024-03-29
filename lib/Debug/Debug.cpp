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

void displayData(const String &tmp) {
  text_struct currentText;
  currentText = calculateDesiredAlignment(1, tmp);
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Set the text color to white
  display.setCursor(currentText.x, currentText.y);     // Start at top-left corner 
  display.print(tmp);
  display.display();
}

void displayWelcomeMsg(void) {
  displayData("NCT Bluetooth Calculator");
}

void LCD_Init(void) {
    // Initialize with the I2C addr 0x3C (for the 128x64)
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  clearScreen();
  displayWelcomeMsg();
}

void clearScreen(void) {
  display.clearDisplay();
}

void displayData(char tmp[]) {
  int16_t x1, y1;
  uint16_t w, h;
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Set the text color to white
  // Calculate the width and height of the text to center it
  display.getTextBounds(tmp, 0, 0, &x1, &y1, &w, &h);

  // Calculate the x and y position to center the text
  int16_t x = (SCREEN_WIDTH - w) / 2;
  int16_t y = (SCREEN_HEIGHT - h) / 2;

  display.setCursor(x, y); // Set the cursor to the calculated position
  display.print(tmp);
  display.display();
}

void displayData(const char tmp) {
  text_struct currentText;
  currentText = calculateDesiredAlignment(1, String(tmp));
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Set the text color to white
  display.setCursor(currentText.x, currentText.y);     // Start at top-left corner 
  display.print(tmp);
  display.display();
}

void displayData(const int tmp) {
  text_struct currentText;
  currentText = calculateDesiredAlignment(1, String(tmp));
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Set the text color to white
  display.setCursor(currentText.x, currentText.y);     // Start at top-left corner 
  display.print(tmp);
  display.display();
}

// void RTC_Display(void) {
//   clearScreen();
//   displayData(RTC_GetTime());
// }

void displayMenu(int current) {
  clearScreen();
  display.setCursor(0, 0);

  String menuItems[] = {"Sleep","BlueTooth", "Calculator", "Game"};
  for (int i = 0; i < 4; i++) {
    if (i == current) {  // Highlight the current menu option
      display.print("> ");
    } else {
      display.print("  ");
    }
    display.println(menuItems[i]);
  }

  display.display();
}

void drawBird(int pos, int size) {
  // Draw bird
  display.fillCircle(10, pos, size, SSD1306_WHITE);
}

void drawObstacle(int pos, int width, int gap_height) {
  display.fillRect(pos, 0, width, SCREEN_HEIGHT / 2 - gap_height / 2, SSD1306_WHITE);
  display.fillRect(pos, SCREEN_HEIGHT / 2 + gap_height / 2, width, SCREEN_HEIGHT / 2 - gap_height / 2, SSD1306_WHITE);
}

void gameSetup(void) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

void displayScreen(void) {
  display.display();
}

void gameOverScreen(void) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2);
  display.print("Game Over");
  display.display();
}

void displayScore(int score) {
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Set the text color to white
  display.setCursor(0, 0);     // Start at top-left corner 
  display.print(score);
  display.display();
}
