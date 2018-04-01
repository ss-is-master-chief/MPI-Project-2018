#include "pitches.h"
#include <SoftwareSerial.h>

int s2RXPin = 9;
int s2TXPin = 10;

// Declaring a new serial named s2
SoftwareSerial s2(s2RXPin, s2TXPin);

// Setting duration for each note, in seconds
float noteDuration = 0.5;

// Setting time to display result message, in seconds
float resultDelay = 10;

// Setting speaker pin
int speakerPin = 8;

// Defining pins for note indicators
int aOutPin = 2;
int bOutPin = 3;
int cOutPin = 4;
int dOutPin = 5;
int eOutPin = 6;

// Declaring game variables
float score1, score2;
int currentNote;
String noteSequence;

void setup() {
  //  Opening channel at 9600 Baud
  Serial.begin(9600);
  s2.begin(9600);
  currentNote = 0;
  noteSequence = "EEEZEEEZEGCDEZFFFFFEEZEEDEDZGZ";

  // Setting pin modes
  pinMode(aOutPin, OUTPUT);
  pinMode(bOutPin, OUTPUT);
  pinMode(cOutPin, OUTPUT);
  pinMode(dOutPin, OUTPUT);
  pinMode(eOutPin, OUTPUT);

  // To allow slaves to come online
  delay(1000);
  }


void loop() {
  Serial.flush();
  s2.flush();

  // Resetting note indicators
  digitalWrite(aOutPin, LOW);
  digitalWrite(bOutPin, LOW);
  digitalWrite(cOutPin, LOW);
  digitalWrite(dOutPin, LOW);
  digitalWrite(eOutPin, LOW);
  
  if(noteSequence[currentNote] == '\0')
  { 
    // Sending stop signal
    Serial.write('S');
    s2.write('S');
    delay(1000);

    // Getting scores from slaves
    Serial.write('P');
    while(!Serial.available());
    score1 = Serial.parseFloat();
    
    s2.write('P');
    while(!s2.available());
    score2 = s2.parseFloat();
    
    if(score1 < score2){
      Serial.write('1');
      s2.write('2');
    }
    else if (score2 < score1){
      Serial.write('2');
      s2.write('1');
    }
    else{
      Serial.write('T');
      s2.write('T');
    }

    Serial.flush();
    s2.flush();

    delay(resultDelay*1000);
    
    // Resetting game
    currentNote = 0;
  }
  else
  {
   switch(noteSequence[currentNote++])
   {
    case 'A':
      Serial.write('A');
      s2.write('A');
      sing('A', noteDuration);
      break;
    case 'B':
      Serial.write('B');
      s2.write('B');
      sing('B', noteDuration);
      break;
    case 'C':
      Serial.write('C');
      s2.write('C');
      digitalWrite(aOutPin, HIGH);
      sing('C', noteDuration);
      break;    
    case 'D':
      Serial.write('D');
      s2.write('D');
      digitalWrite(bOutPin, HIGH);
      sing('D', noteDuration);
      break;
    case 'E':
      Serial.write('E');
      s2.write('E');
      digitalWrite(cOutPin, HIGH);
      sing('E', noteDuration);
      break;
    case 'F':
      Serial.write('F');
      s2.write('F');
      digitalWrite(dOutPin, HIGH);
      sing('F', noteDuration);
      break;
    case 'G':
      Serial.write('G');
      s2.write('G');
      digitalWrite(eOutPin, HIGH);
      sing('G', noteDuration);
      break;
    default:
      sing('Z', noteDuration);
      break;
   }
  }
}


void sing(char note, float noteDuration)
{  
  if(note=='A'){
    tone(speakerPin, NOTE_A4, 1000*noteDuration);
    delay(noteDuration * 1.3 * 1000);
  }
  else if(note=='B'){
    tone(speakerPin, NOTE_B4, 1000*noteDuration);
    delay(noteDuration * 1.3 * 1000);
  }
   else if(note=='C'){
    tone(speakerPin, NOTE_C4, 1000*noteDuration);
    delay(noteDuration * 1.3 * 1000);
  }
   else if(note=='D'){
    tone(speakerPin, NOTE_D4, 1000*noteDuration);
    delay(noteDuration * 1.3 * 1000);
  }
   else if(note=='E'){
    tone(speakerPin, NOTE_E4, 1000*noteDuration);
    delay(noteDuration * 1.3 * 1000);
  }
  else if(note=='F'){
    tone(speakerPin, NOTE_F4, 1000*noteDuration);
    delay(noteDuration * 1.3 * 1000);
  }
  else if(note=='G'){
    tone(speakerPin, NOTE_G4, 1000*noteDuration);
    delay(noteDuration * 1.3 * 1000);
  }
   else if(note=='Z'){
    tone(speakerPin, 0, 1000*noteDuration);
    delay(noteDuration * 1.3 * 1000);
  }
  return;
}
  
