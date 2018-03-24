/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"

// notes in the melody:
//int melody[] = {NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_B4,NOTE_A4, NOTE_B4,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_A4, NOTE_B4, NOTE_A4, NOTE_B4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
//int noteDurations[] =  4, 4, 4, 4, 4, 4, 4, 4,4, 4, 4, 4, 4, 4, 4, 4};

void setup() {
  //The melody here would be sent by the master.This is a smaple. 
  String melody="ACACABABAAAAABAB";
  int d=4;
  for(int i=0;i<melody.length();i++)
  {
    SingJeeLeZaraa(melody[i],d);
  }
}

void loop() {
  // no need to repeat the melody.
}
void SingJeeLeZaraa(char note,int duration)
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
    tone(8,NOTE_C5,noteDuration);
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
   else if(note=='Z'){
    tone(8,0,noteDuration);
    // to distinguish the notes, set a minimum time between them.
    delay(pauseBetweenNotes);
  }
}

