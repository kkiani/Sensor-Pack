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
#include "lm35.h"
#include "ble_network.h"

StatusBlink statusLED(13);
BLENetwork network;

// -- Sensors
DigitalSensor motion_sensor(7);
LM35 temp_sensor(A1);

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(150);

  network.setup();
  motion_sensor.setup();
  temp_sensor.setup();
}

void loop() {
  if (motion_sensor.read()){
    network.write(byte(0x30));
  } 
  else {
    network.write(byte(0x31));
  }

  Serial.println(temp_sensor.read());

  delay(1000);
}
