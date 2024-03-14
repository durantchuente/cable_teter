#include <Arduino.h>
#include "cableTester.hpp"

//Definition des variables et des tableaux contenant les broches utilisées par le programme
char pinCable1[8] = {A4, A5, A6, 0, 1, 2, 3, 4};
int pinCable2[8] = {5, 6, 7, 8, 9, 10, 11, 12};
int responseArrayCable[8];
CableTester cableTest;

void setup() {
  //Definition des broches en entrées
  for (int i = 0; i < 8; i++) {
    pinMode(pinCable1[i], INPUT);
  }
  //Definition des broches en sorties
  for (int i = 0; i < 8; i++) {
    pinMode(pinCable2[i], OUTPUT);
  }

  Serial.begin(9600);
}

void loop() {
  int n = 0;
  do {  
    digitalWrite(pinCable2[n], HIGH); //Envoie du signal élévé aux broches de sortie
    for (int i = 0;i < 8;i++) {
      if (digitalRead(pinCable1[i])) //Vérification de l'état du signal des broches d'entrées
      {
        responseArrayCable[n] = i; //Affectation des position des broches ayant recu un signagle élévé dans un tableau
      }
    }
    digitalWrite(pinCable2[n], LOW); //Envoie du signal faible aux broches de sortie
    n = n+1;
  } while (n<8);
  
  delay(2000);
}