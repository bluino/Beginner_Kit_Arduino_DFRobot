//Project eleven controllable servo

#include <Servo.h>    // insert the Servo.h library

Servo myservo;        // create servo object to control servo

int potpin = 0;       // connect potentiometer to digital pin0
int val;              // variable value to read value from analog pin

void setup() { 
  myservo.attach(9);  //Attach the servo on pin 9 to the servo object.
}

void loop() {
  val = analogRead(potpin);   // eads the value of the potentiommeter (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 179);    // scale it to use it with the servo (between 0 and 180)
  myservo.write(val);   // sets the servo position according to the scaled value
  delay(15);            // wait for 15 ms to turn to certain position
}
