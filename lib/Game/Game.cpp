#include "./Game.h"

// Game variables
int birdY = SCREEN_HEIGHT - 50;
int birdRadius = 3;  // Adjust based on your bird size
int gameRunning = 1;
int score = 0;

// Obstacle variables
int obstacleX = SCREEN_WIDTH;
int obstacleWidth = 20;  // Width of the obstacle
int gapHeight = 50;  // Height of the gap between obstacles
int obstacleSpeed = 5;  // Speed at which obstacle moves

void moveObstacle(void) {
    obstacleX -= obstacleSpeed;
    if (obstacleX + obstacleWidth < 0) {
      obstacleX = SCREEN_WIDTH;  // Reset obstacle position
      // Randomize gap height for the next obstacle
      gapHeight = random(30, 60);
      score++;
    }
}

void checkCollision(void) {
    // Collision detection
    if (10 + birdRadius > obstacleX && 10 - birdRadius < obstacleX + obstacleWidth) {  // Check horizontal collision
      if (birdY - birdRadius < SCREEN_HEIGHT / 2 - gapHeight / 2 || birdY + birdRadius > SCREEN_HEIGHT / 2 + gapHeight / 2) {  // Check vertical collision
        gameRunning = 0;  // End game
      }
    }

    // Check for collision with top and bottom of the screen
    if (birdY + birdRadius >= SCREEN_HEIGHT || birdY - birdRadius <= 0) {
      gameRunning = 0;  // End game
    }
}

void onGameRunning(uint8_t enter_button) {
    if (gameRunning) {
    gameSetup();

    displayScore(score);
  // jump
    if (enter_button == 1) {  // Button pressed
      birdY -= 20;  // Adjust jump height as needed
    }

    // Simple gravity 
    birdY += 10;


    // Draw bird
    drawBird(birdY, birdRadius);

    // Move obstacle
    moveObstacle();

    // Draw obstacle
    drawObstacle(obstacleX,obstacleWidth, gapHeight);
    checkCollision();

    displayScreen();
    delay(100);  // Adjust game speed as needed
  } else {
    // Game over logic
    gameOverScreen();
    delay(2000);  // Display game over message for 2 seconds
    // Reset game variables for a new game
    birdY = SCREEN_HEIGHT - 50;
    obstacleX = SCREEN_WIDTH;
    gameRunning = 1;
    score = 0;
  }
  delay(50);
}