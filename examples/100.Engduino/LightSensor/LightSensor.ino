// Light sensor demo
// There is no include file for this sensor. The value is read
// directly from an analog pin
//
#include <EngduinoLEDs.h>
#include <EngduinoLight.h>

void setup() {
  EngduinoLEDs.begin();
  EngduinoLight.begin();
}

void loop()
{ 
  int l;

  // There are two ways of reading the light level
  // 1) Using the library
  //
  l = EngduinoLight.lightLevel();
  Serial.print("Light value: ");
  Serial.println(l);

  // 2) Directly, by reading the analogue input from the
  // light sensor
  //
  l = analogRead(4);
  Serial.print("Light level: ");
  Serial.println(l);
  
  // The result is a 10 bit value - so in a range 0-1023
  // If we spread this between our 16 LEDs evenly, it means
  // we have to divide the value obtained by 64 to tell us
  // what the biggest numbered LED we have to light should be
  //
  int lightTo = l/64;
  for (int i = 0; i < lightTo; i++) {
    EngduinoLEDs.setLED(i, WHITE, 3);
  }
  for (int i = lightTo; i < 16; i++) {
    EngduinoLEDs.setLED(i, OFF);
  }
}
