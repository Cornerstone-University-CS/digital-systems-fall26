/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

Program: 16
Task: Connect the ESP32 to an existing WiFi network using WiFi.begin() in
      Station mode. Then create a web server with a /leds path, and build a
      web page (test.html) with buttons that use fetch() to send addresses
      like /leds?green=1&red=0. Add the server.sendHeader("Access-Control-Allow-Origin", "*")
      so that the server(ESP32) knows which requests to handle.

To run it : open test.html

*/

#include <WiFi.h>                         // Lets the ESP32 join a network
#include <WebServer.h>                    // Web server library: lets the ESP32 receive and answer browser requests

WebServer server(80);                     // Create a web server on port 80 (the standard port for web pages)
int green_led = 23;     

char* ssid = "Nehmiya";                           // WiFi network name
char* password = "Nehmiya1";                       // WiFi password

void handleon()
{
  server.sendHeader("Access-Control-Allow-Origin", "*");
  digitalWrite(green_led, HIGH);               // Turn the LED on
  server.send(200, "text/plain", "LED on");    // Reply to the browser (200 = success)
}

void handleoff()
{
  server.sendHeader("Access-Control-Allow-Origin", "*");
  digitalWrite(green_led, LOW);                // Turn the LED off
  server.send(200, "text/plain", "LED off");   // Reply to the browser
}

void setup() {

  pinMode(green_led, OUTPUT);    
  Serial.begin(115200);          

  WiFi.begin(ssid, password);                   // Start connecting to the WiFi network (Station mode)

  
  while(WiFi.status() != WL_CONNECTED)          // Wait until the ESP32 is connected, printing a dot every half second
  {
    Serial.print(".");
    delay(500);
  }

  // Print the network name and the ESP32's IP address
  Serial.println();
  Serial.print("Connected to : ");
  Serial.println(ssid);
  Serial.print("IP Address : ");
  Serial.println(WiFi.localIP());   

  server.on("/on", handleon);                       // When a request arrives for /on, run handleon
  server.on("/off", handleoff);                     // When a request arrives for /off, run handleoff
  server.begin();                                   // Start the web server

}

void loop() {
  server.handleClient();                            // Check for new browser requests and run the matching function

}
