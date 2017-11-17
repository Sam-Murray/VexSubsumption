#include "ActuatorArray.h"
ActuatorArray::ActuatorArray(){
}

ActuatorArray::ActuatorArray(int pin1,int pin2):motors({Actuator( pin1),Actuator( pin2),Actuator(0),Actuator(0)}){

}

ActuatorArray::ActuatorArray(int pin1,int pin2,int pin3,int pin4):motors({Actuator( pin1),Actuator( pin2),Actuator(pin3),Actuator(pin4)}){
  motors[0]=Actuator( pin1);
  motors[1]=Actuator( pin2);
  motors[2]=Actuator(pin3);
  motors[3]=Actuator( pin3 );
}

void ActuatorArray::setSpeed(int index,int s){
  motors[index].setSpeed(s);
}

void ActuatorArray::setSpeed(int s1,int s2, int s3,int s4){
  motors[0].setSpeed(1);
  motors[1].setSpeed(2);
  motors[2].setSpeed(3);
  motors[3].setSpeed(4);
}
void ActuatorArray::setSpeed(int s){
  setSpeed(s,s,s,s);
}

void ActuatorArray::Update(bool outPressed, bool inPressed,int i1,int i2,int i3,int i4){
  motors[0].Update( inPressed, outPressed);
  motors[1].Update( outPressed, inPressed);

}
void ActuatorArray::Update(bool outPressed, bool inPressed){
  Update( outPressed,  inPressed,0,0,0,0);
}
