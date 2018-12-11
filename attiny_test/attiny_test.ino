
void setup() {
  pinMode(3, OUTPUT); // Dioda jako wyjście.
  digitalWrite(3, LOW); // Wyłączenie diody na start.
}
 
void loop() {
    digitalWrite(3, HIGH); // Włącz diodę.
    delay(1000);
    digitalWrite(3, LOW); // Wyłącz diodę.
    delay(1000);
  }
