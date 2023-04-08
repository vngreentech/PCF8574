#include <Arduino.h>
#include <PCF8574.h>
#include <Wire.h>

PCF8574 pcf8574(0x24);

void setup() 
{
  Serial.begin(115200);

  pcf8574.begin();

}

void loop() 
{  
  Serial.print("Button read: "); Serial.println(pcf8574.read8(), HEX);

  delay(20);
}