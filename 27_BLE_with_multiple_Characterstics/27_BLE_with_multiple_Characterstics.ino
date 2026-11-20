/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

Program: 27

Task: Upload this sketch. Connect a green LED to pin 23 and a red LED to
  pin 21. On your phone, open nRF Connect, connect to BLE_Task5 and open the
  service. It now has two characteristics, one for each LED. Write 1 (as UTF8
  text) to a characteristic to turn its LED on, and 0 to turn it off.

How it Works:
  One service holds two characteristics, each with its own UUID. So the green_led is one characterstic and the red is another.
  The phone chooses which LED to control by choosing which characteristic
  to write to. The same value (1 or 0) does different things depending on
  where it is written.
*/

#include <BLEDevice.h>

BLEDevice ble;

char* Service_UUID = "611dcd72-4e8a-42d7-a71c-ebaebec1c512";
char* green_UUID = "611dcd73-4e8a-42d7-a71c-ebaebec1c512";   // each characteristic needs its own UUID
char* red_UUID = "611dcd74-4e8a-42d7-a71c-ebaebec1c512";

BLECharacteristic* green_charac;            // global so loop() can use it
BLECharacteristic* red_charac;

int green_led = 23;
int red_led = 21;

void setup()
{
  pinMode(green_led, OUTPUT);
  pinMode(red_led, OUTPUT);
  ble.init("BLE_Task5");

  BLEServer* server = ble.createServer();
  BLEService* service = server->createService(Service_UUID);
  green_charac = service->createCharacteristic(green_UUID, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);  // phone can read and write it
  red_charac = service->createCharacteristic(red_UUID, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);      // phone can read and write it

  green_charac->setValue("Green LED Switch");
  red_charac->setValue("Red LED Switch");
  service->start();
  ble.startAdvertising();

}

void loop()
{
  String green_data = green_charac->getValue();   // what the phone wrote to green
  String red_data = red_charac->getValue();       // what the phone wrote to red

  if(green_data == "1")
  {
    digitalWrite(green_led, HIGH);
    green_charac->setValue("Green Led is ON");    // replace "1" so this runs only once
  }
  else if(green_data == "0")
  {
    digitalWrite(green_led, LOW);
    green_charac->setValue("Green Led is OFF");
  }
  if(red_data == "1")
  {
    digitalWrite(red_led, HIGH);
    red_charac->setValue("Red Led is ON");
  }
  else if(red_data == "0")
  {
    digitalWrite(red_led, LOW);
    red_charac->setValue("Red Led is OFF");
  }
  delay(100);                                     // check 10 times a second

}