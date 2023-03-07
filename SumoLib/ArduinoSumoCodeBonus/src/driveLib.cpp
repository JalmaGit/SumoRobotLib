#include "driveLib.h"

#define LED 13

#define SENS_THRESHOLD  1500

#define NUM_SENSORS 6
unsigned int sensor_values[NUM_SENSORS];
ZumoReflectanceSensorArray sensors(QTR_NO_EMITTER_PIN);

ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON);

ZumoBuzzer buzzer;
const char starWars[] PROGMEM = "!V15 eee C8.G16 e C8.G16 E2";
const char mario[] PROGMEM = "T180 O5 V15 E8E8 R8 E8 R8 C8 E G R4 >G R4 <C R8 >G R8 E R8 G B B8- G G6<E6G6 B F8G8 R8 E C8D8>B R8 <C R8 >G R8 E R8 G B B8- G G6<E6G6 B F8G8 R8 E C8D8>B R8 R4 <G8F8+F8 D+ E8 R8 >G8+A8<C8 R8 >A8<C8D8 R4 G8 F8+F8 D+ E8 R8 < C C8 C R4 R4 >G8F8+ F8 D+ E8 R8 >G8+A8<C8 R8 >G8<C8D8 R4 G- R4 F R4 C R4";
const char seven[] PROGMEM = "O3 V15  E. E8 G8.E8.D8 C2 <B2 >E. E8 G8.E8.D8 C2 <B2 >E. E8 G8.E8.D8 C8.D8.C <B2";
const char pirates[] PROGMEM = "!V15 eee C8.G16 e C8.G16 E2";

void buttonStartAndStopp();

void lineFollow(int trackSpeed) {

  buttonStartAndStopp();
  sensors.read(sensor_values);

  if (sensor_values[0] > SENS_THRESHOLD) { //left turn
    turnLeft(trackSpeed);
  } else if (sensor_values[5] > SENS_THRESHOLD) { //right turn
    turnRight(trackSpeed);
  } else {
    driveForward(trackSpeed);
  }
}

void turnLeft (int turnSpeed) {
  buttonStartAndStopp();
  if (turnSpeed < 0) {
    motors.setSpeeds(0, 0);
  }
  else if (turnSpeed > 400)
  {
    motors.setSpeeds(-400, 400);
  }
  motors.setSpeeds(-turnSpeed, turnSpeed);
}

void turnRight (int turnSpeed) {
  buttonStartAndStopp();
  if (turnSpeed < 0) {
    motors.setSpeeds(0, 0);
  }
  else if (turnSpeed > 400)
  {
    motors.setSpeeds(400, -400);
  }
  motors.setSpeeds(turnSpeed, -turnSpeed);
}


void driveForward (int trackSpeed) {
  buttonStartAndStopp();
  if (trackSpeed < 0) {
    motors.setSpeeds(0, 0);
  }
  else if (trackSpeed > 400)
  {
    motors.setSpeeds(400, 400);
  }
  motors.setSpeeds(trackSpeed, trackSpeed);
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
  else if (i == "Pirates") {
    buzzer.playFromProgramSpace(pirates);
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

bool leftSensor() {
  sensors.read(sensor_values);
  return (sensor_values[0] > SENS_THRESHOLD);
}

bool rightSensor() {
  sensors.read(sensor_values);
  return (sensor_values[5] > SENS_THRESHOLD);
}
