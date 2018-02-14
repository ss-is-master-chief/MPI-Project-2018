## Beat It

### Details
The project contains three pieces of code, one for the master and two for the slaves (one for each player)
The new features of the code, in it's current form, are as enumerated below
   + The master and slave communicate via the Serial channel   
      + The master's TX pin will be connected to the RX pin of both slaves, and both slaves' TX pin will be connected to the RX pin of the master's
      + Although TX is a OUTPUT only pin and there shouldn't be a problem when the one slave's transmitted data reaches the other's TX, there are provisions to ensure that when one transmits, the other shouldn't (by a delay() command)
      + This reduced the number of pins needed for master-slave communication, from 8 to 2. This wouldn't have been a problem in the master board, but on the slave, an additional 5 pins were required for the input buttons and 6 more for the LCD board
      + The signals have been defined as 'STOP', 'ONE WINS', 'TWO WINS', 'TIE', 'A', 'B', 'C', 'D', 'E' 
   + The game will be replayable. After the declaration of the results, all three boards will wait for a predetermined time, before resetting and starting another round again. As of now, it will follow the same sequence
   + In case a slave fails to transmit the score of its player, the master will take them maximum possible score
   + The code for the LCD interfacing is done for the slaves
      + The slave will display the note to be played now, a message when the game ends, the number of seconds left before starting a new round


### To-Do
The following tasks have to be tackled
   + The audio driver has to be written/linked in the master code
   + The code to play a note has to be written in the switch in the master code
   + I did not get a chance to test out the code. It has to be run with at least two boards (one master and one slave)


### Possible add on ideas
The following features can be added
   + More note sequences
      + The random sequence can be selected once at setup() and once right before replay. Since the code will run until it encounters a null character, the length of note sequence is not a cause for concern.
   + Interfacing LEDs to display winner and other such details
