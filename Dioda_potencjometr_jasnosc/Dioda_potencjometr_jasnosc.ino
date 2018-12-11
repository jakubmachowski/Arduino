int odczytanaWartosc = 0; //Zmienna do przechowywania odczytu ADC
 
void setup() {
  pinMode(2, OUTPUT); //Konfiguracja wyjść pod diodę LED
}
 
void loop() {
  odczytanaWartosc = analogRead(A5);//Odczytanie wartości z ADC
  digitalWrite(2, HIGH);//Włączenie diody
  delay(odczytanaWartosc);//Uzależnienie czasu oczekiwania od ADC
  digitalWrite(2, LOW);//Wyłączenie diody
  delay(odczytanaWartosc);//Uzależnienie czasu oczekiwania od ADC 
}
