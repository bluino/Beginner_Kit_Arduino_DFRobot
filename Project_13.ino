//Project thirteen - the Arduino to control fan operation

int buttonPin = 2;          // int buttonPin = 2;
int relayPin = 3;           // int relayPin = 3;
int relayState = HIGH;      // int relayState = HIGH;
int buttonState;            // record the current button state
int lastButtonState = LOW;  // record the last button state
long lastDebounceTime = 0; 
long debounceDelay = 50;    // eliminate debounce time

void setup() { 
  pinMode(buttonPin, INPUT); 
  pinMode(relayPin, OUTPUT);
  
  digitalWrite(relayPin, relayState);   // configure the initial state of relay
}

void loop() {
  int reading = digitalRead(buttonPin); //read the value of button
  
  // once detects change of state, record time
  if (reading != lastButtonState) { 
    lastDebounceTime = millis();
  }
  
  // wait for 50ms to evaluate if it is the same state as last state
  // if different, change the button state
  // if the state of button is high(pressed), change the state of relay
  if ((millis() - lastDebounceTime) > debounceDelay) { 
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) { 
        relayState = !relayState;
      } 
    }
  }
  digitalWrite(relayPin, relayState);
  
  //change the last state of button
  lastButtonState = reading; 
}
