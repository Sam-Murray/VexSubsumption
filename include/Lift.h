#ifndef LIFT_H
#define LIFT_H
#include "API.h"
#include "Actuator.h"
#include "MotorUnit.h"
#include "pins.h"
class Lift {

public:
  // Lift motors: right side wired together, left side wired together, and the
  // upper lift.
  MotorUnit RightLift;
  MotorUnit LeftLift;
  // Integreated motor encoder pins: right side, left side, and upper.
  int P_pin_R;
  int P_pin_L;
  // Limit switch pins:
  int LS_pin_Main_Down;
  int LS_pin_Main_Up;

  int offset_L;
  int offset_R;

  Lift()
      : RightLift(MotorUnit(RIGHT_LIFT_PIN)),
        LeftLift(MotorUnit(LEFT_LIFT_PIN)) {
    offset_L = 556;
    offset_R = 1354;
  };
  bool getUpperLS();
  bool getLowerLS();
  int getLeftP();
  int getRightP();
  void setMotors(int R, int L);
};

#endif
