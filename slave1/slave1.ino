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

// Declaring control string and buffer length
int recvBufferLength = 10;
char command[10];

// Setting timeout for score calculation, in seconds
float timeout = 0.3;

// Setting time between two notes, in seconds
float noteDelay = 5;

// Setting time to display result message, in seconds
float resultDelay = 10;

// Setting replay wait time, in seconds
float replay = 10;

// Declaring game variables
int score;
int timeTaken;

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
  score = 0;
}

void loop() {
 Serial.readBytes(command, recvBufferLength);
 lcd.clear();
 if(strcmp(command, "STOP")==0)
 {
    // Displaying game over message
    lcd.print("GAME OVER!");
    lcd.setCursor(0,1);
    lcd.print("Calculating Scores...");
    
    Serial.write(score);
    delay(timeout * 1000);
    Serial.readBytes(command, recvBufferLength);
    if(strcmp(command, "ONE WINS")==0)
    {
      lcd.clear();
      lcd.print("You Won!");
      lcd.setCursor(0,1);
      lcd.print("Score: ");
      lcd.print(score);
    }
    else if(strcmp(command, "TWO WINS")==0)
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
    score = 0;
 }
 else
 {
    switch(command[0])
    {
      case 'A':
        lcd.print("A");
        timeTaken = pulseIn(aPin, LOW, noteDelay*1000);
        break;
      case 'B':
        lcd.print("B");
        timeTaken = pulseIn(bPin, LOW, noteDelay*1000);
        break;
      case 'C':
        lcd.print("C");
        timeTaken = pulseIn(cPin, LOW, noteDelay*1000);
        break;
      case 'D':
        lcd.print("D");
        timeTaken = pulseIn(dPin, LOW, noteDelay*1000);
        break;
      case 'E':
        lcd.print("E");
        timeTaken = pulseIn(ePin, LOW, noteDelay*1000);
        break;
    }

    // Adding to score
    if(timeTaken == 0)
      score += noteDelay*1000;
    score += timeTaken;
 }
}
