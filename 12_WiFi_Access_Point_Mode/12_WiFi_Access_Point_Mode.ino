/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

Program: 12
Task: Create our own WiFi Access Point using the WiFi.softAP() function, which 
      broadcasts a new wireless network with the specified SSID (network name) 
      and password.

*/

#include <WiFi.h>                           // Include the built-in WiFi libraries

                                            // Both the network name and password should be atleasy 8 characters long
char* ssid = "mynewnetwork";
char* password = "newpassword";

void setup() {
  Serial.begin(115200);

  WiFi.softAP(ssid, password);              // Configure the microcontroller to act as an Access Point (Host) broadcasting the network
  Serial.print("Access Point IP : ");
  Serial.println(WiFi.softAPIP());          // print the IP address allocated to this Access Point

}

void loop() {

}
