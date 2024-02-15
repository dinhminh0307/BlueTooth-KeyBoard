#include "./keyboard_ble.h"

volatile extern int calculatorCounter;

float keyboardCompute(ButtonId num1, ButtonId op, ButtonId num2);
void printResult(void);
void printNumber(uint8_t tmp);