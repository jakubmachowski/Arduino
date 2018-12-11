#include <OneWire.h>
#include <DallasTemperature.h>
 
OneWire oneWire(10); //Podłączenie do A5
DallasTemperature sensors(&oneWire); //Przekazania informacji do biblioteki
 
void setup(void) {
  Serial.begin(9600);
  sensors.begin(); //Inicjalizacja czujnikow
}
 
void loop(void) { 
  sensors.requestTemperatures(); //Pobranie temperatury czujnika
  Serial.print("Aktualna temperatura: ");
  Serial.println(sensors.getTempCByIndex(0));  //Wyswietlenie informacji
  delay(500);
}
