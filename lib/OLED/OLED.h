#include <Wire.h>  
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "./Button.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

typedef struct text_struct {
    int x, y; // cursor
} text_struct;

extern volatile int isWelcomeMenuDis;

//-------------------------
//       Logic functions
//-------------------------
text_struct calculateDesiredAlignment(int size, String tmp);
//-------------------------
//       Display functions
//-------------------------
void LCD_Init(void);
void displayWelcomeMsg(void);
void displayData(char key, int size);
void displayDev(void);
void clearDisplay(void);