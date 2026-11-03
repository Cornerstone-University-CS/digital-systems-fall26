/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

Program: 9
Task: Connect the Face Detection AI model with the ESP32's IDE and forward the model's prediction output to the ESP32 board.
      If the AI model detects a face, the green LED should be ON; if not, the red LED should be ON.

Note: We will do this in our next class meeting.
*/

int led_green = 23;
int led_red = 21;

void setup() {
  Serial.begin(115200);
  pinMode(led_green, OUTPUT);
  pinMode(led_red, OUTPUT);
}

void loop() {
  
  if (Serial.available() > 0) {
      String line = Serial.readStringUntil('\n');               // Read characters until the end of the line, for example "0.97,0.03"

      int comma = line.indexOf(',');                            // Before splitting the predictions output, find where the comma is (in "0.97,0.03" it is at position 4)
      float class1 = line.substring(0, comma).toFloat();       // Take the text before the comma ("0.97") and turn it into a number      
      float class2 = line.substring(comma + 1).toFloat();      // Take the text after the comma ("0.03") and turn it into a number

      float threshold = 0.8;

      if(class1 > threshold)
      {
        digitalWrite(led_green, HIGH);
        digitalWrite(led_red, LOW);
      }
      else if(class2 > threshold)
      {
        digitalWrite(led_red, HIGH);
        digitalWrite(led_green, LOW);
      }


  }

}

