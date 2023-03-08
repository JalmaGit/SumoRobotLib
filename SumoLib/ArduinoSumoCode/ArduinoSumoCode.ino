#include "src/driveLib.h"


void setup() { //This is used to run code once.
  //The code stopps at this function and waits for the button to be pressed. Only used on start up.
  waitForButtonThenStart();
  //This function plays a little melody, the melody choices are "Mario", "StarWars", "Seven".
  music("Mario");


}

void loop() { //After "void setup()" the code will run endlessly unless the device is turned off.
  /*
     There are a few functions available to use: driveForward(int), driveBackward(int), turnLeft(int), turnRight(int), lineFollow(int).
     In each of these functions there are one parametre which is an int. An int is a whole number.
     In our case we want use an int between 0 - 400 which on the SumoRobot means a speed between 0 - 0.4 m/s.
     Any higher or lower will result in eiter just max speed or no speed.
     the delay function is a delay function that takes only positive whole numbers. The values translates to milliseconds
  */
  
  driveForward(200);
  delay(200);
  driveBackward(200);
  delay(200);
  turnLeft(200);
  delay(200);
  turnRight(200);
  delay(200);

}
