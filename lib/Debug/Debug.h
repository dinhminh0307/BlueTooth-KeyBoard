#include <Wire.h>  
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Sleep.h>

/*SCL (Serial Clock) of OLED to GPIO 22 (default I2C SCL) of ESP32
SDA (Serial Data) of OLED to GPIO 21 (default I2C SDA) of ESP32*/


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

typedef struct text_struct {
    int x, y; // cursor
} text_struct;

text_struct calculateDesiredAlignment(int size, String tmp);
void displayData(const String &tmp);
void displayData(char tmp[]);
void displayData(const char tmp); // overload to print char
void displayData(const int tmp); // overload to print int
void LCD_Init(void);
void displayWelcomeMsg(void);
void clearScreen(void);
void RTC_Display(void);
void displayMenu(int currentSelection);
void drawBird(int pos, int size);
void drawObstacle(int pos, int width, int gap_height);
void gameSetup(void);
void displayScreen(void);
void gameOverScreen(void);
void displayScore(int score);