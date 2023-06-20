# include <PTHSensors.h>
PIR::PIR()
//PIR::PIR(int ledpin, int pirpin)
{
//this->led = ledpin;
//this->inputpin = pirpin;
pirstate = LOW;
val = 0;
}
PIR::~PIR(){
}
/*void PIR::initialize()
{
  pinMode(led, OUTPUT);      // declare LED as output
  pinMode(pirstate, INPUT);     // declare sensor as input
}*/
void PIR::process()
{
   // Serial.println(inputpin);
    val = digitalRead(inputpin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(led, HIGH);  // turn LED ON
    if (pirstate == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirstate = HIGH;
    }
  } else {
    digitalWrite(led , LOW); // turn LED OFF
    if (pirstate == HIGH) {
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirstate = LOW;
    }
  }
}
//PIR pirobj(2, 23);

//******functions for class TnH
TnH::TnH(){
    Wire.begin(SDA_PIN, SCL_PIN);
} 
TnH::~TnH(){

}
void TnH::beginTransmission(){
    Wire.beginTransmission(AHT20_I2C_ADDR);
    Wire.write(0xAC);    //request temperature fron data frame this address of Data Frame
    Wire.write(0x33);
    Wire.endTransmission();
    delay(100);
}

bool TnH::readResponse(float temperature, float humidity) {
    Wire.requestFrom(AHT20_I2C_ADDR, 6);
    if (Wire.available() == 6) {
      byte msb1 = Wire.read();
      byte lsb1 = Wire.read();
      byte msb2 = Wire.read();
      byte lsb2 = Wire.read();
      byte crc = Wire.read();
// Verify CRC
      byte crc_calc = (msb1 + lsb1 + msb2 + lsb2) & 0xFF;
      if (crc == crc_calc) {
        // Calculate temperature
        temperature = (((msb1 << 8) | lsb1) * 200.0) / 1048576.0 - 50.0;

        // Calculate humidity
        humidity = (((msb2 << 8) | lsb2) * 100.0) / 1048576.0;

        return true;
      }
      else {
        Serial.println("CRC error!");
        return false;
      }
    }
    else {
      Serial.println("No response from AHT20");
      return false;
    }
  }
  void TnH::displayTnH(){
   //  objTnH.beginTransmission();
 // if (objTnH.readResponse(temperature,humidity)) {
    beginTransmission();
    if (readResponse(temperature,humidity)) {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C, Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  delay(2000);
  }
  