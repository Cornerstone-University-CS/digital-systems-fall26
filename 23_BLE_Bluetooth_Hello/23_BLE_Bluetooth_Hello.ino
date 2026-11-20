/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

Program: 23

Sending a Simple "Hello" text via Bluetooth Low Energy (BLE)

Task: After uploading this sketch. On your phone, Download 'nRF Connect' app from the Appstore and open it, connect to
  'BLE-Bluetoooth' which is the name of the bluetooth declared using the .init() function, then open the service and read the characteristic.
  You should see "Helllloooo".

How it Works:
  The ESP32 is a server that holds one service with one characteristic.
  The phone connects and reads the value stored in the characteristic.

*/

#include <BLEDevice.h>

BLEDevice ble;

char* Service_UUID = "611dcd72-4e8a-42d7-a71c-ebaebec1c512";              
char* Charac_UUID = "611dcd73-4e8a-42d7-a71c-ebaebec1c512";               

void setup()
{
  ble.init("BLE-Bluetoooth");                                                                               // Turns on BLE with a name

  BLEServer* server = ble.createServer();                                                                   // Makes the ESP32 a server
  BLEService* service = server->createService(Service_UUID);                                                // Creates a service inside the server
  BLECharacteristic* charac = service->createCharacteristic(Charac_UUID,BLECharacteristic::PROPERTY_READ);  // Creates a characteristic the phone can read inside the service

  charac->setValue("Helllloooo");                            // Put a value in the characteristic
  service->start();                                          // Starts the service
  ble.startAdvertising();                                    // Starts advertising so the phone can find it

}

void loop(){}                                               