#include "src/driveLib.h"


void setup() { //This is used to run code once.
  //The code stopps at this function and waits for the button to be pressed. Only used on start up.
  waitForButtonThenStart();
  //This function plays a little melody, the melody choices are "Mario", "StarWars", "Seven".
  music("StarWars");


}

void loop() { //After "void setup()" the code will come here and run endlessly unless the device is turned off.

  /*"If" statements are statement that checks if a condition is true or false then execute code depending on that.
    Sometimes you want to check multipile statements to make the program behave differently, based on the value the condition has.
    "else if" statements are optional, and are used if you want to check another statement incase the first "if" failed. You can use zero or more "else if".
    "else" statements are optional, and are used if you want to execute some code if the "if" or "else if" statements failed. You can only use one "else".


    if([condition]){
     ... code ...
    }
    The code within an if block will only get executed, if the [condition] is true
    In our case the condition is either leftSensor() or rightSensor().
    The sensor are true when the sensor sees a very dark/black surface.

    if([condition]){
     ... code ...
    }
    else{
     ... code ...
    }
    If the [condition] is not true, the code within the else block will get executed

    if([condition]){
    ... code ...
    }
    else if([condition]){
    ... code ...
    }
    else{
    ... code ...
    }
    After an if statement, any amount of elseif (0, 1 or more) statements can be used to check for other conditions as well. The code within an elseif block will only get executed, if none of the conditions of the (else)if blocks before it are true.
    Only if none of the if/elseif conditions are true, the code in the else block is run.*/

  if (leftSensor()) {
    //...Code
  }
  else if (rightSensor()) {
    //...Code
  }
  else {
    //...Code
  }
}
