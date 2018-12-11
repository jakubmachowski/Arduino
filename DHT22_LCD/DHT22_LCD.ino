#include <dht.h>
#include <Wire.h> // Standardowa biblioteka Arduino.
#include <LiquidCrystal_I2C.h> // Dołączenie pobranej biblioteki I2C dla LCD.

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Ustawienie adresu układu na 0x27.

/* Ikona termometru */
byte tempIcon[] = {
  B00100,
  B01010,
  B01010,
  B01110,
  B01110,
  B11111,
  B11111,
  B01110
};

/* Ikona kropli wody */
byte wilIcon[] = {
  B00100,
  B00100,
  B01010,
  B01010,
  B10001,
  B10001,
  B10001,
  B01110
};

/* Ikona stopni Celsjusa */
byte stpIcon[] = {
  B01000,
  B10100,
  B01000,
  B00011,
  B00100,
  B00100,
  B00011,
  B00000
};
 
dht DHT22;
#define DHT22PIN 2 //Przypisanie pinu 2 Arduino jako odczyt z sensora
#define L 13 //Przypisanie pinu 13 (diody LED wbudowanej w Arduino)
 
void setup() { 
  lcd.begin(16,2); //Inicjalizacja LCD 16x2, lub 20x4.
  lcd.createChar(1, tempIcon); //Konstruowanie ikony
  lcd.createChar(2, stpIcon); //Konstruowanie ikony
  lcd.createChar(3, wilIcon); //Konstruowanie ikony
  pinMode(L, OUTPUT); //Ustawienie jako wyjście
}
 
void loop() {
  digitalWrite(L, HIGH);
  int chk = DHT22.read(DHT22PIN); //Sprawdzenie stanu sensora, a następnie wyświetlenie komunikatu na monitorze szeregowym
  lcd.setCursor(0,0);
  lcd.write(byte(1));
  lcd.setCursor(2,0);
  lcd.print((float)DHT22.temperature, 1);
  lcd.setCursor(6,0);
  lcd.write(byte(2));
  lcd.setCursor(9,0);
  lcd.write(byte(3));
  lcd.setCursor(11,0);
  lcd.print((float)DHT22.humidity, 1);
  lcd.setCursor(15,0);
  lcd.print("%");
  digitalWrite(L, LOW);
  delay(1000);
}
