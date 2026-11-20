/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

Program: 14
Task: Connect the ESP32 to an existing WiFi network using WiFi.begin() in
      Station mode. Then create a web server with a /blink path that reads a
      number from the address with server.arg(), blinks the LED that many
      times/
To run it : open http://IP Address/blink?times=3 in the browser.

*/

#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

int green_led = 23;

char* ssid = "Nehmiya";
char* password = "Nehmiya1";

void blink_handler()
{
  int blink_value = server.arg("times").toInt();          // read the number after "times="

  for(int i=0; i<blink_value; i++)
  {
    digitalWrite(green_led, HIGH);
    delay(500);
    digitalWrite(green_led, LOW);
    delay(500);
  }

  server.send(200, "text/plain", "Done");
}

void setup()
{
  Serial.begin(115200);
  pinMode(green_led, OUTPUT);

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

  server.on("/blink", blink_handler);
  server.begin();
}

void loop()
{
  server.handleClient();
}