// Docs **************************************************
// -------------------------------------------------------
// copyright kiarash kiani 2020
// shannon version 3
// email: hi@kiarsh.info
// -------------------------------------------------------
// turn on led status     ->    startProgress()
// turn off led status    ->    stopProgressWithWait(true)
// *******************************************************

class StatusBlink{
private:
  int pinNumber;
public:
  StatusBlink(int);
  void setup();
  void start();
  void finish();
};

StatusBlink::StatusBlink(int port){
  this->pinNumber = port;
}

void StatusBlink::setup(){
  pinMode(this->pinNumber, OUTPUT);
}

void StatusBlink::start(){
  digitalWrite(this->pinNumber, HIGH);
}

void StatusBlink::finish(){
  delay(200);
  digitalWrite(this->pinNumber, LOW);
}
