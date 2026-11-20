/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

Program: 20

Bluetooth Classic

Task: Upload this sketch to the ESP32 on Laptop A and open the Serial Monitor
  at 115200 baud. On Laptop B, open the Bluetooth settings and connect to the
  device named ESP32-Bluetooth. Then open the Arduino IDE on Laptop B, pick the
  Bluetooth port (/dev/cu.ESP32-Bluetooth) and open its Serial Monitor. Type on one laptop and the message appears on
  the other.
  */

#include "BluetoothSerial.h"

const char* DEVICE_NAME = "ESP32-Bluetooth";

BluetoothSerial BT;

void setup() {
  Serial.begin(115200);
  BT.begin(DEVICE_NAME);  
}

void loop() {
  // Serial Monitor(Laptop A) -> Laptop B
  if (Serial.available()) {
    BT.write(Serial.read());
  }
  // Laptop B -> Serial Monitor(Laptop A)
  if (BT.available()) {
    Serial.write(BT.read());
  }
  delay(10);
}
