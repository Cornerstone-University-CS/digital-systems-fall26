/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

Program: 8
Task: The user has to type in the password and press the button.
 If the entered password is correct, the green LED turns on and a 'Welcome Home' message is displayed on the Serial Monitor.
 If the entered password is incorrect, the red LED and the buzzer turn on for 5 seconds.
*/

#include <Keypad.h>                                   // This library takes care of scanning all the different rows and columns, and takes care of switch debouncing
#include <vector>                                     // Lets us use vectors (lists that can grow) to store the typed keys

const byte Rows = 4;                                    // Number of rows on the keypad
const byte Columns = 3;                                 // Number of columns on the keypad

int led_green = 23;                                     // Green LED: if password is correct
int led_red = 21;                                       // Red LED: if password is incorrect

int button = 22;                                        // Submit button
int buzzer = 15;                                       

std::vector<char> password = {'1','2','3'};             // This is the system password the user have to input to get into the house         
std::vector<char> password_input;                       // Stores the keys the user types, one by one

char keys [Rows][Columns] = {                           // This defines the keys in the keypad
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[Rows] = {18, 5, 17, 16};                   //The Row pins that are connected to our ESP32
byte colPins[Columns] = {4, 0, 2};                      // The Column pins that are connected ...

Keypad customkeypad = Keypad( makeKeymap(keys), rowPins, colPins, Rows, Columns);  // Object of the Keypad class we imported above

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(led_green, OUTPUT);
  pinMode(led_red, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(buzzer, HIGH);                         // Makes sure the buzzer starts OFF
  Serial.begin(1200);                           // I lowered the baud rate for a slower update on the serial monitor (Make sure to set the Serial monitor to 1200 too)
}

void loop() {

  char customkey = customkeypad.getKey();

  if(customkey)                                     // Checks if the user is typing on the keypad
  {
    password_input.push_back(customkey);            // Adds the typed key to the end of the user's input
    Serial.println(customkey);
  }
  
  if(digitalRead(button) == LOW)                    // Checks if the submit button is pressed
  {
    Serial.println("Button Pressed");

    Serial.print(" User typed Password ");
    for(char val: password_input)                   // Prints every key the user types
    {
      Serial.print(val);
    }

    if(password == password_input)                  // Compares the typed password with the system password
    {
      Serial.println(" ------- Welcome Home --------");
      digitalWrite(led_green, HIGH);
      delay(5000);
      digitalWrite(led_green, LOW);
      password_input.clear();                       // Clears the input so that the user can try again
    }
    else
    {
      Serial.println(" !! Incorrect password !! ");
      digitalWrite(led_red, HIGH);
      analogWrite(buzzer, 50);                      // Turns ON the Buzzer
      delay(5000);
      digitalWrite(led_red, LOW);
      analogWrite(buzzer, 255);                     // Turns OFF the Buzzer
      password_input.clear();

    }
  }
}
