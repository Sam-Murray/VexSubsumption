#include "Macro.h"
#include "DriveTrain.h"

#define HISTORESIS(x) (abs(x) < 30 ? 0 : x)
//============================
// Drivetrain Macros
//============================

// manual drive macro
bool ManualDrive::activate() {
  return ((joystickGetAnalog(1, RIGHT_DRIVE_JOYSTICK_AXIS) *
           joystickGetAnalog(1, RIGHT_DRIVE_JOYSTICK_AXIS)) >= 49) ||
         ((joystickGetAnalog(1, LEFT_DRIVE_JOYSTICK_AXIS) *
           joystickGetAnalog(1, LEFT_DRIVE_JOYSTICK_AXIS)) >= 49);
}

Macro *ManualDrive::Update() {
  int read_R = joystickGetAnalog(1, RIGHT_DRIVE_JOYSTICK_AXIS);
  read_R = HISTORESIS(read_R);
  int read_L = joystickGetAnalog(1, LEFT_DRIVE_JOYSTICK_AXIS);
  read_L = HISTORESIS(read_L);
  if (read_R == 0 && read_L == 0) {
    drivetrain->Update(0, 0);
    return NULL_MACRO;
  } else {
    drivetrain->Update(read_L, read_R);
    return this;
  }
}
// Spings until interrupted
bool SpinDrive::activate() { return joystickGetDigital(1, 8, JOY_UP); }

Macro *SpinDrive::Update() {
  drivetrain->Update(-127, 127);
  return this;
}
//============================
// Claw Macros
//============================
void SetClaw::init(int targettime, bool Opening) { targetTime = targettime; };
bool SetClaw::activate() { return (false); }
Macro *SetClaw::Update() {
  if (targetTime > 0) {
    claw->Update(!opening, opening);
    targetTime--;
    return this;
  } else {
    claw->Update(false, false);
    return NULL_MACRO;
  }
}
bool ToggleClaw::activate() {
  toggle = true;
  if (joystickGetDigital(1, 8, JOY_LEFT)) {
    printf("aaaaaa\n");
  }
  return joystickGetDigital(1, 8, JOY_LEFT);
};
Macro *ToggleClaw::Update() {
  bool button = joystickGetDigital(1, 8, JOY_LEFT);
  toggle = toggle && button;
  printf("toggle %d\n", toggle);
  printf("butt%d\n", button);
  if (button && (!toggle)) {
    setClaw.init(10000, true);
    printf("open\n");
    return this;
  } else {
    printf("closed!\n");
    setClaw.init(1000, false);
    setClaw.Update();
    return this;
  }
};
//============================
// Lift Macros
//============================
bool ManualLift::activate() {

  return (joystickGetDigital(1, 6, JOY_UP) || joystickGetDigital(1, 6, JOY_DOWN)) &&
         !(joystickGetDigital(1, 6, JOY_UP) && joystickGetDigital(1, 6, JOY_DOWN));
}
Macro *ManualLift::Update() {
  // if (lift->getLowerLS() || lift->getUpperLS()) {
  //   return NULL_MACRO;
  // }
  bool upButton = (joystickGetDigital(1, 6, JOY_UP));
  bool downButton = (joystickGetDigital(1, 6, JOY_DOWN));
  if ((upButton || downButton) && !(upButton && downButton)) {

    int s = 127 * (upButton ? 1 : -1);
    // double angle = 250 * ((lift.getRightP() - lift.getLeftP()) / 4095);
    // if (angle < 0) {
    //   lift.setMotors(s, s * sin(angle));
    // } else {
    //   lift.setMotors(s * sin(angle), s);
    // }
    lift->setMotors(s, s);
    return this;
  } else {
    lift->setMotors(0, 0);
    return NULL_MACRO;
  }
}
