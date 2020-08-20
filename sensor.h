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

class DigitalSensor{
private:
  int pinNumber; 
public:
  DigitalSensor(int);
  void setup();
  bool read();
};

DigitalSensor::DigitalSensor(int port){
  this->pinNumber = port;
}

void DigitalSensor::setup(){
  pinMode(this->pinNumber, INPUT);
}

bool DigitalSensor::read(){
  int res = 0;
  for (int i=0; i<100; i++){
    if (digitalRead(this->pinNumber)){
      res = res + 1;
    }
    delay(10);
  }
  
  return res>50;
}
