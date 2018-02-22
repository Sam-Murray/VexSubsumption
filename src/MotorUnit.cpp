#include "MotorUnit.h"


MotorUnit::MotorUnit(int p): channel(p), speed(0)
{
}
// MotorUnit::MotorUnit(): channel(1), speed(0)
// {
// }
void MotorUnit::setSpeed(int s)
{

  speed = s;
  if(channel != 0){
    motorSet(channel, speed);
  }

}
int MotorUnit::getSpeed()
{
  return speed;
}
