//The second project -- S.O.S signal

int ledPin = 10;

void setup() {
    pinMode(ledPin, OUTPUT);
}

void loop() {
  //3 quick blinks to represent “S” again
  for(int x=0;x<3;x++){
    digitalWrite(ledPin,HIGH);      //configure LED on
    delay(150);                     //delay 150 milliseconds
    digitalWrite(ledPin,LOW);       //configure LED off
    delay(100);                     //delay 100 milliseconds
  }

  //100 milliseconds delay between of each letter
  delay(100);

  //3 quick blinks to represent “O”
  for(int x=0;x<3;x++){
    digitalWrite(ledPin,HIGH);      //configure LED on
    delay(400);                     //delay 400 milliseconds
    digitalWrite(ledPin,LOW);       //configure LED off
    delay(100);                     //delay 100 milliseconds
  }

  //100 milliseconds delay between of each letter
  delay(100);

  // 3 quick blinks to represent “S” again
  for(int x=0;x<3;x++){
    digitalWrite(ledPin,HIGH);      //configure LED on
    delay(150);                     // delay 150 milliseconds
    digitalWrite(ledPin,LOW);       //configure LED off
    delay(100);                     //delay 100 milliseconds
  }

  // wait 5 seconds to repeat the next S.O.S signal
  delay(5000);
};
