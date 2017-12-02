#ifndef CLAW_H
#define CLAW_H
#include "API.h"
#include "Actuator.h"

class Claw:public Actuator{
private:
  bool closed=false;
  bool control=true;
  int openTimer=700;
public:
  Claw():Actuator::Actuator(1){};
  Claw(int p1):Actuator::Actuator(p1){};
  Claw(int p1,int speed):Actuator::Actuator(p1,speed){};
  void clawSet(bool ifClosed){
    if(ifClosed){
      Actuator::Update(0,1);
      openTimer=700;
    }else if(openTimer>0){
      Actuator::Update(1,0);
      openTimer-=1;
    }else{
      Actuator::Update(0,0);
    }
  }

  void Update(bool toggle){

    if(toggle&&control)
    {
      closed=!closed;
    }
    clawSet(closed);
    control=!toggle;
  }
};

#endif
