## Beat It

### Details
The project contains two pieces of code, one for the master and one for the slaves (both slaves can run on the same code)
The features of the code, in it's current form, are as enumerated below
   + The master and slaves communicate via the Serial channel
      + Two serials have been defined, one being the default one and another via the SoftwareSerial package
      + The master's TX pin for the default Serial (pin 1) will be connected to the RX pin of slave 1 (pin 0), while the TX pin for the new Serial (pin 10) will be connected to the RX pin of slave 2 (pin 0). A similar arrangement will be done for the master's RXs and slave's TX (Master's pin 0 to Slave 1's pin 1 | Master's pin 9 to Slave 2's pin 1).
      + This reduces the number of pins needed for master-slave communication, from 8 to 2. This wouldn't have been a problem in the master board, but on the slave, an additional 5 pins were required for the input buttons and 6 more for the LCD board
      + The signals have been defined as 'S', '1', '2', 'T', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'P'
   + The game will be replayable. After the declaration of the results, all three boards will wait for a predetermined time, before resetting and starting another round again. As of now, it will follow the same sequence
   + In case a slave fails to transmit the score of its player, the master will take them maximum possible score
   + The code for the LCD interfacing is done for the slaves
      + The slave will display the note to be played now, a message when the game ends, the number of seconds left before starting a new round
   + The sounds are played as per the note sequence, where A, B, C, D, E, F, G have been defined, and can play. An additional Z note has been defined to allow for pauses. No sound will be emitted when Z is encountered.
   + When the game is over, the master will send a P on the serial to indicate that slave 1 has to transmit its score. Then the master sends a P on the softare serial to indicate to slave 2 that it has to transmit its score
   + The scores are calculated as float, and are transmitted as a string


### To-Do
The following tasks have to be tackled
   + Fixing invalid reads from buttons
   + Cleaning up code

### Possible add on ideas
The following features can be added
   + More note sequences
      + The random sequence can be selected once at setup() and once right before replay. Since the code will run until it encounters a null character, the length of note sequence is not a cause for concern.
      + The slaves must have a way of knowing what sequence is playing, so as to set the value of input pins
   + Interfacing LEDs to display winner and other such details

### Change Log
#### 31st March
+ Both Slaves now run on a single code
+ P is the default signal to indicate transmission of scores
+ A second Serial has been defined
+ Scores are now calculated as float, are converted to a string before transmission and are converted back to a float after recieving
#### 28th March
+ Now P and Q are used to signal when scores are sent
+ Removed timeout and delay(timeout)s for timing when scores are sent
#### 26th March
+ Command words from Master to Slaves are now changed to single characters, to allow faster, and easier transmission of commands
+ Slaves now listen for buttons only when an input is recieved
+ Code for sound works, and simply changing the noteDuration variable for all three files will adjust timing
