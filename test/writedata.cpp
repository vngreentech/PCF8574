#include <Arduino.h>
#include <PCF8574.h>
#include <Wire.h>

PCF8574 pcf8574(0x20);

void setup() 
{
  Serial.begin(115200);
  pcf8574.begin();

  pcf8574.write(0, LOW);
  pcf8574.write(1, LOW);
  pcf8574.write(2, LOW);
  pcf8574.write(3, LOW);
}

void loop() 
{
  pcf8574.write(0, HIGH);
  pcf8574.write(1, HIGH);
  pcf8574.write(2, HIGH);
  pcf8574.write(3, HIGH);
  delay(2000);

  pcf8574.write(0, LOW);
  pcf8574.write(1, LOW);
  pcf8574.write(2, LOW);
  pcf8574.write(3, LOW);
  delay(500);
}