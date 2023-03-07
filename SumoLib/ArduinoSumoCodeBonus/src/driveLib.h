#ifndef DRIVELIB_H
#define DRIVELIB_H

#include <Arduino.h>
#include <ZumoShield.h>
#include <Wire.h>
#include <ZumoBuzzer.h>

void lineFollow (int trackSpeed); //(start/stopp,hastighet:0-400,Et lite delay fra 0 til uendlig)

void turnLeft (int turnSpeed);
void turnRight (int turnSpeed);
void driveForward (int trackSpeed);
void driveBackward (int trackSpeed);

bool leftSensor();
bool rightSensor();

void waitForButtonThenStart();
void music(String i);

#endif
