#if 0
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <Arduino.h>

#define SERVICE_UUID        "e40dd444-d807-4c05-b7ca-7e8bdbdc6231"
#define CHARACTERISTIC_UUID "fd95605e-3243-4c62-817c-5c324699b5f6"

int buttonPin = 0; // Use the correct pin number
BLEServer *pServer = NULL;
BLECharacteristic *pCharacteristic = NULL;
bool deviceConnected = false;

class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
    };

    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
    }
};

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);
  BLEDevice::init("ESP32 Button Peripheral");
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());
  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ |
                      BLECharacteristic::PROPERTY_WRITE
                    );
  pCharacteristic->setValue("Button State: OFF");
  pService->start();
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("Waiting for a client connection to notify...");
}

void loop() {
  if (deviceConnected) {
    if (digitalRead(buttonPin) == LOW) { // Assuming the button is active low
      pCharacteristic->setValue("Button State: ON");
      pCharacteristic->notify();
      delay(100); // Simple debounce
    }
    else {
      pCharacteristic->setValue("Button State: OFF");
      pCharacteristic->notify();
    }
  }
  delay(50); // Delay to prevent excessive CPU usage
}
#endif

#if 1
#include <Arduino.h>
#include <Arduino.h>
#include <esp32_button.h>

#define BUTTON_1_PIN 33
#define BUTTON_2_PIN 32

button_t button_1;
button_t button_2;

void IRAM_ATTR button_isr()
{
  button_update(&button_1);
}

void setup()
{
  Serial.begin(115200);

  button_add_default(&button_1, BUTTON_1_PIN);

  button_init(&button_isr);
}

void loop()
{
  if(button_1.mode) {
    Serial.print("Button mode: ");
    Serial.println(button_1.mode);
    button_1.mode = NONE;
  }
  
  delay(100);
}
#endif
