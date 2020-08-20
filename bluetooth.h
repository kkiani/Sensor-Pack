// Docs **************************************************
// -------------------------------------------------------
// copyright kiarash kiani 2020
// shannon version 3
// email: hi@kiarsh.info
// -------------------------------------------------------
// Device([pin], [base command])
// [reserved]                     ->    [base command]
// on                             ->    [base command] + 1
// off                            ->    [base command] + 2
// [forward compatibility]        ->    [base command] + 3
// [forward compatibility]        ->    [base command] + 4
// *******************************************************

#include <SoftwareSerial.h>

SoftwareSerial hc_08(10, 11);

void setupNetwork(){
  hc_08.begin(9600);
}

int readFromNetwork(){
  if (hc_08.available()) {
    return hc_08.parseInt();
  }
}

void writeToNetwork(byte code){
  hc_08.write(code);
}
