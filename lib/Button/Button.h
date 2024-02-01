#include <esp32_button.h>

#define BUTTON_0_PIN 23
#define BUTTON_1_PIN 33
#define BUTTON_2_PIN 14  // GPIO14
#define BUTTON_3_PIN 15  // GPIO15
#define BUTTON_4_PIN 16  // GPIO16
#define BUTTON_5_PIN 17  // GPIO17
#define BUTTON_6_PIN 18  // GPIO18
#define BUTTON_7_PIN 19  // GPIO19
#define BUTTON_8_PIN 24  // GPIO24 (Skipping GPIO20 as it's not available on most ESP32 boards)
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
extern volatile int buttonInitCheck;

void button_config(void);
uint8_t button_scan(void);