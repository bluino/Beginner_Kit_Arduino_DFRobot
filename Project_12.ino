//Sample Code 12-1:

int redPin = 9;       // R – digital 9
int greenPin = 10;    // G – digital 10
int bluePin = 11;     // B – digital 11
int potRedPin = 0;    // potentiometer 1 – analog 0
int potGreenPin = 1;  // potentiometer 2 – analog 1
int potBluePin = 2;   // potentiometer 3 – analog 2

void setup(){ 
  pinMode(redPin,OUTPUT); 
  pinMode(greenPin,OUTPUT); 
  pinMode(bluePin,OUTPUT); 
  Serial.begin(115200);       // Initialize the serial port
}

void loop(){
  int potRed = analogRead(potRedPin);       // read value from potentiometer of red LED
  int potGreen = analogRead(potGreenPin);   // read value from potentiometer of green LED
  int potBlue = analogRead(potBluePin);     // read value from potentiometer of blue LED
  int val1 = map(potRed,0,1023,0,255);      //map the voltage value ranging from 0~1023 to analog value ranging from 0~255
  int val2 = map(potGreen,0,1023,0,255); 
  int val3 = map(potBlue,0,1023,0,255);
  
  // print value of red, green and blues LEDs from serial port
  Serial.print("Red:");
  Serial.print(val1);
  Serial.print("Green:");
  Serial.print(val2);
  Serial.print("Blue:");
  Serial.println(val3);
  colorRGB(val1,val2,val3); // configure the analog value for RGB LED
}

//define the colorRGB function
void colorRGB(int red, int green, int blue){ 
  analogWrite(redPin,constrain(red,0,255)); 
  analogWrite(greenPin,constrain(green,0,255)); 
  analogWrite(bluePin,constrain(blue,0,255));
}
