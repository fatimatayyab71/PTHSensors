#include<PTHSensors.h>

//PIR pirobj(2, 23);         //sending pin numbers to the constructor as an argument
TnH* objTnH= new TnH();
PIR* pirobj= new PIR();
void setup()
{
   // pirobj.initialize();
    Serial.begin(9600);
    Wire.begin();
}
void loop()
{
    pirobj->process();
    objTnH->displayTnH();
    delete objTnH;
    delete pirobj;
    delay(100);
}