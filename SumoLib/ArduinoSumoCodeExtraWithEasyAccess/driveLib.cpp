#include "driveLib.h"

#define LED 13

#define SENS_THRESHOLD  1500

#define NUM_SENSORS 6
unsigned int sensor_values[NUM_SENSORS];
ZumoReflectanceSensorArray sensors(QTR_NO_EMITTER_PIN);

ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON);

ZumoBuzzer buzzer;
//Here the different tunes are set.
const char starWars[] PROGMEM = "!V15 eee C8.G16 e C8.G16 E2";
const char mario[] PROGMEM = "T180 O5 V15 E8E8 R8 E8 R8 C8 E G R4 O4 G";
const char seven[] PROGMEM = "O4 V15  E. E8 G8.E8.D8 C2 O3 B2 O4 E. E8 G8.E8.D8 C2 O3 B2 O4 E. E8 G8.E8.D8 C8.D8.C8 O3 B2";

void buttonStartAndStopp(); //This is used intilize the function locally

//A void function is a function that returns nothing
//A bool function is a function that returns a boolean value, true/false


//TASK:
/*
 * Finnish function lineFollow
 * Finnish function driveForward, turnLeft, turnRight.
 * For reference use driveBackwards
 */


void lineFollow(int trackSpeed) { //Here one function starts

  buttonStartAndStopp();
  sensors.read(sensor_values);

  /*
   * Below these two conditions can be used
   * You will have to select which logic to use.
   * Example: sensor_values[0] == SENS_THRESHOLD
   * "sensor_values[0] > or < or == SENS_THRESHOLD" <-- This is for the left sensor
   * "sensor_values[5] > or < or == SENS_THRESHOLD" <-- This is for the right sensor
   * You could use Serial.println(sensor_values[]) to get info on what the sensors reads
   */

  if (/*Condition*/) {
    //...Code...
  } else if (/*Condition*/) {
    //...Code...
  } else {
    //...Code...
  }
} //Here it ends

void turnLeft (int turnSpeed) {
  /*You will have to finnish this function.
    make sure that if the turnSpeed value is lower than 0, then the robot will continue to stand still
    make sure that if the turnSpeed value exceeds 400, that the code sets the speed to max 400
    You can write "-" in front of turnSpeed to reverse the motors
   */
  //...Code...
}

void turnRight (int turnSpeed) {
  /*You will have to finnish this function.
    make sure that if the turnSpeed value is lower than 0, then the robot will continue to stand still
    make sure that if the turnSpeed value exceeds 400, that the code sets the speed to max 400
    You can write "-" in front of turnSpeed to reverse the motors
   */
  //...Code...
}


void driveForward (int trackSpeed) { 
  /*You will have to finnish this function.
    make sure that if the trackSpeed value is lower than 0, then the robot will continue to stand still
    make sure that if the trackSpeed value exceeds 400, that the code sets the speed to max 400
   */
  //...Code...
}

void driveBackward (int trackSpeed) {
  buttonStartAndStopp();
  if (trackSpeed < 0) {
    motors.setSpeeds(0, 0);
  }
  else if (trackSpeed > 400)
  {
    motors.setSpeeds(-400, -400);
  }
  motors.setSpeeds(-trackSpeed, -trackSpeed);
}


void buttonStartAndStopp() {
  if (button.isPressed()) {
    motors.setSpeeds(0, 0);
    button.waitForRelease();
    waitForButtonThenStart();
  }
}

void waitForButtonThenStart() {
  digitalWrite(LED, HIGH);
  button.waitForButton();
  digitalWrite(LED, LOW);
}

void music(String i) {
  if (i == "StarWars") {
    buzzer.playFromProgramSpace(starWars);
    delay(4000);
  }
  else if (i == "Seven") {
    buzzer.playFromProgramSpace(seven);
    delay(4000);
  }
  else if (i == "Mario") {
    buzzer.playFromProgramSpace(mario);
    delay(4000);
  }
}

//Below is extra functions if there is more time.
