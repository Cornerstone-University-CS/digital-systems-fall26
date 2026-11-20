/*
Prof. Nehmiya Shikur
EGR-226: Digital Sys and Computer ORG

Program: 23

Task: Use BLE notify to send a message to the phone every time the button
      on GPIO 22 is pressed. Each press sends "Button pressed" with a
      counter, so every click shows up as a new message.
To run it : connect to "Notification-Sender" in nRF Connect, tap the three
            down arrows to subscribe, then press the button.
*/

#include <BLEDevice.h>
#include <BLE2902.h>

BLEDevice ble;

char* Service_UUID = "611dcd72-4e8a-42d7-a71c-ebaebec1c512";              
char* Charac_UUID = "611dcd73-4e8a-42d7-a71c-ebaebec1c512";      

BLECharacteristic* charac;

int button = 22;

int lastState = HIGH; 
int button_click_counter;


void setup()
{
  Serial.begin(115200);
  pinMode(button, INPUT_PULLUP);


  ble.init("Notification-Sender");                                                                               // Turns on BLE with a name

  BLEServer* server = ble.createServer();                                                                   // Makes the ESP32 a server
  BLEService* service = server->createService(Service_UUID);                                                // Creates a service inside the server
  charac = service->createCharacteristic(Charac_UUID,BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);  // Creates a characteristic the phone can read inside the service
  charac->addDescriptor(new BLE2902());

  charac->setValue("Helllloooo");                            // Put a value in the characteristic
  service->start();                                          // Starts the service
  ble.startAdvertising();                                    // Starts advertising so the phone can find it

}

void loop()
{
  int button_val = digitalRead(button);

  if (button_val == LOW && lastState == HIGH)    // just pressed
  {
    button_click_counter+=1;
    String message =  "Button pressed " + String (button_click_counter);
    charac->setValue(message.c_str());
    charac->notify();
    Serial.println(message);
  }

  lastState = button_val;     // remember this reading for next time
  delay(50);
}                                              