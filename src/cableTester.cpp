#include <Arduino.h>
#include "CableTester.hpp"
#include <string>

using namespace std;

CableTester::CableTester(){};

int CableTester::orderPositionCross[8] = {2, 5, 0, 3, 4, 1, 6, 7}; //Definition du tableau de position de reception du signal d'un cable croisé
int CableTester::orderPositionStraight[8] = {0, 1, 2, 3, 4, 5, 6, 7};//Definition du tableau de position de reception du signal d'un cable droit
bool compareArrays(int a[], int b[], int n); //Definition du prototype de la fonction de comparaison de tableau

void CableTester::verifyCableType(int resultOrderSignalPosition[], int n){ //Definition de la fonction de vérification du type de cable
    if (compareArrays(orderPositionStraight, resultOrderSignalPosition, n)) //On verifie ici si le tableau qui resulte du teste est equivalent a celui du cable droit
  {
    Serial.println("Ce cable est droit");
  }
  else if (compareArrays(orderPositionCross, resultOrderSignalPosition, n)) //On verifie ici si le tableau qui resulte du teste est equivalent a celui du cable croisé
  {
    Serial.println("Ce cable est croisé");
  }
  else
  {
    Serial.println("Ce cable est inconnu");
  }
}

bool compareArrays(int a[], int b[], int n) { //Implementation de la fonction de comparaison de tableaux
  int i;
  for(i = 0; i < n; i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}