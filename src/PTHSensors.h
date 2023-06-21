//Version 1.1
#include <Arduino.h>
#include <Wire.h>
#define AHT20_I2C_ADDR 0x38
#define SDA_PIN 21
#define SCL_PIN 22

///////////////////////////////////////////////
class PIR{
private:
int led = 2;
int inputpin =23;
int pirstate = LOW;
int val = 0;

public:
PIR();        // Default Constructor
~PIR();      //Default Destructor
void initialize();
void process();
};

//////////////////////////////////////////////
class TnH{
private:
float temperature;
float humidity;

public:
TnH();
~TnH();
void beginTransmission();
bool readResponse(float, float);
void displayTnH();
};
