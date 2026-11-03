// This program turns an led light with two buttons (one for turn on, and the other for turning it off)
/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

program: 3
Task: Turns the led light connected to pin 23 with two buttons (one button turns it on, the other turns it off)
*/

int green_led = 23;
int button_on = 22;                         // Turns on the led light
int button_off = 32;                         // Turns off the led light

void setup() {                            
  
  pinMode(green_led, OUTPUT);
  pinMode(button_on, INPUT_PULLUP);                // The INPUT_PULLUP serves as a resistor in the button (it makes sure the value reading of the button doesn't change until it is clicked)
  pinMode(button_off, INPUT_PULLUP);
}

void loop() {

  if(digitalRead(button_on) == LOW)               // Since we are using INPUT_PULLUP for the button, when it is clicked no current will flow. That's why 'digitalRead(button) == LOW' corresponds to 'button clicked'
  {
    digitalWrite(green_led, HIGH);                
  }
  if(digitalRead(button_off) == LOW)
  {
    digitalWrite(green_led, LOW);
  }

}
