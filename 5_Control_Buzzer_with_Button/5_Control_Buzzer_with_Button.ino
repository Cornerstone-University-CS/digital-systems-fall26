/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

program: 5
Task: The button connected to pin 22 turns the buzzer connected to pin 15 ON and OFF.
Things to Note: Unlike the previous programs I have declared a function called buzzer_with_button() that will be executed inside loop()
*/
int button = 22;
int buzzer = 15;
bool is_on = true;                         // A condition controlling variable that helps us track the current state of the buzzer (whether it is beeping or not)

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  digitalWrite(buzzer, HIGH);
}

void loop() {                        
  buzzer_with_button();                     // Executes(calls) the function declared below
}

void buzzer_with_button()                  
{
  if(digitalRead(button) == LOW)            // Checks if the button is pressed (LOW = pressed when using INPUT_PULLUP)
  {
    if(is_on == true)                      // If the buzzer is currently ON
    {
      digitalWrite(buzzer, LOW);            // Turns ON the buzzer
      is_on = false;                       // Remembers that the buzzer is now ON
      delay(500);                           // Waits so one press is not read as many presses
    }
    else if(is_on ==false)
    {
      digitalWrite(buzzer, HIGH);           // Turns off the buzzer
      is_on = true;
      delay(500);
    }
  }
}
