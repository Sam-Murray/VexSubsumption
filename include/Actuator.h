#ifndef ACTUATOR_H
#define ACTUATOR_H
#include "MotorUnit.h"
#include "API.h"

class Actuator
{
private:
  MotorUnit actuatorMotor;
  int speed;
public:
  Actuator();
  Actuator(int aPin,int s);
  Actuator(int aPin);
  void setSpeed(int s);
  void Update(bool outPressed, bool inPressed);

};

#endif
