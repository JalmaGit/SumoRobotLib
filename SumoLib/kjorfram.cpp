#include "kjorfram.h"

#define LED 13

#define QTR_THRESHOLD  1500

#define NUM_SENSORS 6
unsigned int sensor_values[NUM_SENSORS];

ZumoReflectanceSensorArray sensors(QTR_NO_EMITTER_PIN);

ZumoBuzzer buzzer;
ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON);

unsigned long time_now = 0;

void sving (int i);
void knappstart_og_slutt();

void kjor(String i, int s, int d, bool sving_on_or_of) {

  while (true) {
    knappstart_og_slutt();
    if (sving_on_or_of) {
      sving(s);
    }
    if  (i == "frem") {
        motors.setSpeeds(s, s);
    }
    else if  (i == "bak") {
      motors.setSpeeds(-s, -s);
    }
    else if (i == "stopp") {
      motors.setSpeeds(0, 0);
    }
    if (millis() >= time_now + d) {
      time_now += d;
      break;
    }
  }
}

void sving (int i) {
  sensors.read(sensor_values);
  while (sensor_values[0] > QTR_THRESHOLD || sensor_values[5] > QTR_THRESHOLD) {
    sensors.read(sensor_values);

    knappstart_og_slutt();
    if (sensor_values[0] > QTR_THRESHOLD)
    {
      // if leftmost sensor detects line, turn to the right
      motors.setSpeeds(-i + 50, i + 50);
    }
    else if (sensor_values[5] > QTR_THRESHOLD)
    {
      // if rightmost sensor detects line, turn to the left
      motors.setSpeeds(i + 50, -i + 50);

    }
  }
}

void knappstart_og_slutt() {
  if (button.isPressed()) // if button is pressed, stop and wait for another press to go again
  {
    motors.setSpeeds(0, 0); //Stops the motors
    button.waitForRelease(); //waits for button to be released
    ventForKnapp();; //Calls function to wait for the next button press and 5 second timer
  }
}

void ventForKnapp()
{
  digitalWrite(LED, HIGH); //LED turns on
  button.waitForButton(); //Code stops and waits for button press
  digitalWrite(LED, LOW); //LED turns off
}

void musikk(String i) {
  if (i == "StarWars") {
    for (int i = 0; i < 3; i++)
    {
      delay(1000);
      buzzer.playNote(NOTE_C(3), 200, 15);
    }
    delay(1000);
    buzzer.playNote(NOTE_C(4), 500, 15);
    delay(1000);
  }
  else if (i == "Pirates") {
    for (int i = 0; i < 3; i++)
    {
      delay(1000);
      buzzer.playNote(NOTE_E(3), 200, 15);
    }
    delay(1000);
    buzzer.playNote(NOTE_E(4), 500, 15);
    delay(1000);
  }
  else if (i == "Seven") {
    for (int i = 0; i < 3; i++)
    {
      delay(1000);
      buzzer.playNote(NOTE_G(3), 200, 15);
    }
    delay(1000);
    buzzer.playNote(NOTE_G(4), 500, 15);
    delay(1000);
  }
  else if (i == "Mario") {
    for (int i = 0; i < 3; i++)
    {
      delay(1000);
      buzzer.playNote(NOTE_F(3), 200, 15);
    }
    delay(1000);
    buzzer.playNote(NOTE_F(4), 500, 15);
    delay(1000);
  }

}
