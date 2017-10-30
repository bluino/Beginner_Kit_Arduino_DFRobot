// Project 4

int ledPin = 10;

void setup() { 
  pinMode(ledPin,OUTPUT);
}

void loop(){ 
  fadeOn(1000,5);
  fadeOff(1000,5); 
}

void fadeOn(unsigned int time,int increament){
  for (byte value = 0 ; value < 255; value+=increament){
    analogWrite(ledPin, value); 
    delay(time/(255/5));
  }
}

void fadeOff(unsigned int time,int decreament){
  for (byte value = 255; value >0; value-=decreament){
    analogWrite(ledPin, value); 
    delay(time/(255/5));
  }
}
