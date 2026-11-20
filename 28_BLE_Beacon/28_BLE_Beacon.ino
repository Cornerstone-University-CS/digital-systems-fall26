/*
  BLE Beacon
  Prof. Nehmiya Shikur, Nov 19, 2026

  Keeps announcing the name "AirTag" so nearby phones and boards can see it.
*/
#include <BLEDevice.h>

BLEDevice ble;

void setup()
{
  ble.init("AirTag");

  BLEAdvertising* adv = ble.getAdvertising();
  adv->setAdvertisementType(ADV_TYPE_NONCONN_IND);   // announce only, no connecting
  adv->start();
}

void loop(){}
