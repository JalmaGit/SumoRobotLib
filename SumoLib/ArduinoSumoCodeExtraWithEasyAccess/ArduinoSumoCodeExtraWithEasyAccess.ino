#include "driveLib.h"

void setup() { //This is used to run code once.
  //The code stopps at this function and waits for the button to be pressed. Only used on start up.
  waitForButtonThenStart();
  Serial.begin(9600); //This is for communcation with the Arduino over USB.
  //This function plays a little melody, the melody choices are "Mario", "StarWars", "Seven".
  music("StarWars");


}

void loop() { //After "void setup()" the code will run endlessly unless the device is turned off or reset.
  //...Code...
}
