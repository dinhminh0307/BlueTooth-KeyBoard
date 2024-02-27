#include "./Sleep.h"

void shuwDownMode(void) {
    esp_sleep_enable_timer_wakeup(UINT64_MAX); // Set the wakeup time far in the future
    esp_deep_sleep_start(); // Enter deep sleep mode
}

void wakeUpMode(void) {
    esp_sleep_enable_ext0_wakeup(GPIO_NUM_27, 1); // 1 = High, 0 = Low
}