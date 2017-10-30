//PROJECT 5 RGB LED

int redPin = 9;
int greenPin = 10; 
int bluePin = 11;

void setup(){
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT);
}

void loop(){
  //R:0-255 G:0-255 B:0-255 
  colorRGB(random(0,255),random(0,255),random(0,255)); 
  delay(1000);
}

void colorRGB(int red, int green, int blue){ 
  analogWrite(redPin,constrain(red,0,255)); 
  analogWrite(greenPin,constrain(green,0,255)); 
  analogWrite(bluePin,constrain(blue,0,255));
}
