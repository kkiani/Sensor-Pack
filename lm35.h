class LM35{
private:
    int pinNumber;
public:
    LM35(int pin);
    void setup();
    int read();
};

LM35::LM35(int pin){
    this->pinNumber = pin;
}

void LM35::setup(){}

int LM35::read(){
    int val = analogRead(this->pinNumber);
    float mv = (val/1024.0)*5000;
    float cel = mv/10;

    return cel;
}