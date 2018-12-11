int odczytanaWartosc = 0;//Odczytana wartość z ADC
float napiecie = 0;//Wartość przeliczona na napięcie w V
 
void setup() {
  Serial.begin(9600);//Uruchomienie komunikacji przez USART
}
 
void loop() {
  odczytanaWartosc = analogRead(A5);//Odczytujemy wartość napięcia
  napiecie = odczytanaWartosc * (5.0/1023.0); //Przeliczenie wartości na napięcie
  Serial.println(napiecie);//Wysyłamy zmierzone napięcie
  delay(200);//Czekamy, aby wygodniej odczytywać wyniki  
}
