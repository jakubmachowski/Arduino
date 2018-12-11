void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(8, 500);
  delay(500);
  tone(8, 2000);
  delay(500);
}
