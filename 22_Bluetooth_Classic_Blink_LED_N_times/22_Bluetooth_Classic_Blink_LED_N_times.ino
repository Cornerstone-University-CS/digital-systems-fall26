/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

Program: 22

Blink an led n times from another device connected via Bluetooth Classic

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

  Send a number from 1 to 9. The LED blinks that many times.
  */

#include <BluetoothSerial.h>

BluetoothSerial BT;
const char* Bluetooth_name = "ESP32-Bluetooth";
int green_led = 23;
char reading;

void setup() {
  Serial.begin(115200);
  pinMode(green_led, OUTPUT);

  BT.begin(Bluetooth_name);

}

void loop() {
  if(BT.available())
  {
    reading = BT.read();
  }
  if(reading > '1' && reading < '9')
  {
    int times = reading - '0';      // turns '5' to 5. '0' corresponds to 48 in ASCII format

    for(int i=0; i<times;i++)
    {
      digitalWrite(green_led, HIGH);
      delay(500);
      digitalWrite(green_led, LOW);
      delay(500);
    }
  }
  delay(500);

}
