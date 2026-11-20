/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

program: 7
Task: The different keys we click on the keypad should be displayed on the Serial Monitor.
Things to Note: Make sure that your pin connections for the 4 rows and 3 columns match the pins in rowPins and colPins.
*/

#include <Keypad.h>                       // This library takes care of scanning all the different rows and columns, and takes care of switch debouncing

const byte Rows = 4;                      // Number of rows on the keypad
const byte Columns = 3;                   // Number of columns on the keypad

char keys [Rows][Columns] = {             // Defines the keys in the keypad in the same layout
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[Rows] = {18, 5, 17, 16};             //The Row pins that are connected to our ESP32
byte colPins[Columns] = {4, 0, 2};                // The Column pins that are connected ...

Keypad customkeypad = Keypad( makeKeymap(keys), rowPins, colPins, Rows, Columns);           // Object of the Keypad class we imported above


void setup() {
  Serial.begin(9600);

}

void loop() {
  char customkey = customkeypad.getKey();           // Reads the key that was pressed (empty if no key is pressed)
  if(customkey)                                     // Checks if a key is pressed
  {
    Serial.println(customkey);                      // Prints the pressed key into the Serial monitor
  }

}
