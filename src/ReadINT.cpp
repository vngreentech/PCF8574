#include <Arduino.h>
#include <PCF8574.h>
#include <Wire.h>

PCF8574 pcf8574(0x20);

int dataRead;

void setup() 
{
  Serial.begin(115200);
  pcf8574.begin();

  pcf8574.write(0, LOW);
  pcf8574.write(1, LOW);
  pcf8574.write(2, LOW);
  pcf8574.write(3, LOW);

  pinMode(5, INPUT_PULLUP); //INT

}

void loop() 
{  
  if(digitalRead(5) == 0)
  {
    dataRead = pcf8574.readButton(7);

    if(dataRead == 0)
    {
      pcf8574.write(0, HIGH);
      pcf8574.write(1, HIGH);
      pcf8574.write(2, HIGH);
      pcf8574.write(3, HIGH);
    }
    else
    {
      pcf8574.write(0, LOW);
      pcf8574.write(1, LOW);
      pcf8574.write(2, LOW);
      pcf8574.write(3, LOW);
    }
    Serial.print(" - - - Button read: "); Serial.println(dataRead);
  }

  Serial.print("INT: "); Serial.println(digitalRead(5));
  delay(100);
}