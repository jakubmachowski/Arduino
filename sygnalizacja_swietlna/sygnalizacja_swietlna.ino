int t = 300; // Definiowanie czasu delay.
void setup() {
  pinMode(10, OUTPUT); //Dioda czerwona
  pinMode(9, OUTPUT); //Dioda żółta
  pinMode(8, OUTPUT); //Dioda zielona
 
  pinMode(7, INPUT_PULLUP); //Przycisk
 
  digitalWrite(10, LOW); //Wyłączenie diod
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
}
 
void loop()
{
  digitalWrite(10, LOW); //Czerwona
  digitalWrite(9, LOW); //Pomarańczowa
  digitalWrite(8, HIGH); //Zielona
 
  delay(t); //Zatrzymujemy program przed wejsciem do pętli na 1 sekunde
  while (digitalRead(7) == HIGH) {} //Jeśli przycisk jest wciśnięty 
 
  digitalWrite(10, LOW); //Czerwona
  digitalWrite(9, HIGH); //Pomarańczowa
  digitalWrite(8, LOW); //Zielona
 
  delay(t); //Zatrzymujemy program przed wejsciem do pętli na 1 sekunde
  while (digitalRead(7) == HIGH) {} //Jeśli przycisk jest wciśnięty 
 
  digitalWrite(10, HIGH); //Czerwona
  digitalWrite(9, LOW); //Pomarańczowa
  digitalWrite(8, LOW); //Zielona
 
  delay(t); //Zatrzymujemy program przed wejsciem do pętli na 1 sekunde
  while (digitalRead(7) == HIGH) {} //Jeśli przycisk jest wciśnięty 
 
  digitalWrite(10, HIGH); //Czerwona
  digitalWrite(9, HIGH); //Pomarańczowa
  digitalWrite(8, LOW); //Zielona
 
  delay(t); //Zatrzymujemy program przed wejsciem do pętli na 1 sekunde
  while (digitalRead(7) == HIGH) {} //Jeśli przycisk jest wciśnięty 
}
