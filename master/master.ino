#include "pitches.h"
#include <SoftwareSerial.h>
SoftwareSerial s2(9,10); 

// Setting duration for each note, in seconds
float noteDuration = 0.5;

// Setting note value, for pitches
float noteValue = 1/noteDuration;

// Setting time to display result message, in seconds
float resultDelay = 10;

// Setting replay wait time
float replay = 10;

// Setting speaker pin
int speakerPin = 8;

// Declaring game variables
long score1, score2;
int currentNote;
String noteSequence;
unsigned long temp = 0;

void setup() {
  //  Opening channel at 9600 Baud
  Serial.begin(9600);
  s2.begin(9600);
  currentNote = 0;
  noteSequence = "ABCDEZABCDEZABCDEZ";

  // Setting maximum value of score1 and score 2, in case one fails to transmit
  score1 = score2 = noteSequence.length()*2.3*noteDuration;
  delay(1000);
  Serial.flush();
  s2.flush();
}


void loop() {
  Serial.flush();
  s2.flush();
  if(noteSequence[currentNote] == '\0')
  { 
    // Sending STOP signal
    Serial.write('S');
    s2.write('S');
    delay(1000);

    
    // Getting scores from slaves
    Serial.write('P');
    while(!Serial.available());
    score1 = Serial.parseFloat();
    Serial.println(score1);
//    delay(2000);
      
    s2.write('P');
    while(!s2.available());
    score2 = s2.parseFloat();
    Serial.println(score2);
//    delay(2000);

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
     
     delay(replay*1000);
     // Resetting game
     currentNote = 0;
     score1 = score2 = noteSequence.length()*2.3*noteDuration;
  }
  else
  {
   switch(noteSequence[currentNote++])
   {
    case 'A':
      Serial.write('A');
      s2.write('A');
//      Serial.println('A');
      sing('A', noteDuration);
      break;
    case 'B':
      Serial.write('B');
      s2.write('B');
//      Serial.println('B');
      sing('B', noteDuration);
      break;
    case 'C':
      Serial.write('C');
      s2.write('C');
//      Serial.println('C');
      sing('C', noteDuration);
      break;    
    case 'D':
      Serial.write('D');
      s2.write('D');
//      Serial.println('D');
      sing('D', noteDuration);
      break;
    case 'E':
      Serial.write('E');
      s2.write('E');
//      Serial.println('E');      
      sing('E', noteDuration);
      break;
    case 'F':
      Serial.write('F');
      s2.write('F');
//      Serial.println('F');
      sing('F', noteDuration);
      break;
    case 'G':
      Serial.write('G');
      s2.write('G');
//      Serial.println('G');
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
    delay(noteDuration * 1.30 * 1000);
  }
  else if(note=='B'){
    tone(speakerPin, NOTE_B4, 1000*noteDuration);
    delay(noteDuration * 1.30 * 1000);
  }
   else if(note=='C'){
    tone(speakerPin, NOTE_C4, 1000*noteDuration);
    delay(noteDuration * 1.30 * 1000);
  }
   else if(note=='D'){
    tone(speakerPin, NOTE_D4, 1000*noteDuration);
    delay(noteDuration * 1.30 * 1000);
  }
   else if(note=='E'){
    tone(speakerPin, NOTE_E4, 1000*noteDuration);
    delay(noteDuration * 1.30 * 1000);
  }
  else if(note=='F'){
    tone(speakerPin, NOTE_F4, 1000*noteDuration);
    delay(noteDuration * 1.30 * 1000);
  }
  else if(note=='G'){
    tone(speakerPin, NOTE_G4, 1000*noteDuration);
    delay(noteDuration * 1.30 * 1000);
  }
   else if(note=='Z'){
    tone(speakerPin, 0, 1000*noteDuration);
    delay(noteDuration * 1.30 * 1000);
  }
  return;
}
