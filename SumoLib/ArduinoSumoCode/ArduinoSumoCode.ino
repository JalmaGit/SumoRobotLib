#include "src/driveLib.h"


void setup() { //Dette brukes første gang arduinoen starter for å set ting i gang.
  //The code stops at this function and waits for the button to be pressed. Only used on start up.
  waitForButtonThenStart();
  //This function plays a little melody, the choices here are "Mario", "StarWars", "Seven".
  music("Seven");


}

void loop() {
  /*
     There are a few functions available to use: driveForward(int), driveBackward(int), turnLeft(int), turnRight(int), lineFollow(int).
     In each of these functions there is one int parameter. An int is a whole number.
     In our case we want use an int between 0 - 400, which on the SumoRobot translates to a speed between 0 - 0.4 m/s.
     Any higher or lower will result in either just max speed or no speed.
     The delay function will delay execution of new commands for a period of time. The function accepts only positive whole numbers (milliseconds).
  */

  // play around with the order and presence of the below commands
  driveForward(200);
  delay(200);
  driveBackward(200);
  delay(200);
  turnLeft(200);
  delay(200);
  turnRight(200);
  delay(200);

}
