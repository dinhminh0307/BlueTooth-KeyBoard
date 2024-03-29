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
button_t button_switch;

button_t button_plus;
button_t button_minus;
button_t button_multiply;
button_t button_divide;

State allState[] = {SLEEP_MODE, BLUETOOTH_MODE, CALCULATOR_MODE, GAME_MODE,DEF_MODE, MAX_MODE};

volatile int buttonInitCheck = 0;
volatile int isEnterClick = 0;
volatile int gameState = allState[4];
volatile int isModeSwitch = 0;
volatile int currentSelection = 0; // when  button enter is pressed, this var is executed

ButtonId allButtons[] = {NUM_0, NUM_1, NUM_2, NUM_3, NUM_4, NUM_5, NUM_6, NUM_7, 
                        NUM_8, NUM_9, BTN_ENTER, BTN_PLUS, BTN_MINUS, BTN_MULTIPLY, BTN_DIVIDE, BTN_SWITCH, NUM_MAX};

// Array of pointers to your button_t instances
button_t* buttons[] = {
    &button_0, &button_1, &button_2, &button_3, &button_4,
    &button_5, &button_6, &button_7, &button_8, &button_9,
    &button_enter, &button_plus, &button_minus, &button_multiply, &button_divide, &button_switch
};

int numButtons = sizeof(allButtons) / sizeof(allButtons[0]);

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
  button_update(&button_plus);
  button_update(&button_minus);
  button_update(&button_multiply);
  button_update(&button_divide);
  button_update(&button_switch);
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
    button_add_default(&button_plus, BUTTON_PLUS_PIN);
    button_add_default(&button_minus, BUTTON_MINUS_PIN);
    button_add_default(&button_multiply, BUTTON_MULTIPLY_PIN);
    button_add_default(&button_divide, BUTTON_DIVIDE_PIN);
    button_add_default(&button_switch, BUTTON_SWITCH_PIN);
    button_init(&button_isr);
}

uint8_t button_scan(void) {
    for (int i = 0; i < sizeof(buttons) / sizeof(buttons[0]); ++i) {
        if (buttons[i]->mode) {  // Assuming mode is a valid member to check if the button is pressed
            buttons[i]->mode = NONE;  // Reset the button mode

            // Special handling for specific buttons, if needed
            if (allButtons[i] == BTN_ENTER) {
                isEnterClick++;
                switch(currentSelection) {
                    case 0:
                        gameState = allState[0];
                        break;
                    case 1:
                        gameState = allState[1];
                        break;
                    case 2:
                        gameState = allState[2];
                        break;
                    case 3:
                        gameState = allState[3];
                        break;
                }  
            }
            if (allButtons[i] == BTN_SWITCH) {
                if(gameState == allState[4]) { // By default state, the system asks user to select mode.
                                           // If the enter button is pressed, the current selection will be selected
                                           // if the system ask find are in the other modes, it will skip the first
                                           // condition.
                    currentSelection++; // Cycle through 0, 1, 2, 3
                    if(currentSelection >= 4) {
                        currentSelection = 0;
                    }
                } else {
                    gameState == allState[4];
                    currentSelection = 0;
                }
                isModeSwitch = 1;
            }
            buttonInitCheck++;
            delay(200);  // mute all bounce
            return allButtons[i];
        }
    }
    return 0x00;  // Return 0x00 if no button is pressed
}