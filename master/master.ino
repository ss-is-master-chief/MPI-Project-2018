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
float score1, score2;
int currentNote;
String noteSequence;

void setup() {
  //  Opening channel at 9600 Baud
  Serial.begin(9600);

  currentNote = 0;
  noteSequence = "ABCDEABEDAC";

  // Setting maximum value of score1 and score 2, in case one fails to transmit
  score1 = score2 = noteSequence.length()*timeout;
}

void loop() {
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
      // Play note here
      Serial.write("A");
      break;
    case 'B':
      // Play note here
      Serial.write("B");
      break;
    case 'C':
      // Play note here
      Serial.write("C");
      break;
    case 'D':
      // Play note here
      Serial.write("D");
      break;
    case 'E':
      // Play note here
      Serial.write("E");
      break;      
   }
  }
  
  // Pause to allow user to press note
  delay(noteDelay * 1000);
}
