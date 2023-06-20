#include <Arduino.h>
#include <Wire.h>
#define AHT20_I2C_ADDR 0x38
#define SDA_PIN 21
#define SCL_PIN 22
#define inputpin 23
#define led 2

class PIR{
private:
//int led;
///int inputpin;
int pirstate;
int val;

public:
//PIR(int led,int pirstate);
PIR();
~PIR();
//void initialize();
void process();
};

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
