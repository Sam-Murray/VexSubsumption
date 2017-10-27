#ifndef CLAW_H
#define CLAW_H
#include "API.h"

class Claw{
private:
  int pin1;
  bool open=false;
public:
  Claw():pin1(1){};
  Claw(int p1):pin1(p1){};
  void clawSet(bool openClosed){
    digitalWrite(pin1, openClosed);
    open=openClosed;
  }
  void Update(bool o, bool c){
    bool u=o&&(!c);
    clawSet(u);
  }
};

#endif
