#define LED 3
#define switchPin 7

int counter = 0;

void setup() {
 pinMode(switchPin, INPUT_PULLUP);
 pinMode(LED, OUTPUT);
}

void loop() {
 int switchVal = digitalRead(switchPin);
 if(switchVal == LOW) {
   delay(300);  
   counter ++;
   if(counter == 4) {
     counter = 0;
   }
 } else {
   switch (counter) {
   case 0:
     analogWrite(LED, 10);
     break;
   case 1:
     analogWrite(LED, 50);
     break;
   case 2:
     analogWrite(LED, 150);
     break;
   case 3:
     analogWrite(LED, 200);
     break;
   }
 }
}

