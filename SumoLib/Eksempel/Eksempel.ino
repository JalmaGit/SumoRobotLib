#include <kjorfram.h>


void setup() { //Dette brukes første gang arduinoen starter for å set ting i gang.
  //Denne funksjonen gjør at roboten starter i stille tilstand og venter på at knappen blir trykt
  ventForKnapp();
  
  //Denne funksjonen spiller en liten lått, det er fire låter: "Mario", "StarWars", "Pirates", "Seven"
  musikk("Mario"); 

  
}

void loop() { //Denne delen kjører gjentakene, til evig tid.
  /*Funksjonen under brukes til å styre roboten med fire parametre:
  kjor("ord", hel-tall, hel-tall, true/false); 
  
  Den første er en del av en streng, som vil si et ord eller setning
  Valgene er: "frem", "bak", "stopp"
  
  Den andre er et nummer. Det nummeret styrer farten til roboten. 
  Tallet er et helt tall mellom: 50 - 400.
  
  Den tredje er et nummer. Det nummeret styrer hvor lenge roboten kjorer den spesefikke funksjonen hvis det brukes flere kjor funksjoner. 
  Gjør ingen ting hvis bare en brukes en funksjon. Tiden er i millisekunder
  Tallet er et helt tall mellom: 1 - uendlig
  
  Den fjerde er en false/true valg. false betyr falsk og true betyr sant. Den styrer om linjefølgeren blir aktivert eller ikke.
  For å aktivere linje følgeren så må det stå: true
  For å deaktivere linje følgeren så må det stå: false
  */
  kjor("frem", 200, 500, false); //kjører frem med en fart på 0.2m/s i 0.5sekunder/500millisekunder.
  kjor("bak", 100, 2000, false); //kjører bakover med en fart på 0.2m/s i 2sekunder/2000millisekunder.
}
