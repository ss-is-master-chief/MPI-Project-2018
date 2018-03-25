#include "pitches.h"
// To include audio driver code

// Setting timeout for score calculation, in seconds
float timeout = 0.3;

// Setting time between two notes, in seconds
float noteDelay = 5;

// Setting time to display result message, in seconds
float resultDelay = 10;

// Setting replay wait time
float replay = 10;

// Declaring game variables
long score1, score2;
int currentNote;
String noteSequence;
int NoteDuration;

void setup() {
  //  Opening channel at 9600 Baud
  Serial.begin(9600);

  currentNote = 0;
  noteSequence = "ABCDEZABCDEZABCDEZ";
  NoteDuration = 4;

  // Setting maximum value of score1 and score 2, in case one fails to transmit
  score1 = score2 = noteSequence.length()*timeout;
}

void loop() {
  while(1)
  {
    Serial.write('A');
    delay(1000);
  }
  if(noteSequence[currentNote] == '\0')
  { 
    // Sending STOP signal
    Serial.write("STOP");
    
    // Getting scores from slaves
    score1 = Serial.parseFloat();
    // Delay to prevent collision of inputs
    delay(timeout * 1000);
    score2 = Serial.parseFloat();

    if(score1 > score2)
      Serial.write("ONE WINS");
    else if (score2 > score1)
      Serial.write("TWO WINS");
    else
      Serial.write("TIE");

     delay(resultDelay*1000);
     
     delay(replay * 1000);
     // Resetting game
     currentNote = 0;
  }
  else
  {
   switch(noteSequence[currentNote++])
   {
    case 'A':
      Serial.write("A");
      // Play note here
      Sing('A',NoteDuration);
      break;
    case 'B':
      Serial.write("B");
      // Play note here
      Sing('B',NoteDuration);
      break;
    case 'C':
      // Play note here
      Serial.write("C");
      Sing('C',NoteDuration);
      break;
    case 'D':
      // Play note here
      Serial.write("D");
      Sing('D',NoteDuration);
      break;
    case 'E':
      // Play note here
      Serial.write("E");
      Sing('E',NoteDuration);
      break;
    case 'F':
      // Play note here
      Serial.write("F");
      Sing('F',NoteDuration);
      break;
    case 'G':
      // Play note here
      Serial.write("G");
      Sing('G',NoteDuration);
      break;
    case 'Z':
      // Play note here
      Serial.write("Z");
      Sing('Z',NoteDuration);
      break;     
   }
  }
  
  // Pause to allow user to press note
  delay(NoteDuration * 1.3);
}
void Sing(char note,int duration)
{
  // to calculate the note duration, take one second divided by the note type.
  int noteDuration = 1000 /duration;
  int pauseBetweenNotes = noteDuration * 1.30;
  if(note=='A'){
    tone(8,NOTE_A4,noteDuration);
    // to distinguish the notes, set a minimum time between them.
    delay(pauseBetweenNotes);
  }
  else if(note=='B'){
    tone(8,NOTE_B4,noteDuration);
    // to distinguish the notes, set a minimum time between them.
    delay(pauseBetweenNotes);
  }
   else if(note=='C'){
    tone(8,NOTE_C4,noteDuration);
    // to distinguish the notes, set a minimum time between them.
    delay(pauseBetweenNotes);
  }
   else if(note=='D'){
    tone(8,NOTE_D4,noteDuration);
    // to distinguish the notes, set a minimum time between them.
    delay(pauseBetweenNotes);
  }
   else if(note=='E'){
    tone(8,NOTE_E4,noteDuration);
    // to distinguish the notes, set a minimum time between them.
    delay(pauseBetweenNotes);
  }
  else if(note=='F'){
    tone(8,NOTE_F4,noteDuration);
    // to distinguish the notes, set a minimum time between them.
    delay(pauseBetweenNotes);
  }
  else if(note=='G'){
    tone(8,NOTE_G4,noteDuration);
    // to distinguish the notes, set a minimum time between them.
    delay(pauseBetweenNotes);
  }
   else if(note=='Z'){
    tone(8,0,noteDuration);
    // to distinguish the notes, set a minimum time between them.
    delay(pauseBetweenNotes);
  }
}
