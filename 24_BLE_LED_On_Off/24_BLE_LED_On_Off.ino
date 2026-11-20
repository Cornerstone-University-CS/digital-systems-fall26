/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

Program: 24

Task: Upload this sketch and connect a green LED to pin 23. On your phone,
  open nRF Connect, connect to BLE-Task2 and open the service. Write 1 (as
  UTF8 text) to the characteristic to turn the LED on, and 0 to turn it off.
  Read the characteristic to see the LED status.

How it Works:
  The phone writes a value into the characteristic. loop() keeps checking
  that value. When it sees 1 or 0, it turns the LED on or off, then replaces
  the value with the LED status so the phone can read it.

*/

#include <BLEDevice.h>

BLEDevice ble;

char* Service_UUID = "611dcd72-4e8a-42d7-a71c-ebaebec1c512";
char* Char_UUID = "611dcd73-4e8a-42d7-a71c-ebaebec1c512";

BLECharacteristic* charac;                          // global so loop() can use it

int green_led = 23;

void setup()
{
  pinMode(green_led, OUTPUT);
  ble.init("BLE-Task2");

  BLEServer* server = ble.createServer();
  BLEService* service = server->createService(Service_UUID);
  charac = service->createCharacteristic(Char_UUID, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);  // phone can read and write it

  charac->setValue("Here I am");
  service->start();

  ble.startAdvertising();
}

void loop()
{
  String state = charac->getValue();  // what the phone wrote

  if(state == "1")
  {
    digitalWrite(green_led, HIGH);
    charac->setValue("LED is ON");    
  }
  else if (state == "0")
  {
    digitalWrite(green_led, LOW);
    charac->setValue("LED is OFF");   
  }
  delay(100);                         // check 10 times a second
}