#ifndef ROBOT_H
#define ROBOT_H
#include "API.h"
#include "DriveTrain.h"
#include "Actuator.h"
#include "ActuatorArray.h"
#include "Claw.h"

class Robot{
public:
  Robot();
  Robot(int DRpin,int DLpin,int LRpin,int LLpin,int LURpin,int LULpin,int Cpin,int speedC); //constructor for ROBOT
  DriveTrain driveT;//drive train
  ActuatorArray lift;
  Claw claw;
  void Update(int joystickSlot);
};

#endif
