#include <LiquidCrystal.h>

/*
 * LiquidCrystal(rs, enable, d4, d5, d6, d7) 
 * rs: the number of the Arduino pin that is connected to the RS pin on the LCD
 * rw: the number of the Arduino pin that is connected to the RW pin on the LCD (optional)
 * enable: the number of the Arduino pin that is connected to the enable pin on the LCD
 * d0, d1, d2, d3, d4, d5, d6, d7: the numbers of the Arduino pins that are connected to the corresponding data pins on the LCD. d0, d1, d2, and d3 are optional; if omitted, the LCD will be controlled using only the four data lines (d4, d5, d6, d7).
*/ 
LiquidCrystal lcd(6,7,5,4,3,2);


// Defining pins for note inputs
int aPin = 8;
int bPin = 9;
int cPin = 10;
int dPin = 11;
int ePin = 12;

// Declaring control variable
char command;

// Setting the duration of a note, in seconds
float noteDuration = 0.5;

// Setting time to display result message, in seconds
float resultDelay = 10;

// Setting replay wait time, in seconds
float replay = 10;

// Declaring game variables
float score;
long timeTaken;
long startPressed;
long endPressed;
int buttonState;
int lastButtonState;
char scoreStr[9];

void setup() {
  //  Opening channel at 9600 Baud
  Serial.begin(9600);

  // Starting LCD
  lcd.begin(16,2);
  lcd.print("Initializing...");

  // Setting pin modes
  pinMode(aPin, INPUT);
  pinMode(bPin, INPUT);
  pinMode(cPin, INPUT);
  pinMode(dPin, INPUT);
  pinMode(ePin, INPUT);
  
  // Resetting score
  score = 0.0;
}

void loop() {
  Serial.flush();
  if(Serial.available())
  {
   char command = Serial.read();
   Serial.println(command);
   
   lcd.clear();
   if(command == 'S')
   {
      // Displaying game over message
      lcd.print("GAME OVER!");
      lcd.setCursor(0,1);
      lcd.print("Calculating Scores...");

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
      Serial.println(command);
      if(command == '1')
      {
        lcd.clear();
        lcd.print("You Won!");
        lcd.setCursor(0,1);
        lcd.print("Score: ");
        lcd.print(score);
      }
      else if(command == '2')
      {
        lcd.clear();
        lcd.print("You lost...");
        lcd.setCursor(0,1);
        lcd.print("Score: ");
        lcd.print(score);
      }
      else
      {
        lcd.clear();
        lcd.print("It was a tie!");
        lcd.setCursor(0,1);
        lcd.print("Score: ");
        lcd.print(score);
      }
  
      delay(resultDelay*1000);
      
      for (int i = replay; i>=0; i--)
      {
        lcd.clear();
        lcd.print("New game starting in ");
        lcd.print(i);
        lcd.print(" seconds");
        delay(1000);
      }
      
      // Reseting game
      score = 0.0;
      strcpy(scoreStr, "");
   }
   else
   {
      switch(command)
      {
        case 'A':
          lcd.print("A");
          // Recording time taken
          startPressed = millis();
          lastButtonState = LOW;
  
          while(true)
          {
            buttonState = digitalRead(aPin);
            endPressed = millis();
  
            timeTaken = endPressed - startPressed;
        
            if (timeTaken >= 1.3*noteDuration*1000) {
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
            break;
        case 'B':
          lcd.print("B");
          // Recording time taken
          startPressed = millis();
          lastButtonState = LOW;
  
          while(true)
          {
            buttonState = digitalRead(bPin);
            endPressed = millis();
  
            timeTaken = endPressed - startPressed;
        
            if (timeTaken >= 1.3*noteDuration*1000) {
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
            break;
         case 'C':
          lcd.print("C");  
          // Recording time taken
          startPressed = millis();
          lastButtonState = LOW;
  
          while(true)
          {
            buttonState = digitalRead(cPin);
            endPressed = millis();
  
            timeTaken = endPressed - startPressed;
        
            if (timeTaken >= 1.3*noteDuration*1000) {
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
            break;
        case 'D':
          lcd.print("D");
          // Recording time taken
          startPressed = millis();
          lastButtonState = LOW;
  
          while(true)
          {
            buttonState = digitalRead(dPin);
            endPressed = millis();
  
            timeTaken = endPressed - startPressed;
        
            if (timeTaken >= 1.3*noteDuration*1000) {
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
            break;
        case 'E':
          lcd.print("E");  
          // Recording time taken
          startPressed = millis();
          lastButtonState = LOW;
  
          while(true)
          {
            buttonState = digitalRead(ePin);
            endPressed = millis();
  
            timeTaken = endPressed - startPressed;
        
            if (timeTaken >= 1.3*noteDuration*1000) {
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
            break;
  //      case 'F':
  //        lcd.print("F");
  //        timeTaken = pulseIn(ePin, LOW, 1.3*noteDuration*1000);
  //        break;
  //      case 'G':
  //        lcd.print("G");
  //        timeTaken = pulseIn(ePin, LOW, 1.3*noteDuration*1000);
  //        break;
      }
      
      // Adding to score
      score += timeTaken;
   }
 }
}
