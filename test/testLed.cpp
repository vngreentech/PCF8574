#include <Arduino.h>
#include <PCF8574.h>
#include <Wire.h>

PCF8574 pcf8574(0x20);

String dataRead;

void setup() 
{
  Serial.begin(115200);
  pcf8574.begin();

  pcf8574.write(0, LOW);

}

void loop() 
{  
  dataRead = String(pcf8574.read8(), HEX);

  if(dataRead == "7e") pcf8574.write(0, HIGH);
  else pcf8574.write(0, LOW);

  Serial.print("Button read: "); Serial.println(dataRead);
  delay(10);
}