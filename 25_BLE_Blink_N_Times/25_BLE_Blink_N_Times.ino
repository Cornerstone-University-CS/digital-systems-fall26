/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

Program: 25

Task: Upload this sketch and connect a green LED to pin 23. On your phone,
  open nRF Connect, connect to BLE_Task3 and open the service. Write a number
  N from 1 to 9 (as UTF8 text) to the characteristic. The LED blinks N times.

How it Works:
  The phone writes a number into the characteristic. loop() reads it and
  turns it into an int with toInt(). The LED blinks that many times, then
  the value is replaced with "Done" so it does not blink again.
  Unlike Bluetooth Classic, reading a BLE value does not remove it. The value
  stays in the characteristic until someone changes it.

*/

#include <BLEDevice.h>

BLEDevice ble;

char* Service_UUID = "611dcd72-4e8a-42d7-a71c-ebaebec1c512";
char* Char_UUID = "611dcd73-4e8a-42d7-a71c-ebaebec1c512";

BLECharacteristic* charac;            // global so loop() can use it

int green_led = 23;

void setup()
{
  pinMode(green_led, OUTPUT);
  ble.init("BLE_Task3");

  BLEServer* server = ble.createServer();
  BLEService* service = server->createService(Service_UUID);
  charac = service->createCharacteristic(Char_UUID, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);  // phone can read and write it

  charac->setValue("Here I am");
  service->start();
  ble.startAdvertising();

}

void loop()
{
  int data = charac->getValue().toInt();     // "5" becomes 5

  if (data > 0)
  {
    for(int i = 0; i< data; i++)
    {
      digitalWrite(green_led, HIGH);
      delay(200);
      digitalWrite(green_led, LOW);
      delay(200);
    }
    charac->setValue("Done");              // replace the number so that the loop runs only once
  }
  delay(100);                              // check 10 times a second
}