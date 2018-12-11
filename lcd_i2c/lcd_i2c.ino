#include <Wire.h> // Standardowa biblioteka Arduino.
#include <LiquidCrystal_I2C.h> // Dołączenie pobranej biblioteki I2C dla LCD.

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Ustawienie adresu układu na 0x27.

/*
*  GND - GND
*  VCC - > 5 V
*  SDA -> A4
*  SCL -> A5
*/

void setup()  
{
  lcd.begin(16,2); // Inicjalizacja LCD 2x16.
  lcd.backlight(); // Załączenie podświetlenia .
  lcd.setCursor(0,0); // Ustawienie kursora w pozycji 0,0 (pierwszy wiersz, pierwsza kolumna).
  lcd.print("Jakub Machowski");
  lcd.setCursor(5,1); //Ustawienie kursora w pozycji 0,0 (drugi wiersz, pierwsza kolumna).
  lcd.print("ZOI :)");
  //lcd.cursor(); // Włącznie kursora.
  // lcd.blink(); // Włącznie kursora migającego.
}

void loop() 
{
  /*lcd.noDisplay(); // Wyłącz napis.
  delay(500);
  lcd.display(); // Włącz napis.
  delay(500);

  lcd.noCursor(); // Wyłącz kursor.
  delay(500);
  lcd.cursor(); // Włącz kursor.
  delay(500);*/
}
