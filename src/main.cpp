#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
 
//la pin GPIO de connexion
const int oneWireBus = 4;
 
//initialisation d'une instance onewire
OneWire oneWire(oneWireBus);
 
//passer la référence au sensor Dallas Temperature
DallasTemperature sensors(&oneWire);
 
void setup()
{
Serial.begin(9600);
//start le sensor
sensors.begin();
}
void loop()
{
  // On appelle la requète de température sensors.requestTemperatures()
  sensors.requestTemperatures(); 
  Serial.print("Celsius temperature: ");
  // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
  Serial.print(sensors.getTempCByIndex(0)); 
  Serial.print(" - Fahrenheit temperature: ");
  Serial.println(sensors.getTempFByIndex(0));
  delay(1000);
}