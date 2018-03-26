## Beat It

### Details
The project contains three pieces of code, one for the master and two for the slaves (one for each player)
The new features of the code, in it's current form, are as enumerated below
   + The master and slave communicate via the Serial channel   
      + The master's TX pin will be connected to the RX pin of both slaves, and both slaves' TX pin will be connected to the RX pin of the master's
      + Although TX is a OUTPUT only pin and there shouldn't be a problem when the one slave's transmitted data reaches the other's TX, there are provisions to ensure that when one transmits, the other shouldn't (by a delay() command)
      + This reduced the number of pins needed for master-slave communication, from 8 to 2. This wouldn't have been a problem in the master board, but on the slave, an additional 5 pins were required for the input buttons and 6 more for the LCD board
      + The signals have been defined as 'S', '1', '2', 'T', 'A', 'B', 'C', 'D', 'E' 
   + The game will be replayable. After the declaration of the results, all three boards will wait for a predetermined time, before resetting and starting another round again. As of now, it will follow the same sequence
   + In case a slave fails to transmit the score of its player, the master will take them maximum possible score
   + The code for the LCD interfacing is done for the slaves
      + The slave will display the note to be played now, a message when the game ends, the number of seconds left before starting a new round
   + The sounds are played as per the note sequence, where A, B, C, D, E, F, G have been defined, and can play. An additional Z note has been defined to allow for pauses. No sound will be emitted when Z is encountered.


### To-Do
The following tasks have to be tackled
   + Transmission of long values from slave to master
   + Slight timing corrections to accomodate the above transmission
   + Removing all Serial.println() statements


### Possible add on ideas
The following features can be added
   + More note sequences
      + The random sequence can be selected once at setup() and once right before replay. Since the code will run until it encounters a null character, the length of note sequence is not a cause for concern.
      + The slaves must have a way of knowing what sequence is playing, so as to set the value of input pins
   + Interfacing LEDs to display winner and other such details

### Change Log
#### 26th March
+ Command words from Master to Slaves are now changed to single characters, to allow faster, and easier transmission of commands
+ Slaves now listen for buttons only when an input is recieved
+ Code for sound works, and simply changing the noteDuration variable for all three files will adjust timing
