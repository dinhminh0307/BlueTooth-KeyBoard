
#if 1
#include <Game.h>
/*For error: Failed to connect to ESP32: Invalid head of packet (0x5B): Possible serial noise or corruption
hold the boot when it is uploading then the chill will be in bootloader mode*/

int buttonPin = 26;
void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLDOWN);
  //button_config();
  //BLE_Config();
  LCD_Init();
  delay(100);
  clearScreen(); // Clear
}

void loop() {
  uint8_t test = 0;
  int dataRead = digitalRead(buttonPin);
  if(dataRead == HIGH) {
    test = 1;
    delay(10);
  }
  onGameRunning(test);
  //onDataSent(test);
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

#if 0
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define BUTTON_PIN 27  // Change according to your setup

// Game variables
int birdY = SCREEN_HEIGHT / 2;
int birdRadius = 3;  // Adjust based on your bird size
bool gameRunning = true;

// Obstacle variables
int obstacleX = SCREEN_WIDTH;
int obstacleWidth = 20;  // Width of the obstacle
int gapHeight = 20;  // Height of the gap between obstacles
int obstacleSpeed = 2;  // Speed at which obstacle moves

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLDOWN);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize with the I2C addr 0x3C
  display.clearDisplay();
  display.display();
}

void loop() {
  if (gameRunning) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    // Simple gravity 
    birdY -= 10;

    // Jump
    if (digitalRead(BUTTON_PIN) == LOW) {  // Button pressed
      birdY += 20;  // Adjust jump height as needed
    }

    // Draw bird
    display.fillCircle(10, birdY, birdRadius, SSD1306_WHITE);

    // Move obstacle
    obstacleX -= obstacleSpeed;
    if (obstacleX + obstacleWidth < 0) {
      obstacleX = SCREEN_WIDTH;  // Reset obstacle position
      // Randomize gap height for the next obstacle
      gapHeight = random(10, SCREEN_HEIGHT / 2);
    }

    // Draw obstacle
    display.fillRect(obstacleX, 0, obstacleWidth, SCREEN_HEIGHT / 2 - gapHeight / 2, SSD1306_WHITE);
    display.fillRect(obstacleX, SCREEN_HEIGHT / 2 + gapHeight / 2, obstacleWidth, SCREEN_HEIGHT / 2 - gapHeight / 2, SSD1306_WHITE);

    // Collision detection
    if (10 + birdRadius > obstacleX && 10 - birdRadius < obstacleX + obstacleWidth) {  // Check horizontal collision
      if (birdY - birdRadius < SCREEN_HEIGHT / 2 - gapHeight / 2 || birdY + birdRadius > SCREEN_HEIGHT / 2 + gapHeight / 2) {  // Check vertical collision
        gameRunning = false;  // End game
      }
    }

    // Check for collision with top and bottom of the screen
    if (birdY + birdRadius >= SCREEN_HEIGHT || birdY - birdRadius <= 0) {
      gameRunning = false;  // End game
    }

    display.display();
    delay(50);  // Adjust game speed as needed
  } else {
    // Game over logic
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2);
    display.print("Game Over");
    display.display();
    delay(2000);  // Display game over message for 2 seconds
    // Reset game variables for a new game
    birdY = SCREEN_HEIGHT / 2;
    obstacleX = SCREEN_WIDTH;
    gameRunning = true;
  }
  delay(500);
}

#endif
