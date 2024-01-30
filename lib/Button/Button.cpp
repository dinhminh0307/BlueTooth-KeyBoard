#include "./Button.h"

button_t button_1;
void IRAM_ATTR button_isr()
{
  button_update(&button_1);
}

void button_config(void) {
    button_add_default(&button_1, BUTTON_1_PIN);

    button_init(&button_isr);
}