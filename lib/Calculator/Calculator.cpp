#include "./Calculator.h"


String printedChar = ""; // char to be printed
volatile int calculatorCounter = 0;


float keyboardCompute(ButtonId num1, ButtonId op, ButtonId num2) {
    float result = 0.0;
    float number1 = num1 - '0'; // Convert from ASCII to integer
    float number2 = num2 - '0'; // Convert from ASCII to integer

    switch (op) {
        case BTN_PLUS:
            result = number1 + number2;
            break;
        case BTN_MINUS:
            result = number1 - number2;
            break;
        case BTN_MULTIPLY:
            result = number1 * number2;
            break;
        case BTN_DIVIDE:
            if (number2 != 0) { // Check for divide by zero
                result = number1 / number2;
            } else {
                printf("Error: Division by zero.\n");
                return 0; // Handle division by zero error
            }
            break;
        default:
            printf("Invalid operation.\n");
            return 0; // Handle invalid operator error
  }

    return result;
}

void printNumber(uint8_t tmp) {
    if(tmp != 0x00 && tmp != BUTTON_ENTER) {
        if(calculatorCounter == 0) {
            printedChar += (char)tmp;
            clearScreen();
            displayData(printedChar);
        }
        else {
            clearScreen();
            calculatorCounter = 0;
        }
    }
}