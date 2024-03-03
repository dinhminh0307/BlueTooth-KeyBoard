
#if 0
#include <Calculator.h>
/*For error: Failed to connect to ESP32: Invalid head of packet (0x5B): Possible serial noise or corruption
hold the boot when it is uploading*/
void setup() {
  Serial.begin(115200);
  button_config();
  BLE_Config();
  RTC_config();
  LCD_Init();
  delay(100);
  clearScreen();
}

void loop() {
  uint8_t test = button_scan();
  if(gameState == CONNECT) {
    if(isModeSwitch) {
      clearScreen();
      isModeSwitch = 0;
    }
    displayData(gameState);
    onDataSent(test);
  } else {
    if(isModeSwitch) {
      clearScreen();
      isModeSwitch = 0;
      calculatorCounter = 1;
    }
    // calculating functio7n
    //printNumber(test);
    //RTC_Display();
    //displayData(gameState);
  }
  delay(500);
}
#endif

#if 0
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SCL, SDA pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // Initialize OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Check your display's I2C address
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0,0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  // Display basic Nokia-like interface
  display.print(F("NOKIA"));
  display.drawLine(0, 10, SCREEN_WIDTH, 10, SSD1306_WHITE);

  // Simulate the Nokia menu
  display.setCursor(0, 15);
  display.print(F("Menu"));
  display.setCursor(0, 25);
  display.print(F("Contacts"));
  display.setCursor(0, 35);
  display.print(F("Messages"));
  display.setCursor(0, 45);
  display.print(F("Settings"));

  display.display(); // Actually display all of the above
}

void loop() {
   // Nothing here. Everything is done in setup for this simple demo.
}

#endif
