#ifndef MACRO_H
#define MACRO_H
#include "API.h"
#include "DriveTrain.h"
#include "Lift.h"
#include "claw.h"
#include "pins.h"
#include <vector>

class Macro {
public:
  bool isActive;
  int pinBit;
  virtual bool activate();
  virtual Macro *Update();
  Macro(){};
  Macro(int pin_bits) {
    isActive = false;
    pinBit = pin_bits;
  };
};
//============================
// Drivetrain Macros
//============================
class ManualDrive : public Macro {
public:
  DriveTrain *drivetrain;
  ManualDrive() : Macro(RIGHT_DRIVETRAIN_BIT | LEFT_DRIVETRAIN_BIT) {
    drivetrain = new DriveTrain;
  };
  bool activate();
  Macro *Update();
};
class SpinDrive : public Macro {
public:
  DriveTrain *drivetrain;
  SpinDrive() : Macro(RIGHT_DRIVETRAIN_BIT | LEFT_DRIVETRAIN_BIT) { drivetrain = new DriveTrain; };
  bool activate();
  Macro *Update();
};
//============================
// Claw Macros
//============================
class SetClaw : public Macro {
public:
  Claw *claw;
  int targetTime;
  bool opening;
  SetClaw() : Macro(CLAW_BIT) {
    claw = new Claw;
    targetTime = 100;
    opening = false;
  };
  void init(int targettime, bool Opening);
  bool activate();
  Macro *Update();
};
class ToggleClaw : public Macro {
public:
  SetClaw setClaw;
  int openTime;
  bool opening;
  bool toggle;
  ToggleClaw() : Macro(CLAW_BIT) {
    openTime = 2000;
    opening = false;
    toggle = true;
  };
  bool activate();
  Macro *Update();
};
//============================
// Lift Macros
//============================
#include "Lift.h"
class ManualLift : public Macro {
public:
  Lift *lift;
  ManualLift() : Macro(RIGHT_LIFT_BIT | LEFT_LIFT_BIT) { lift = new Lift; };
  bool activate();
  Macro *Update();
};

#define NULL_MACRO ((Macro *)0)

#endif
