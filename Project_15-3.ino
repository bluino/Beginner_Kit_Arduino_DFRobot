// Project 13 - IR Remote Controlled LED Module

#include <IRremote.h>     //Call IRremote.h Library.

int RECV_PIN = 11;        //Dim RECV_PIN as 11
IRrecv irrecv(RECV_PIN);  //Set RECV_PIN (Pin-out 11) as the IR receiver port. 
decode_results results;   //Set results as the IR records storage position.
int currentNumber = 0;    //The variable is for current number storage.

long codes[12]= {  //The array is for IR codes storage delivered bythe IR remote controller.
  0xFD30CF,0xFD08F7,    // 0 ,1 
  0xFD8877,0xFD48B7,    // 2 ,3
  0xFD28D7,0xFDA857,    // 4 ,5
  0xFD6897,0xFD18E7,    // 6 ,7
  0xFD9867,0xFD58A7,    // 8 ,9
  0xFD20DF,0xFD609F,    // + ,-
};

int number[10][8] = {  //The array is for numbers storage displayed on the LED module.
  {0,0,0,1,0,0,0,1},  //0 
  {0,1,1,1,1,1,0,1},  //1 
  {0,0,1,0,0,0,1,1},  //2 
  {0,0,1,0,1,0,0,1},  //3 
  {0,1,0,0,1,1,0,1},  //4 
  {1,0,0,0,1,0,0,1},  //5 
  {1,0,0,0,0,0,0,1},  //6 
  {0,0,1,1,1,1,0,1},  //7 
  {0,0,0,0,0,0,0,1},  //8 
  {0,0,0,0,1,1,0,1},  //9
};

void numberShow(int i) {    //The function works to display numbers on the LED module.
  for(int pin = 2; pin <= 9 ; pin++){ 
    digitalWrite(pin, number[i][pin - 2]); 
  }
}

void setup(){
  Serial.begin(9600);   //Set the baud rate as 9600. 
  irrecv.enableIRIn();  //Launch IR decoding.
  for(int pin = 2 ; pin <= 9 ; pin++){ //Set Pin-out 2 to 9 as output mode. 
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
}

void loop() {
//Evaluate whether decoding data are received and store the data in variable results.
  if (irrecv.decode(&results)) { 
    for(int i = 0; i <= 11; i++){
      //Evaluate whether IR codes are received of press button 0 to 9.
      if(results.value == codes[i]&& i <= 9){
        numberShow(i); //Display 0 to 9 on corresponding position of the LED module.
        currentNumber = i; //Assign value displayed to variable currentNumber.
        Serial.println(i);
        break; 
      }

      // /Evaluate whether decreasing IR codes are received and the current value is not 0.
      else if(results.value == codes[10]&& currentNumber != 0){ 
        currentNumber--;  //Decrease current value. 
        numberShow(currentNumber);  //The LED module displays decreasing value.
        Serial.println(currentNumber);  //The serial port outputs decreasing value.
        break; 
      }
  
      //Evaluate whether decreasing IR codes are received and current value is not 9.
      else if(results.value == codes[11]&& currentNumber != 9){
        currentNumber++;                //Current value increases.
        numberShow(currentNumber);      //The LED module displays increasing value.
        Serial.println(currentNumber);  //The serial port outputs increasing value.
        break; 
      }
    }
 
    Serial.println(results.value, HEX); //View IR codes via serial port monitor.
    irrecv.resume();  //Wait for next signal.
  }
}
