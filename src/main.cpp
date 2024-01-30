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
#include <keyboard_ble.h>

void setup() {
  Serial.begin(115200);
  button_config();
  BLE_Config();
}

void loop() {
  onDataSent();
}
#endif
