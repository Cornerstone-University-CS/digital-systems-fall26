/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

Program: 21

Task: Upload this sketch. Connect a green LED to pin 23.
  Then connect to the ESP32 over Bluetooth in one of these two ways to control the LED:

  Option 1, second laptop:
    On the second laptop, connect to the device named ESP32-Bluetooth in the
    Bluetooth settings. Then open the Arduino IDE on that laptop, pick the
    Bluetooth port (/dev/cu.ESP32-Bluetooth) and open the Serial Monitor.

  Option 2, same laptop (no second laptop needed):
    On your own laptop, connect to the device named ESP32-Bluetooth in the
    Bluetooth settings. Then open a second Arduino IDE window (File > New
    Sketch), pick the Bluetooth port (/dev/cu.ESP32-Bluetooth) and open the Serial Monitor in that window.

  Send '1' to turn the green LED on. Send '2' to turn it off.

*/


#include <BluetoothSerial.h>

BluetoothSerial BT;

const char* Bluetooth_name = "ESP32-Bluetooth";

int green_led = 23;
char reading;

void setup() {
  BT.begin(Bluetooth_name);
  pinMode(green_led, OUTPUT);

}

void loop() {
  if(BT.available())
  {
    reading = BT.read();
  }

  if(reading == '1')
  {
    digitalWrite(green_led, HIGH);
  }
  else if(reading == '2')
  {
    digitalWrite(green_led, LOW);
  }
  delay(100);

}
