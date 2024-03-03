#include "./CalculatorRTC.h"

void RTC_config(void) {
    // Set up for NTP
  configTime(0, 0, "pool.ntp.org", "time.nist.gov");

  // Wait for time to be set
  time_t now = time(nullptr);
  while (now < 24 * 3600) {
    Serial.println("Waiting for NTP time sync");
    delay(100);
    now = time(nullptr);
  }
}

String RTC_GetTime(void) {
    struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    return " ";
  }

  delay(1000); // Wait a second before updating the time
  return asctime(&timeinfo);
}