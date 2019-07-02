

#include "Ultra.h"



  
Ultra::Ultra()
  {
    Echo = NULL;
    Trigger = NULL;
    distance = NULL;
    duration = NULL;
    diference = NULL;
    TempDiference=NULL;
    k=NULL;
  }
  Ultra::Ultra(int Echo, int Trigger){
    this->Echo = Echo;
    this->Trigger = Trigger;
    distance = NULL;
    duration = NULL;
    diference = NULL;
    TempDiference = NULL;
    k = NULL;

    pinMode(Trigger,OUTPUT);
    pinMode(Echo,INPUT);
    
  }



  ///the konstans you dont want to surpase or change in diference
  void Ultra::setDiferenceK(int k)
  {
    this->k = k;
  }
  void Ultra::calculateD()
  {
    ///Tiempo para que no exista desfase
    digitalWrite(Trigger,LOW);

    delayMicroseconds(2);

    //empieza la onda
    digitalWrite(Trigger,HIGH);

    delayMicroseconds(10);
    //despues de 10 milisegundos se apaga
    digitalWrite(Trigger,LOW);

    ///guardamos la medida anterior, si no existe se pone cero
    int durationTemp = pulseIn(Echo,HIGH);
    duration = durationTemp;
    distance = duration *.034/2;
      

  }
  bool Ultra::SurpaseK()
  {
    if(k != 0 && k >= diference)
      return true;
    else
      return false;
  }
  int Ultra::getDistance()
  {
    calculateD();
    return distance;

  }
