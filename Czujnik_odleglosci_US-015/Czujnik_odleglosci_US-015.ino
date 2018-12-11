#include <Wire.h> // Standardowa biblioteka Arduino.
#include <LiquidCrystal_I2C.h> // Dołączenie pobranej biblioteki I2C dla LCD.

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Ustawienie adresu układu na 0x27.

int Trig = 2;  //pin 2 Arduino połączony z pinem Trigger czujnika
int Echo = 3;  //pin 3 Arduino połączony z pinem Echo czujnika
int CM;        //odległość w cm
long CZAS;     //długość powrotnego impulsu w uS
  
void setup()
{
  Serial.begin(9600);                        //inicjalizaja monitora szeregowego
  pinMode(Trig, OUTPUT);                     //ustawienie pinu 2 w Arduino jako wyjście
  pinMode(Echo, INPUT);                      //ustawienie pinu 3 w Arduino jako wejście
    
  lcd.begin(16,2); // Inicjalizacja LCD 16x2, lub 20x4.
  lcd.backlight(); // Załączenie podświetlenia .
}
   
void loop()
{
  pomiar_odleglosci();              //pomiar odległości
  /*Serial.print("Odleglosc: ");      //wyświetlanie wyników na ekranie w pętli co 200 ms
  Serial.print(CM);
  Serial.println(" cm");*/
    
  lcd.setCursor(0,0); // Ustawienie kursora w pozycji 0,0 (pierwszy wiersz, pierwsza kolumna).
  lcd.print("Odl: ");
  lcd.setCursor(0,1); //Ustawienie kursora w pozycji 0,0 (drugi wiersz, pierwsza kolumna).
  lcd.print(CM);
  lcd.print(" cm");
  delay(500);
}
   
void pomiar_odleglosci ()
{
  digitalWrite(Trig, LOW);        //ustawienie stanu wysokiego na 2 uS - impuls inicjalizujacy - patrz dokumentacja
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);       //ustawienie stanu wysokiego na 10 uS - impuls inicjalizujacy - patrz dokumentacja
  delayMicroseconds(15);
  digitalWrite(Trig, LOW);
  digitalWrite(Echo, HIGH); 
  CZAS = pulseIn(Echo, HIGH);
  CM = CZAS / 58;                //szerokość odbitego impulsu w uS podzielone przez 58 to odleglosc w cm - patrz dokumentacja
}
