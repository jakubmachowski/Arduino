#include <dht.h>
 
dht DHT22;
 
#define DHT22PIN 2    //przypisanie pinu 2 Arduino jako odczyt z sensora
 
void setup()
{
  Serial.begin(9600);                    //inicjalizacja monitora szeregowego
  Serial.println("Program testowy DHT22"); 
  Serial.println();
}
 
void loop()
{
  int chk = DHT22.read(DHT22PIN);         //sprawdzenie stanu sensora, a następnie wyświetlenie komunikatu na monitorze szeregowym
 
  Serial.print("Stan sensora: ");
  switch (chk)
  {
    case DHTLIB_OK: 
        Serial.print("OK\t"); 
        break;
    case DHTLIB_ERROR_CHECKSUM: 
        Serial.println("Błąd sumy kontrolnej"); 
        break;
    case DHTLIB_ERROR_TIMEOUT: 
        Serial.println("Koniec czasu oczekiwania - brak odpowiedzi"); 
        break;
    default: 
        Serial.println("Nieznany błąd"); 
        break;
  }
  Serial.print("Wilgotnosc (%): ");              //wyświetlenie wartości wilgotności
  Serial.print((float)DHT22.humidity, 2);
  Serial.print("\t\t");
  Serial.print("Temperatura (C): ");           //wyświetlenie temperatury
  Serial.println((float)DHT22.temperature, 2);
 
  delay(1000);                                  //opóźnienie między kolejnymi odczytami - 1 s
}
