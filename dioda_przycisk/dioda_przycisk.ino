int diodaPin = 3;
int button = 7;

void setup() {
  pinMode(diodaPin, OUTPUT); // Dioda jako wyjście.
  pinMode(button, INPUT_PULLUP); // Przycisk jako wejście.
  digitalWrite(diodaPin, LOW); // Wyłączenie diody na start.
}
 
void loop() {
  if (digitalRead(button) == LOW) { // Jeśli przycisk wciśnięty.
    digitalWrite(diodaPin, HIGH); // Włącz diodę.
  } else { // Jeśli warunek nie został spełniony (przycisk nie jest wciśnięty).
    digitalWrite(diodaPin, LOW); // Wyłącz diodę.
  }
}
