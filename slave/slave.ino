// Defining pins for note inputs
int aPin = 8;
int bPin = 9;
int cPin = 10;
int dPin = 11;
int ePin = 12;

// Defining pin for winner indication
int winPin = 4; 

// Declaring control variable
char command;

// Setting the duration of a note, in seconds
float noteDuration = 0.5;

// Setting time to display result message, in seconds
float resultDelay = 10;

// Declaring game variables
float score;
long timeTaken;
char scoreStr[9];
int buttoncount = 0;

long calcScore(int pinno) {
  int buttonState, lastButtonState;
  long startPressed, endPressed, tempTimeTaken;
  startPressed = millis();
  lastButtonState = LOW;
  while(true)
  {
    buttonState = digitalRead(pinno) ? LOW : HIGH;
    endPressed = millis();

    tempTimeTaken = endPressed - startPressed;

    if (tempTimeTaken >= 1.3*noteDuration*1000) {
      break;
    }

    if (buttonState != lastButtonState) {
      if(buttonState == HIGH)
      {
        break;
      }
    }
    lastButtonState = buttonState;
  }
  return(tempTimeTaken);
}


void setup() {
  //  Opening channel at 9600 Baud
  Serial.begin(9600);

  // Setting pin modes
  pinMode(aPin, INPUT_PULLUP);
  pinMode(bPin, INPUT_PULLUP);
  pinMode(cPin, INPUT_PULLUP);
  pinMode(dPin, INPUT_PULLUP);
  pinMode(ePin, INPUT_PULLUP);
  pinMode(winPin, OUTPUT);
  digitalWrite(winPin, LOW);
  
  // Resetting score
  score = 0.0;
}

void loop() {
  Serial.flush();
  if(Serial.available())
  {
    char command = Serial.read();

    if(command == 'S')
    {
    // Displaying game over message

      dtostrf(score, 8, 0, scoreStr);
      while(1){
        while(!Serial.available());
        if(Serial.read() == 'P'){
          Serial.write(scoreStr, 9);
          break;
        }
      }
      
      while(!Serial.available());
      command = Serial.read();
      if(command == '1')
      {
        digitalWrite(winPin, HIGH);
      }
      else if(command == '2')
      {
        digitalWrite(winPin, LOW);
      }
      else
      {
        digitalWrite(winPin, HIGH);
      }

      delay(resultDelay*1000);
            
    // Reseting game
      score = 0.0;
      strcpy(scoreStr, "");
      digitalWrite(winPin, LOW);
    }
    else
    {
      switch(command)
      {
        case 'A':
      // Recording time taken
        timeTaken = calcScore(aPin);
        break;

        case 'B':
      // Recording time taken
        timeTaken = calcScore(bPin);
        break;

        case 'C':
      // Recording time taken
        timeTaken = calcScore(cPin);
        break;

        case 'D':
      // Recording time taken
        timeTaken = calcScore(dPin);
        break;

        case 'E':
      // Recording time taken
        timeTaken = calcScore(ePin);
        break;
        
        default:
        timeTaken = 0;  
        break;
      }
     // Adding to score
      score = score + timeTaken;
    }
  }
} 
