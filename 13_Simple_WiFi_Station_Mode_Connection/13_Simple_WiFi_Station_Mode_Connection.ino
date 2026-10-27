/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

Program: 13
Task: Connect to the WiFi of a local network (a Hotspot in this case) and print the assigned IP address. 
This is a good example of how an ESP32 connects to an existing network(wifi) in station mode.

*/

#include <WiFi.h>                                   // Loads the ESP32 WiFi library.

const char* ssid = "Nehmiya";                       // The WiFi username we are connecting to
const char* password = "Nehmiya1";                  // The WiFi password

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);                       // Establishes the WiFi connection

  while(WiFi.status() != WL_CONNECTED)              // While the WiFi is not connected ..
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());                   // Prints the IP address assigned to the ESP32
}

void loop() {

}
