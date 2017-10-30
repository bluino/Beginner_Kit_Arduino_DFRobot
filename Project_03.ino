// PROJECT 3 Interactive Traffic Light

int carRed = 12;      //configure traffic light
int carYellow = 11;
int carGreen = 10;
int button = 9;       //pin of button
int pedRed = 8;       //configure light for pedestrians
int pedGreen = 7;
int crossTime = 5000; //time for pedestrians to pass 
unsigned long changeTime; //time that the button is pressed

void setup() {
  //configure all LEDs as output
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);
  pinMode(pedRed, OUTPUT);
  pinMode(pedGreen, OUTPUT);
  pinMode(button, INPUT); //configure button as inputlight on
  digitalWrite(carGreen, HIGH); //initialize green traffic digitalWrite(pedRed, LOW); //initialize red pedestrian light off }
}
  
void loop() {
  int state = digitalRead(button);
  // test if the button is pressed and if 5 seconds have passed after it is pressed lately.
  if(state == HIGH && (millis() - changeTime)> 5000){
    //carry out the function of changing LED
    changeLights();
  }
} 

void changeLights() {
  digitalWrite(carGreen, LOW);    //green traffic light off
  digitalWrite(carYellow, HIGH);  //yellow traffic light on 
  delay(2000);                    //wait for 2 secs
  
  digitalWrite(carYellow, LOW);   //yellow traffic light off
  digitalWrite(carRed, HIGH);     //red traffic light on
  delay(1000);                    //wait for 1 sec for safety reason
  
  digitalWrite(pedRed, LOW);      //red pedestrian light off
  digitalWrite(pedGreen, HIGH);   //light pedestrian light on
  delay(crossTime);               // time for crossing street 

  //blink green pedestrian light to notify pedestrians to pass soon
  for (int x=0; x<10; x++) { 
    digitalWrite(pedGreen, HIGH);
    delay(250); 
    digitalWrite(pedGreen, LOW);
    delay(250);
  }
  digitalWrite(pedRed, HIGH);       //red pedestrian light on
  delay(500);
  
  digitalWrite(carRed, LOW);        //red traffic light off 
  digitalWrite(carYellow, HIGH);    //yellow traffic light on
  delay(1000); 
  digitalWrite(carYellow, LOW);     //yellow traffic light off
  digitalWrite(carGreen, HIGH);     //green traffic light on

  changeTime = millis();            //record the duration since last change
                                    //back to the loop of main code
}

