#include "./Calculator.h"

char opt = 0;
String printedChar = ""; // char to be printed
String previousNumber = ""; // number 1 string then be converted to int
String currentNumber = ""; // number 2 string then be converted to int
volatile int newNumber = 1;

volatile int calculatorCounter = 0;
int result = 0;
volatile int index_ctr = 0; // if there were more than 1 digit in the calculation, this flag will mark it

int keyboardCompute(int num1, uint8_t op , int num2) {
    result = 0;
    int number1 = num1 - '0'; // Convert from ASCII to integer
    int number2 = num2 - '0'; // Convert from ASCII to integer

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
     if(tmp != 0x00) {
        if(calculatorCounter == 0 && tmp >= '0' && tmp <= '9' && tmp != BUTTON_ENTER) {
            if(newNumber) {
                currentNumber = (char)tmp;
                newNumber = 0;
            } else {
                currentNumber += (char)tmp;
            }

            clearScreen();
            displayData(currentNumber);
        }
        if(calculatorCounter == 0 && tmp >= '*' && tmp <= '/' && tmp != BUTTON_ENTER) {
            previousNumber = currentNumber;
            clearScreen();
            displayData(previousNumber + (char)tmp);
            currentNumber = "";
            opt = (char)tmp;
            newNumber = 1;
        }
        if( calculatorCounter == 0 && tmp != BUTTON_ENTER) {
            keyboardCompute(previousNumber.toInt(), opt, currentNumber.toInt());
            clearScreen();
            displayData(result);
            delay(500);
        }
        else {
            clearScreen();
            calculatorCounter = 0;
        }
    }
}