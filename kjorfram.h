#ifndef KJORFRAM_H
#define KJORFRAM_H

#include <Arduino.h>
#include <ZumoShield.h>
#include <Wire.h>
#include <ZumoBuzzer.h>

void kjor (String i, int d, int s, bool sving_on_or_of); //(start/stopp,hastighet:0-400,Et lite delay fra 0 til uendlig)
void ventForKnapp();
void musikk(String i);

#endif
