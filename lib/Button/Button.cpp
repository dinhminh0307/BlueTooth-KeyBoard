#include "./Button.h"

button_t button_2;
button_t button_3;
button_t button_4;
button_t button_5;
button_t button_6;
button_t button_7;
button_t button_8;
button_t button_9;
button_t button_1;
button_t button_0;

button_t button_enter;

volatile int buttonInitCheck = 0;
volatile int gameState = DISCONNECT;
volatile int isEnterClick = 0;

void IRAM_ATTR button_isr()
{
  button_update(&button_0);
  button_update(&button_1);
  button_update(&button_2);
  button_update(&button_3);
  button_update(&button_4);
  button_update(&button_5);
  button_update(&button_6);
  button_update(&button_7);
  button_update(&button_8);
  button_update(&button_9);
  button_update(&button_enter);
}

void button_config(void) {
    button_add_default(&button_0, BUTTON_0_PIN);
    button_add_default(&button_1, BUTTON_1_PIN);
    button_add_default(&button_1, BUTTON_1_PIN);
    button_add_default(&button_2, BUTTON_2_PIN);
    button_add_default(&button_3, BUTTON_3_PIN);
    button_add_default(&button_4, BUTTON_4_PIN);
    button_add_default(&button_5, BUTTON_5_PIN);
    button_add_default(&button_6, BUTTON_6_PIN);
    button_add_default(&button_7, BUTTON_7_PIN);
    button_add_default(&button_8, BUTTON_8_PIN);
    button_add_default(&button_9, BUTTON_9_PIN);
    button_add_default(&button_enter, BUTTON_ENTER_PIN);

    button_init(&button_isr);
}



uint8_t button_scan(void) {
    if(button_0.mode) {
        buttonInitCheck++;
        delay(100);
        button_0.mode = NONE;
        return BUTTON_0;
    } else if(button_1.mode) {
        buttonInitCheck++;
        delay(100);
        button_1.mode = NONE;
        return BUTTON_1;
    } else if(button_2.mode) {
        buttonInitCheck++;
        delay(100);
        button_2.mode = NONE;
        return BUTTON_2;
    } else if(button_3.mode) {
        buttonInitCheck++;
        delay(100);
        button_3.mode = NONE;
        return BUTTON_3;
    } else if(button_4.mode) {
        buttonInitCheck++;
        delay(100);
        button_4.mode = NONE;
        return BUTTON_4;
    } else if(button_5.mode) {
        buttonInitCheck++;
        delay(100);
        button_5.mode = NONE;
        return BUTTON_5;
    } else if(button_6.mode) {
        buttonInitCheck++;
        delay(100);
        button_6.mode = NONE;
        return BUTTON_6;
    } else if(button_7.mode) {
        buttonInitCheck++;
        delay(100);
        button_7.mode = NONE;
        return BUTTON_7;
    } else if(button_8.mode) {
        buttonInitCheck++;
        delay(100);
        button_8.mode = NONE;
        return BUTTON_8;
    } else if(button_9.mode) {
        buttonInitCheck++;
        delay(100);
        button_9.mode = NONE;
        return BUTTON_9;
    } else if(button_enter.mode) {
        Serial.print("is enter clicked: ");
        Serial.print(isEnterClick);
        buttonInitCheck++;
        isEnterClick++;
        delay(100);
        button_enter.mode = NONE;
        return BUTTON_ENTER;
    }
    return 0x00;
}