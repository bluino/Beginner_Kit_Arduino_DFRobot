//Project 10 Servo

#include <Servo.h>    //declare to insert Servo.h library 

Servo myservo;        //create servo object to control a servo 
int pos = 0;          //variable pos to store position of servo

void setup() {
  myservo.attach(9);  //attach the servo to digital pin 9.
}

void loop() {
  for(pos = 0; pos < 180; pos += 1){  //servo turns from 0 to 180 in steps of 1 degree
    myservo.write(pos);   //tell servo to go to position in variable 'pos' 
    delay(15);            //wts 15ms for the servo to reach the position
  }
  for(pos = 180; pos>=1; pos-=1) {  // servo turns from 180 to 0 in steps of 1 degree
    myservo.write(pos);   //tell servo to go to position in variable 'pos'
    delay(15);            //waits 15ms for the servo to reach the position 
  }
}
