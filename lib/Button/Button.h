#include <esp32_button.h>
#include "./Debug.h"

//-------------------------
//       Number button
//-------------------------
#define BUTTON_0_PIN 23
#define BUTTON_1_PIN 33
#define BUTTON_2_PIN 14  // GPIO14
#define BUTTON_3_PIN 15  // GPIO15
#define BUTTON_4_PIN 16  // GPIO16
#define BUTTON_5_PIN 17  // GPIO17
#define BUTTON_6_PIN 18  // GPIO18
#define BUTTON_7_PIN 19  // GPIO19
#define BUTTON_8_PIN 24  // GPIO24 
#define BUTTON_9_PIN 32 // GPIO32

#define BUTTON_0 0x30
#define BUTTON_1 0x31
#define BUTTON_2 0x32
#define BUTTON_3 0x33
#define BUTTON_4 0x34
#define BUTTON_5 0x35
#define BUTTON_6 0x36
#define BUTTON_7 0x37
#define BUTTON_8 0x38
#define BUTTON_9 0x39

//-------------------------
//       Switch Button
//-------------------------2222
#define BUTTON_SWITCH_PIN 27

#define BUTTON_SWITCH 0x01

//-------------------------9

//       Enter Button
//-------------------------
#define BUTTON_ENTER_PIN 26
#define BUTTON_ENTER 0x0A

//-------------------------
//       + - * /
//-------------------------
#define BUTTON_PLUS_PIN 12 /////////// +
#define BUTTON_PLUS 0x2B    //////////

#define BUTTON_MINUS_PIN 35 ////////// -
#define BUTTON_MINUS 0x2D //////////

#define BUTTON_MULTIPLY_PIN 4 ////////// *
#define BUTTON_MULTIPLY 0x2A    ////////////

#define BUTTON_DIVIDE_PIN 2 ////////// divide
#define BUTTON_DIVIDE 0x2F    ////////////

//-------------------------
//       State +++9
//-------------------------
#define CONNECT 0
#define DISCONNECT 1


//-------------------------
//       Number declaration
//-------------------------
extern button_t button_0;
extern button_t button_1;
extern button_t button_2;
extern button_t button_3;
extern button_t button_4;
extern button_t button_5;
extern button_t button_6;
extern button_t button_7;
extern button_t button_8;
extern button_t button_9;

//-------------------------
//       Enter declaration
//-------------------------
extern button_t button_enter;

//-------------------------
//       + - * / declaration
//-------------------------
extern button_t button_plus;
extern button_t button_minus;
extern button_t button_multiply;
extern button_t button_divide;

//-------------------------
//       + - * / declaration
//-------------------------
extern button_t button_switch;
//-------------------------
//       Flag declaration
//-------------------------
extern volatile int buttonInitCheck;
extern volatile int isEnterClick;
extern volatile int gameState;
extern volatile int isModeSwitch;


typedef enum {
    NUM_0 = '0', // ASCII value for character '0'
    NUM_1 = '1', // ASCII value for character '1'
    NUM_2 = '2', // ASCII value for character '2'
    NUM_3 = '3', // ASCII value for character '3'
    NUM_4 = '4', // ASCII value for character '4'
    NUM_5 = '5', // ASCII value for character '5'
    NUM_6 = '6', // ASCII value for character '6'
    NUM_7 = '7', // ASCII value for character '7'222
    NUM_8 = '8', // ASCII value for character '8'22
    NUM_9 = '9', // ASCII value for character '9'
    BTN_ENTER = 0x0A,
    BTN_PLUS = 0x2B,
    BTN_MINUS = 0x2D,
    BTN_MULTIPLY = 0x2A,
    BTN_DIVIDE = 0x2F,
    BTN_SWITCH = 0x01,
    NUM_MAX // loop limit
} ButtonId;

extern ButtonId allButtons[];

// extern ButtonId allButtons[];
extern int numButtons;


//-------------------------
//       Init functions
//-------------------------
void button_config(void);
//-------------------------
//       Logic functions
//-------------------------
uint8_t button_scan(void);