#include "pitches.h"

// Setting duration for each note, in seconds
float noteDuration = 1;

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

void setup() {
  //  Opening channel at 9600 Baud
  Serial.begin(9600);
  
  currentNote = 0;
  noteSequence = "ABCDEZABCDEZABCDEZ";

  // Setting maximum value of score1 and score 2, in case one fails to transmit
  score1 = score2 = noteSequence.length()*2.3*noteDuration;
}

void loop() {
  Serial.flush();
  if(noteSequence[currentNote] == '\0')
  { 
    // Sending STOP signal
    Serial.write('S');
    
    // Getting scores from slaves
    Serial.write('P');
    if(Serial.available())
      score1 = Serial.parseFloat();
    
    Serial.write('Q');
    if(Serial.available())
      score2 = Serial.parseFloat();

    if(score1 < score2)
      Serial.write('1');
    else if (score2 < score1)
      Serial.write('2');
    else
      Serial.write('T');

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
      sing('A', noteDuration);
      break;
    case 'B':
      Serial.write('B');
      sing('B', noteDuration);
      break;
    case 'C':
      Serial.write('C');
      sing('C', noteDuration);
      break;    
    case 'D':
      Serial.write('D');
      sing('D', noteDuration);
      break;
    case 'E':
      Serial.write('E');
      sing('E', noteDuration);
      break;
    case 'F':
      Serial.write('F');
      sing('F', noteDuration);
      break;
    case 'G':
      Serial.write('G');
      sing('G', noteDuration);
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
