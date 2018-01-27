#ifndef ROBOT_H
#define ROBOT_H
#include "API.h"
#include "DriveTrain.h"
#include "Actuator.h"
#include "ActuatorArray.h"
#include "Claw.h"

#define R_MOVE 2

#define L_MOVE 3

class Robot{
public:
  Robot();
  Robot(int DRpin,int DLpin,int LRpin,int LLpin,int Cpin,int Ipin,int SLpin,int speedC); //constructor for ROBOT
  DriveTrain driveT;//drive train
  Actuator liftL;
  Actuator liftR;
  Actuator intake;
  Claw claw;
  Actuator secondaryLift;
  void Update(int LMOVE,int RMOVE,bool liftUp,bool liftDown,bool intakeUp,bool intakeDown,bool clawToggle,bool secondUp,bool secondDown);
  void Update(int joystickSlot);
  void SpecialUpdate(int LMOVE,int RMOVE,bool liftUp,bool liftDown,bool intakeUp,bool intakeDown,bool clawSet,bool secondUp,bool secondDown);
};

#endif
