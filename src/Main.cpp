//Version 1.1 
#include<PTHSensors.h>

PIR pirobj;         
TnH TnHobj;

void setup()
{
    pirobj.initialize();
    Serial.begin(9600);
    Wire.begin();
}
void loop()
{
    pirobj.process();
    TnHobj.displayTnH();
    delay(100);
}