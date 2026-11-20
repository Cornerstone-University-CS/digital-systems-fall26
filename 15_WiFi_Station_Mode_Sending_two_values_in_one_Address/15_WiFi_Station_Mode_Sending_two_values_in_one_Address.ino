/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

Program: 15
Task: Connect the ESP32 to an existing WiFi network using WiFi.begin() in
      Station mode. Then create a web server with a /leds path that reads two
      values from the address with server.arg() and turns each LED on (1) or
      off (0).
To run it : open http://IP Address/leds?green=0&red=1 in the browser.

*/

#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

int green_led = 23;
int red_led = 21;

char* ssid = "Nehmiya";
char* password = "Nehmiya1";

void handle_Leds()
{
  int green_val = server.arg("green").toInt();
  int red_val = server.arg("red").toInt();

  digitalWrite(green_led, green_val);
  digitalWrite(red_led, red_val);

  server.send(200, "text/plain", "OK");
}

void setup()
{
  Serial.begin(115200);
  pinMode(green_led, OUTPUT);
  pinMode(red_led, OUTPUT);

  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500); 
  }

  Serial.println();
  Serial.print("Connected to : ");
  Serial.println(ssid);
  Serial.print("IP Address : ");
  Serial.println(WiFi.localIP());

  server.on("/leds", handle_Leds);
  server.begin();
}

void loop()
{
  server.handleClient();
}