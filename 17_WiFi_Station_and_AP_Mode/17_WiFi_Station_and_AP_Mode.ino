/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

Program: 17

Task: Turn on both Station and Access Point mode with WiFi.mode(WIFI_AP_STA).
      The ESP32 joins an existing WiFi network and also creates its own
      network at the same time and prints the IP Addresses.

To run it : open test.html

*/

#include <WiFi.h>

char* station_ssid = "Nehmiya";
char* station_password = "Nehmiya1";

char* AP_ssid = "DemoWiFi";
char* AP_password = "DemoWiFi";

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_AP_STA);                           // turns on both modes (Station and Access Point Mode)
  WiFi.begin(station_ssid, station_password);
  WiFi.softAP(AP_ssid, AP_password);

  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }

  // Prints Station Mode Connection
  Serial.println("Station Mode");
  Serial.print("Connected to : ");
  Serial.println(station_ssid);
  Serial.print("IP Address : ");
  Serial.println(WiFi.localIP());

  // Prints the Access Point Mode Connection
  Serial.println("Access Point Mode : ");
  Serial.print(WiFi.softAPIP());

}

void loop() {}
