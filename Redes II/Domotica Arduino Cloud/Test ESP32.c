/*
Nota: Para esto, se utilizó un ESP32 
MODELO: DOIT ESP32 DEVKIT V1

--Espacio Personal
Device ID:
9ba5d159-f1e0-4c56-83e4-bf7d16252539

Secret Key:
ORMFGTPBCIOAQDRXWZSR

--Espacio Compartido--
Device ID:
7bc70465-b669-4a64-a90f-530bf1d13d2b

SecretKey:
WMM0ONBISPSLIBU4WB4B
*/
#include "thingProperties.h"

int LED = 2;

void setup() {
  pinMode(LED, OUTPUT);
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  random_value = random(0, 500);
  delay(500);
}


void onLedSwitchChange() {
  // Do something
  if(led_switch){
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
}
/*
  Since Calendario is READ_WRITE variable, onCalendarioChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onCalendarioChange()  {
  // Add your code here to act upon Calendario change
}