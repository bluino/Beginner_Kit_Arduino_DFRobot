//Project 15 - digital tube display

void setup(){
  for(int pin = 2 ; pin <= 9 ; pin++){    // define digital pin 2-9 as output
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH); 
  }
}

void loop() {
  // display number 0
  int n0[8]={0,0,0,1,0,0,0,1};
  //display the array of n0[8] in digital pin 2-9
  for(int pin = 2; pin <= 9 ; pin++){ 
    digitalWrite(pin,n0[pin-2]);
  }
  delay(500);
  
  // display number1
  int n1[8]={0,1,1,1,1,1,0,1};
  // display the array of n1[8] in digital pin 2-9
  for(int pin = 2; pin <= 9 ; pin++){ 
    digitalWrite(pin,n1[pin-2]);
  }
  delay(500);
  
  // display number 2
  int n2[8]={0,0,1,0,0,0,1,1};
  // display the array of n2[8] in digital pin 2-9
  for(int pin = 2; pin <= 9 ; pin++){ 
    digitalWrite(pin,n2[pin-2]);
  }
  delay(500);
  
  // display number 3
  int n3[8]={0,0,1,0,1,0,0,1};
  // display the array of n3[8] in digital pin 2-9
  for(int pin = 2; pin <= 9 ; pin++){ 
    digitalWrite(pin,n3[pin-2]);
  }
  delay(500);
  
  // display number 4
  int n4[8]={0,1,0,0,1,1,0,1};
  // display the array of n4[8] in digital pin 2-9
  for(int pin = 2; pin <= 9 ; pin++){ 
    digitalWrite(pin,n4[pin-2]);
  }
  delay(500);

  // display number 5
  int n5[8]={1,0,0,0,1,0,0,1};
  // display the array of n5[8] in digital pin 2-9
  for(int pin = 2; pin <= 9 ; pin++){ 
    digitalWrite(pin,n5[pin-2]);
  } 
  delay(500);

  // display number 6
  int n6[8]={1,0,0,0,0,0,0,1};
  //display the array of n6[8] in digital pin 2-9
  for(int pin = 2; pin <= 9 ; pin++){ 
    digitalWrite(pin,n6[pin-2]);
  }
  delay(500);

  // display number 7
  int n7[8]={0,0,1,1,1,1,0,1};
  // display the array of n7[8] in digital pin 2-9
  for(int pin = 2; pin <= 9 ; pin++){ 
    digitalWrite(pin,n7[pin-2]);
  } 
  delay(500);

  // display number 8
  int n8[8]={0,0,0,0,0,0,0,1};
  // display the array of n8[8] in digital pin 2-9
  for(int pin = 2; pin <= 9 ; pin++){ 
    digitalWrite(pin,n8[pin-2]);
  } 
  delay(500);

  // display number 9
  int n9[8]={0,0,0,0,1,1,0,1};
  // display the array of n9[8] in digital pin 2-9
  for(int pin = 2; pin <= 9 ; pin++){ 
    digitalWrite(pin,n9[pin-2]);
  }
  delay(500); 
}
