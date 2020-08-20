// Docs **************************************************
// -------------------------------------------------------
// copyright kiarash kiani 2020
// shannon version 3
// email: hi@kiarsh.info
// -------------------------------------------------------
// send commands simply on serial ports
// ONLY byte accaptable
// DO NOT USE pin 13 for anything but progress status LEDsudo 
// *******************************************************

#include "sensor.h"
#include "StatusBlink.h"
#include "bluetooth.h"

StatusBlink statusLED(13);

// -- Sensors
DigitalSensor motion_sensor(7);


void setup() {
  Serial.begin(9600);
  Serial.setTimeout(150);

  setupNetwork();
  motion_sensor.setup();
}

void loop() {
  if (motion_sensor.read()){
    writeToNetwork(byte(0x30));
  } 
  else {
    writeToNetwork(byte(0x31));
  }

  delay(1000);
}
