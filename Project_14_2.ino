#include <IRremote.h>     

int RECV_PIN = 11;        
int ledPin = 10;          //LED – digital 10
boolean ledState = LOW;   // ledState to store the state of LED
IRrecv irrecv(RECV_PIN);  
decode_results results;   

void setup(){ 
  Serial.begin(115200);
  irrecv.enableIRIn();
  pinMode(ledPin,OUTPUT);   // define LED as output signal
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);

    //once receive code from power button, the state of LED is changed from HIGH to LOW or from LOW to HIGH.
    if(results.value == 0xFD00FF){ 
      ledState = !ledState;           //reverse
      digitalWrite(ledPin,ledState);  //change the state of LED
    }
    irrecv.resume();
  }
}
