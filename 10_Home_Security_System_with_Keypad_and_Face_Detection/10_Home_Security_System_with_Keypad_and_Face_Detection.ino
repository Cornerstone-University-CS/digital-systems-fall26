/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

Program: 10
Task: The user has to type in the password and press the button.
 If the Ai Model detects the users face and the entered password is correct, the green LED turns on for 5 seconds.
 If the users face is not detected or the entered password is incorrect, the red LED and the buzzer turn on for 5 seconds.
*/

#include <Keypad.h>  // This library takes care of pulling all the different rows and columns and, takes care of switch debouncing
#include <vector>

const byte Rows = 4;
const byte Columns = 3;

int led_green = 23;
int led_red = 21;

int button = 22;
int buzzer = 15;   

float class1;
float class2;
float prediction_threshold = 0.8;                 // The Ai model should be atleast 80 percent sure

std::vector<char> password = {'1','2','3'};
std::vector<char> password_input;

char keys [Rows][Columns] = {                     // This defines the keys in the keypad
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[Rows] = {18, 5, 17, 16};     //The Row pins that are connected to our ESP32
byte colPins[Columns] = {4, 0, 2};        // The Column pins that are connected ...

Keypad customkeypad = Keypad( makeKeymap(keys), rowPins, colPins, Rows, Columns);  // Object of the Keypad class we imported above

void setup() {

  pinMode(button, INPUT_PULLUP);
  pinMode(led_green, OUTPUT);
  pinMode(led_red, OUTPUT);
  pinMode(buzzer, OUTPUT);
  analogWrite(buzzer, 255);   // Turns OFF the Buzzer because it beeps during start 
  Serial.begin(115200);                                          
} 

void loop() {

  char customkey = customkeypad.getKey();

  if(customkey)                               // Checks if the user is typing on the keypad
  {
    password_input.push_back(customkey);
    //Serial.println(customkey);
  }

  if(Serial.available() > 0)                                
  {
    String line = Serial.readStringUntil('\n');             // Read characters until the end of the line, for example "0.97,0.03"

    int comma = line.indexOf(',');                          // Before splitting the predictions output, find where the comma is (in "0.97,0.03" it is at position 4) 

    class1 = line.substring(0, comma).toFloat();      // Take the text before the comma ("0.97") and turn it into a number  
    class2 = line.substring(comma + 1).toFloat();  

    if(digitalRead(button) == LOW)            // Checks if the submit button is pressed
    {

      if(password == password_input && class1 > prediction_threshold)
      {
        //Serial.println(" ------- Welcome Home --------");
        digitalWrite(led_green, HIGH);
        delay(5000);
        digitalWrite(led_green, LOW);
        password_input.clear();
      }
      else
      {
        //Serial.println(" !! Incorrect password !! ");
        digitalWrite(led_red, HIGH);
        analogWrite(buzzer, 50);    // Turns ON the Buzzer
        delay(5000);
        digitalWrite(led_red, LOW);
        analogWrite(buzzer, 255);   // Turns OFF the Buzzer
        password_input.clear();

      }
    }
  }

}

