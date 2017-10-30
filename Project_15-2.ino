//Item 11 - digital tube digital display

int number[10][8] = {
  {0,0,0,1,0,0,0,1},    //display 0 
  {0,1,1,1,1,1,0,1},    //display 1 
  {0,0,1,0,0,0,1,1},    //display 2 
  {0,0,1,0,1,0,0,1},    //display 3 
  {0,1,0,0,1,1,0,1},    //display 4 
  {1,0,0,0,1,0,0,1},    //display 5 
  {1,0,0,0,0,0,0,1},    //display 6 
  {0,0,1,1,1,1,0,1},    //display 7 
  {0,0,0,0,0,0,0,1},    //display 8 
  {0,0,0,0,1,1,0,1}     //display 9
};

void numberShow(int i){     //call this function to display numbers
  for(int pin = 2; pin <= 9 ; pin++){ 
    digitalWrite(pin, number[i][pin - 2]);
  } 
}

void setup(){
  for(int pin = 2 ; pin <= 9 ; pin++){  // define digital pins 2 to 9 as output
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH); 
  }
}

void loop() {
  for(int j = 0; j <= 9 ; j++){
    numberShow(j);   // call numberShow() function todisplay 0-9.
    delay(500); }
}
