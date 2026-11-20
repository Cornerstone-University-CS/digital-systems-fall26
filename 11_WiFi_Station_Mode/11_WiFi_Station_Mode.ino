/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

Program: 11
Task: Connect to the WiFi of a local network (a Hotspot in this case) and print the assigned IP address. 
This is a good example of how an ESP32 connects to an existing network(wifi) in station mode.

*/

#include <WiFi.h>
#include <WebServer.h>

char* ssid = "Nehmiya";
char* password = "Nehmiya1";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP Address : ");
  Serial.println(WiFi.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:
}
