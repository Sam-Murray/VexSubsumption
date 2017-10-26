#ifndef ROBOT_H
#define ROBOT_H
#include "API.h"
#include "DriveTrain.h"
#include "Actuator.h"
#include "ActuatorArray.h"


#define R_MOVE 2

#define L_MOVE 3

class Robot{
public:
  Robot();
  Robot(int DRpin, int DLpin,int Lpin,int ILpin,int IRpin,int CLpin,int CUpin,int speedC); //constructor for ROBOT
  DriveTrain driveT;//drive train
  Actuator lift;
  ActuatorArray intake;
  Actuator upperClaw;
  Actuator lowerClaw;
  void Update(int joystickSlot);
};

#endif
