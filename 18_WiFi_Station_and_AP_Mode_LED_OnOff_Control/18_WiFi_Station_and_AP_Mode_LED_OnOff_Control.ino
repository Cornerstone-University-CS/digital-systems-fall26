/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

Program: 18

Task: Turn on both Station and Access Point mode with WiFi.mode(WIFI_AP_STA).
      The ESP32 joins an existing WiFi network and also creates its own
      network at the same time. Then create a web server with two paths,
      /on and /off, that turn the LED on and off from either network.

To run it : 1. Connect one device to the same WiFi as the ESP32 and open
               http:// Station IP Address/on or /off in the browser. (From the Laptop)
            2. Connect another device to the Access Point network created by ESP32's and open
               http:// Access Point IP/on or /off in the browser.
*/

#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

char* station_ssid = "Nehmiya";
char* station_password = "Nehmiya1";

char* AP_ssid = "DemoWiFi";
char* AP_password = "DemoWiFi";

int green_led = 23;

void on_handler()
{
  digitalWrite(green_led, HIGH);
  server.send(200, "text/plain", "LED ON!");

}
void off_handler()
{
  digitalWrite(green_led, LOW);
  server.send(200, "text/plain", "LED OFF!");
}

void setup() {
  Serial.begin(115200);
  pinMode(green_led, OUTPUT);

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

  server.on("/on", on_handler);
  server.on("/off", off_handler);
  server.begin();

}

void loop() {
  server.handleClient();
}
