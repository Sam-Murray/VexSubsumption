#ifndef CLAW_H
#define CLAW_H
#include "API.h"

class Claw{
private:
  int pin1;
  int pin2;
  bool open=false;
public:
  Claw(){};
  Claw(int p1, int p2):pin1(p1),pin2(p2){};
  void clawSet(bool openClosed){
    digitalWrite(pin1, openClosed);
    digitalWrite(pin2, openClosed);
    open=openClosed;
  }
  void Update(bool o, bool c){
    bool u=o&&(!c);
    clawSet(u);
  }
};

#endif
