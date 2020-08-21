#include <SoftwareSerial.h>

class BLENetwork{
private:
    SoftwareSerial *hc_port;
public:
    BLENetwork(void);
    void setup();
    int read();
    void write(byte);
};

BLENetwork::BLENetwork(void){
    this->hc_port = new SoftwareSerial(10, 11);
}

void BLENetwork::setup(){
    this->hc_port->begin(9600);
}

int BLENetwork::read(){
    if (this->hc_port->available()){
        return this->hc_port->parseInt();
    }
    return 1;
}

void BLENetwork::write(byte value){
    this->hc_port->write(value);
}