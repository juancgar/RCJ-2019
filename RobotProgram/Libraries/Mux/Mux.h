#include <Arduino.h>
class Mux
{
public:
  int setChannel(int Channel);
  /// 0 254 0 1023
  Mux();
  void setSignatures(int arr[10]);


private:
  const int SIG = A2;
  const int S0 = 44;
  const int S1 = 42;
  const int S2 = 40;
  const int S3 = 38;

  // Back 3 Front 2 Left 3 Right 3
  int Signatures[10];
  int value;



};