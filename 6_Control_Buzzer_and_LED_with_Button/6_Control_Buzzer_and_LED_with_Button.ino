/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

program: 6
Task: The button connected to pin 22 turns the buzzer connected to pin 15 and the led_light connected to pin 23 ON and OFF.
Things to Note: Unlike the previous programs I have declared a function called buzzer_with_button() that will be executed inside loop()
*/

int led_light = 23;
int button = 22;
int buzzer = 15;
bool is_on = false;                         // A condition controlling variable that helps us track the current state of the buzzer (whether it is beeping or not)

void setup() {
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, HIGH);               // This makes sure the buzzer doesn't go off during setup
  pinMode(button, INPUT_PULLUP);
  pinMode(led_light, OUTPUT);
}

void loop() {
  buzzer_with_button();                   // Executes(calls) the function declared below
}

void buzzer_with_button()
{
  if(digitalRead(button) == LOW)          // Checks if the button is pressed (LOW = pressed when using INPUT_PULLUP)
  {
    if(is_on == false)                    // If the buzzer is currently OFF...
    {
      digitalWrite(buzzer, LOW);          // Turns ON the buzzer
      is_on = true;                       // Remembers that the buzzer is now ON
      digitalWrite(led_light, HIGH);      // Turns ON the led_light
      delay(500);
    }
    else if(is_on == true)               // If the buzzer is currently ON ... 
    {
      digitalWrite(buzzer, HIGH);        // Turns off the buzzer
      is_on = false;
      digitalWrite(led_light, LOW);
      delay(500);
    }
  }
}
