#include "./keyboard_ble.h"

volatile extern int calculatorCounter;

int keyboardCompute(int num1, uint8_t op , int num2);
void printResult(void);
void printNumber(uint8_t tmp);