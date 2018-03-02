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
  SpinDrive() : Macro(RIGHT_DRIVETRAIN_BIT | LEFT_DRIVETRAIN_BIT) {
    drivetrain = new DriveTrain;
  };
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
  Claw claw;
  int timer;
  bool opening;
  bool toggle;
  ToggleClaw() : Macro(CLAW_BIT) {
    timer = 2000;
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
class StableLift : public Macro {
public:
  Lift *lift;
  int R_stable;
  int L_stable;
  void init(int rstable, int lstable);
  StableLift() : Macro(RIGHT_LIFT_BIT | LEFT_LIFT_BIT) {
    lift = new Lift;
    R_stable = 0;
    L_stable = 0;
  };
  bool activate();
  Macro *Update();
};
//============================
// Upper Lift Macros
//============================
class UpperLift : public Macro {
public:
  Actuator upperlift;
  UpperLift() : Macro(UPPER_LIFT_BIT) { upperlift = Actuator(UPPER_LIFT_PIN); };
  bool activate();
  Macro *Update();
};
//============================
// Intake Macros
//============================
class Intake : public Macro {
public:
  Actuator intake;
  Intake() : Macro(INTAKE_BIT) { intake = Actuator(INTAKE_PIN); };
  bool activate();
  Macro *Update();
};

class Stack : public Macro {
public:
  Claw claw;
  Lift lift;
  Actuator upperLift;
  int timer;
  Stack() : Macro(LEFT_LIFT_BIT | RIGHT_LIFT_BIT | UPPER_LIFT_BIT | CLAW_BIT) {
    upperLift = Actuator(UPPER_LIFT_PIN);
    timer = 10000;
  };
  bool activate();
  Macro *Update();
};

class Autonomous : public Macro {
public:
  DriveTrain drive;
  Actuator intake;
  Actuator upperLift;
  int timer;
  Autonomous()
      : Macro(UPPER_LIFT_BIT | RIGHT_DRIVETRAIN_BIT | LEFT_DRIVETRAIN_BIT |
              INTAKE_BIT) {
    upperLift = Actuator(UPPER_LIFT_PIN);
    timer = 50000;
  };
  bool activate();
  Macro *Update();
};
#define NULL_MACRO ((Macro *)0)

#endif
