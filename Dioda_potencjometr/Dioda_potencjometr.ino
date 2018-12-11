int diodaPin = 12; // Pin cyfrowy na którym jest dioda.
int potPin = 0; // Przypisujemy do zmiennej numer wejścia analogowego - potencjometr.
int pot; // Zmienna w której będziemy zapisywać "wartość" potencjometru.
int przerwa; // Zmienna w której będziemy zapisywać szybkość migania.

void setup() {
  pinMode(diodaPin, OUTPUT); // Ustawienie diody na wyjście.
}

void loop() {
  pot = analogRead(potPin); // Odczytujemy A0 i zapisujemy w zmiennej pot.

  /*
  Wykorzystana niżej funkcja map() służy do przeliczenia jednego zakresu liczb
  na inny. W naszym wypadku przeliczy liczby z zakresu od 0 do 1023 (wartość
  odczytana z A0), na liczby z zakresu od 50 do 3000 (odstęp między zapalaniem
  i gaszeniem diody). Przeliczony zakres liczb zostanie zapisany w zmiennej przerwa.
  */

  przerwa = map(pot, 0, 1023, 50, 3000); // Wyliczenie przerwy.

  digitalWrite(diodaPin, HIGH); // Ustawienie stanu wysokiego (5V).
  delay(przerwa); // Przerwa zależna od położenia potencjometru.
  digitalWrite(diodaPin, LOW); // Ustawienie stanu niskiego (0V).
  delay(przerwa); // Przerwa zależna od położenia potencjometru.
}
