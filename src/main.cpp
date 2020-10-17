// NOM DU PROGRAMME : SondeTemperature_PROTOTYPE
// REALISATION INFORMATIQUE : Mathieu Lepage
// DATE DE CREATION : 2020/10/16
// OBJET : Programme test permettant d'afficher les températures captées par la sonde

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
 
// La pin GPIO de connexion
const int oneWireBus = 4;
 
// Initialisation d'une instance onewire
OneWire oneWire(oneWireBus);
 
// Passer la référence au sensor Dallas Temperature
DallasTemperature sensors(&oneWire);
 
void setup()
{
Serial.begin(9600);
// Start le sensor
sensors.begin();
}
void loop()
{
  // On appelle la requète de température sensors.requestTemperatures()
  sensors.requestTemperatures(); 
  Serial.print("Celsius temperature: ");
  // Le "byIndex" permet d'avoir plus qu'une IC sur le même bus. 0 réfère au premier IC sur le wire
  // Ici on record la température en celcius
  Serial.print(sensors.getTempCByIndex(0)); 
  Serial.print(" - Fahrenheit temperature: ");
  // Ici on record la température en fahrenheit
  Serial.println(sensors.getTempFByIndex(0));
  delay(1000);
}