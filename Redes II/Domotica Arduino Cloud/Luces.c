#include "thingProperties.h"
int luces_encendidas = 0;
int luz_comedor = 16;
int luz_cocina = 17;
int luz_cuarto2 = 5;
int luz_cuarto1 = 13;
int luz_banio = 23;
int luz_alarma = 22;
int luz_entrada = 33;
int luz_puerta = 32;

void setup() {
  pinMode(luz_comedor, OUTPUT);
  pinMode(luz_cocina, OUTPUT);
  pinMode(luz_cuarto2, OUTPUT);
  pinMode(luz_cuarto1, OUTPUT);
  pinMode(luz_banio, OUTPUT);
  pinMode(luz_alarma, OUTPUT);
  pinMode(luz_entrada, OUTPUT);
  pinMode(luz_puerta, OUTPUT);
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
  delay(500);
  
  if(calendario.isActive())
  {
    digitalWrite(luz_puerta, HIGH);
    switch_puerta = true;
  }
  else
  {
    digitalWrite(luz_puerta, LOW);
    switch_puerta = false;
  }
  
}

void onCalendarioChange()  {
  /*
  if(calendario.isActive() && switch_puerta == false)
  {
    digitalWrite(luz_puerta, HIGH);
    switch_puerta=true;
  }
  else if(switch_puerta == true)
  {
    digitalWrite(luz_puerta, LOW);
    switch_puerta = false;
  }
  */
}

void onSwitchPuertaChange()  {
  // Add your code here to act upon SwitchPuerta change
  if(switch_puerta){
    digitalWrite(luz_puerta, HIGH);
    switch_luces=true;
    luces_encendidas++;
  }
  else{
    digitalWrite(luz_puerta, LOW);
    if(luces_encendidas == 1)
    {
      switch_luces=false;
    }
    luces_encendidas--;
  }
}

void onSwitchComedorChange()  {
  // Add your code here to act upon SwitchPuerta change
  if(switch_comedor){
    digitalWrite(luz_comedor, HIGH);
    switch_luces=true;
    luces_encendidas++;
  }
  else{
    digitalWrite(luz_comedor, LOW);
    if(luces_encendidas == 1)
    {
      switch_luces=false;
    }
    luces_encendidas--;
  }
}

void onSwitchBanioChange()  {
  // Add your code here to act upon SwitchPuerta change
  if(switch_banio){
    digitalWrite(luz_banio, HIGH);
    switch_luces=true;
    luces_encendidas++;
  }
  else{
    digitalWrite(luz_banio, LOW);
    if(luces_encendidas == 1)
    {
      switch_luces=false;
    }
    luces_encendidas--;
  }
}
void onSwitchLucesChange()  {
  // Do something
  if(switch_luces){
    digitalWrite(luz_comedor, HIGH);
    switch_comedor=true;
    digitalWrite(luz_cocina, HIGH);
    digitalWrite(luz_cuarto2, HIGH);
    digitalWrite(luz_cuarto1, HIGH);
    digitalWrite(luz_banio, HIGH);
    switch_banio=true;
    digitalWrite(luz_alarma, HIGH);
    digitalWrite(luz_entrada, HIGH);
    digitalWrite(luz_puerta, HIGH);
    switch_puerta=true;
    
    luces_encendidas = 8;
  }
  else{
    digitalWrite(luz_comedor, LOW);
    switch_comedor=false;
    digitalWrite(luz_cocina, LOW);
    digitalWrite(luz_cuarto2, LOW);
    digitalWrite(luz_cuarto1, LOW);
    digitalWrite(luz_banio, LOW);
    switch_banio=false;;
    digitalWrite(luz_alarma, LOW);
    digitalWrite(luz_entrada, LOW);
    digitalWrite(luz_puerta, LOW);
    switch_puerta=false;
    
    luces_encendidas = 0;
  }
}
