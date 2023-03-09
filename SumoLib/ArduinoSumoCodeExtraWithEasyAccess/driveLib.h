#ifndef DRIVELIB_H
#define DRIVELIB_H

#include <Arduino.h>
#include <ZumoShield.h>
#include <Wire.h>
#include <ZumoBuzzer.h>
//Here we initialize the functions with global access through driveLib.h 
void lineFollow (int trackSpeed); 
void turnLeft (int turnSpeed);
void turnRight (int turnSpeed);
void driveForward (int trackSpeed);
void driveBackward (int trackSpeed);

bool leftSensor();
bool rightSensor();

void waitForButtonThenStart();
void music(String i);

#endif
