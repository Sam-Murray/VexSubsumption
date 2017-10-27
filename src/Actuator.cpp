#include "Actuator.h"

Actuator::Actuator():actuatorMotor(MotorUnit(4)){

}
Actuator::Actuator(int aPin):actuatorMotor(MotorUnit(aPin)){
  speed=127;

}
Actuator::Actuator(int aPin,int s):actuatorMotor(MotorUnit(aPin)){
  speed=s;
}
void Actuator::setSpeed(int s){
  actuatorMotor.setSpeed(s);
}

void Actuator::Update(bool outPressed, bool inPressed){
  int aSpeed=0;
  if(outPressed){
    aSpeed=speed;
  }else if(inPressed){
    aSpeed=-speed;
  }
  setSpeed(aSpeed);
}
