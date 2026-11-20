/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

program: 4
Task: turns the led_light connected to pin 21 on/off using the button connected to pin 22
*/

int led_light = 21; 
int button = 22;
bool is_on = false;                          // A condition controlling variable that helps us track the current state of the led light (whether it is on or off)

void setup() {                              // put your setup code here, to run once:
  pinMode(led_light, OUTPUT);
  pinMode(button, INPUT_PULLUP);           // The INPUT_PULLUP serves as a resistor in the button (it makes sure the value reading of the button doesn't change until it is clicked)
}

void loop() {
  
  if(digitalRead(button) == LOW)          // Since we are using INPUT_PULLUP for the button, when it is clicked no current will flow. That's why 'digitalRead(button) == LOW' corresponds to 'button clicked'
  {
    if(is_on == false)                    // if the light is not 'ON'
    {
      digitalWrite(led_light, 255);       // Turns the light 'ON'
      is_on = true;                       
      delay(300);
    }
    else if(is_on == true)
    {
      digitalWrite(led_light, 0);
      is_on = false;
      delay(300);
    }
  }

}
