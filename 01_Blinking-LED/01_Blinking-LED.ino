/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

program: 1
Task: Makes the led light connected to pin 23 blink with a delay of 1 Second (1000ms)
*/

int ledpin = 23;                  // The LED light is connected to GIOP 23 (General purpose Input/Output pin 23)

void setup() {                    // put your setup code here, to run once:
  pinMode(ledpin, OUTPUT);        // The pinMode() function takes 2 parameters: the pin number and the type of action you want to do with that pin, which is either to read information (INPUT) or to output information (OUTPUT).
}

void loop() {                     // put your main code here, to run repeatedly:
  digitalWrite(ledpin, HIGH);     // The digitalWrite() function takes 2 parameters: the pin number and the value you want to write to that pin (HIGH or LOW).
  delay(1000);                    // The delay() function makes the program execution stop for n milliseconds.
  digitalWrite(ledpin, LOW); 
  delay(1000);

}
