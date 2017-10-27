#ifndef ACTUATORARRAY_H
#define ACTUATORARRAY_H
#include "Actuator.h"

class ActuatorArray{
private:
  Actuator motors[4];
public:
  ActuatorArray();
  ActuatorArray(int pin1,int pin2);
  ActuatorArray(int pin1,int pin2,int pin3,int pin4);
  void setSpeed(int index,int s);
  void setSpeed(int s1,int s2, int s3,int s4);
  void setSpeed(int s);
  void Update(bool outPressed, bool inPressed,int i1,int i2,int i3,int i4);
  void Update(bool outPressed, bool inPressed);

};

#endif
