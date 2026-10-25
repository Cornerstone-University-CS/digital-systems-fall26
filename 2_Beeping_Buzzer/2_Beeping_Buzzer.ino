/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

Program: 2
Task: Makes the buzzer connected to pin 15 beep with a delay of 5 seconds.
*/

int buzzer = 15;

void setup() {                        // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
}

void loop() {                         // put your main code here, to run repeatedly:
  digitalWrite(buzzer, LOW);          // Turns the buzzer ON (LOW = on, HIGH = off for this type of buzzer)
  delay(500);                       
  digitalWrite(buzzer, HIGH);         // Turns the buzzer OFF
  delay(5000);
  
}
