
#include <Arduino.h>
class Ultra
{

  public:

  Ultra();
  Ultra(int Echo,int Trigger);
  void setDiferenceK(int k);
  
  int getDistance();
  bool SurpaseK();
  
  private:
  int Echo;
  int Trigger;
  int distance;
  int duration;
  int diference;
  int TempDiference;
  int k;
  void calculateD();

  
  };
  