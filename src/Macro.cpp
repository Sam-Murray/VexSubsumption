#include "Macro.h"
#include "DriveTrain.h"

#define HISTORESIS(x) (abs(x) < 30 ? 0 : x)
//============================
// Drivetrain Macros
//============================

// manual drive macro
bool ManualDrive::activate() {
  if (((joystickGetAnalog(1, RIGHT_DRIVE_JOYSTICK_AXIS) *
        joystickGetAnalog(1, RIGHT_DRIVE_JOYSTICK_AXIS)) >= 49) ||
      ((joystickGetAnalog(1, LEFT_DRIVE_JOYSTICK_AXIS) *
        joystickGetAnalog(1, LEFT_DRIVE_JOYSTICK_AXIS)) >= 49)) {
  }
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
    isActive = false;
    return NULL_MACRO;
  } else {
    drivetrain->Update(read_L, read_R);
    return this;
  }
}
// Spings until interrupted
bool SpinDrive::activate() { return joystickGetDigital(1, 7, JOY_LEFT); }

Macro *SpinDrive::Update() {
  drivetrain->Update(-127, 127);
  return this;
}
//============================
// Claw Macros
//============================
void SetClaw::init(int targettime, bool Opening) {
  targetTime = targettime;
  opening = Opening;
};
bool SetClaw::activate() { return (false); }
Macro *SetClaw::Update() {
  isActive = true;
  if (targetTime > 0) {
    claw->Update(!opening, opening);
    targetTime--;
    return this;
  } else {
    isActive = false;
    claw->Update(false, false);
    return NULL_MACRO;
  }
}
bool ToggleClaw::activate() {
  toggle = joystickGetDigital(1, 8, JOY_LEFT);

  return toggle;
};
Macro *ToggleClaw::Update() {

  bool button = joystickGetDigital(1, 8, JOY_LEFT);
  printf("Toggle:%d", toggle);
  printf("Button:%d", button);
  if (toggle && button) {
    opening = !opening;
    timer = 500;
  }
  printf("I'm the thing:%d", digitalRead(LS_CLAW_PIN));
  if ((timer > 0)) {
    timer--;
    printf("is Opening:%d\n", opening);
    claw.Update(opening, !opening);
  } else {
    claw.Update(false, false);
    printf("doing nothing\n");
  }
  toggle = !button;
  return this;
};
//============================
// Lift Macros
//============================
bool ManualLift::activate() {
  bool liftBool =
      (joystickGetDigital(1, 6, JOY_UP) ||
       joystickGetDigital(1, 6, JOY_DOWN)) &&
      !(joystickGetDigital(1, 6, JOY_UP) && joystickGetDigital(1, 6, JOY_DOWN));

  isActive = liftBool || isActive;
  return liftBool;
}
Macro *ManualLift::Update() {
  // if (lift->getLowerLS() || lift->getUpperLS()) {
  //   return NULL_MACRO;
  // }
  bool upButton = (joystickGetDigital(1, 6, JOY_UP));
  bool downButton = (joystickGetDigital(1, 6, JOY_DOWN));
  if ((upButton || downButton) && !(upButton && downButton)) {

    int s = 127 * (upButton ? -1 : 1);
    // double angle = 250 * ((lift.getRightP() - lift.getLeftP()) / 4095);
    // if (angle < 0) {
    //   lift.setMotors(s, s * sin(angle));
    // } else {
    //   lift.setMotors(s * sin(angle), s);
    // }
    lift->setMotors(s, -s);
    return this;
  } else {
    lift->setMotors(0, 0);
    isActive = false;
    return NULL_MACRO;
  }
}
bool StableLift::activate() {

  if (joystickGetDigital(1, 7, JOY_RIGHT)) {
    printf("AAAAHHHH\n");
    init(lift->getRightP(), lift->getLeftP());
  }

  return joystickGetDigital(1, 7, JOY_RIGHT);
}
void StableLift::init(int rstable, int lstable) {
  R_stable = rstable;
  L_stable = lstable;
}
Macro *StableLift::Update() {
  if (lift->getUpperLS() || lift->getLowerLS()) {
    printf("I'm In the Bad place\n");
    return NULL_MACRO;
  } else {
    int angle_R = lift->getRightP() - lift->offset_R;
    int angle_L = lift->getLeftP() - lift->offset_L;
    int motorSet_R = 0;
    int motorSet_L = 0;
    printf("Angle L: %d\n", angle_L);
    printf("target L: %d\n", L_stable);
    printf("Angle R: %d\n", angle_R);
    printf("target R: %d\n", R_stable);
    if ((angle_L < L_stable) && (abs(angle_L - L_stable) < 100)) {
      motorSet_L = 100;
    } else if (angle_L > L_stable && (abs(angle_L - L_stable) < 100)) {
      motorSet_L = -100;
    }
    // if (angle_L > angle_R) {
    //   motorSet_L -= 20;
    //   motorSet_R += 20;
    // } else if (angle_L < angle_R) {
    //   motorSet_L += 20;
    //   motorSet_R -= 20;
    // }
    lift->setMotors(motorSet_L, motorSet_L);
    return this;
  }
}

bool UpperLift::activate() {
  return (joystickGetDigital(1, 5, JOY_UP) ||
          joystickGetDigital(1, 5, JOY_DOWN)) &&
         !(joystickGetDigital(1, 5, JOY_UP) &&
           joystickGetDigital(1, 5, JOY_DOWN));
}
Macro *UpperLift::Update() {
  bool upButt = joystickGetDigital(1, 5, JOY_DOWN);
  bool downButt = joystickGetDigital(1, 5, JOY_UP);
  if (!(upButt && downButt)) {
    if (upButt) {
      upperlift.Update(true, false);
      return this;
    } else if (downButt) {
      upperlift.Update(false, true);
      return this;
    } else {
      upperlift.Update(false, false);
      isActive = false;
      return NULL_MACRO;
    }
  } else {
    isActive = false;
    return NULL_MACRO;
  }
}
bool Intake::activate() {
  if ((joystickGetDigital(1, 7, JOY_UP) ||
       joystickGetDigital(1, 7, JOY_DOWN)) &&
      !(joystickGetDigital(1, 7, JOY_UP) &&
        joystickGetDigital(1, 7, JOY_DOWN))) {
  }
  return ((joystickGetDigital(1, 7, JOY_UP) ||
           joystickGetDigital(1, 7, JOY_DOWN)) &&
          !(joystickGetDigital(1, 7, JOY_UP) &&
            joystickGetDigital(1, 7, JOY_DOWN)));
}
Macro *Intake::Update() {
  bool upButt = joystickGetDigital(1, 7, JOY_DOWN);
  bool downButt = joystickGetDigital(1, 7, JOY_UP);
  if (!(upButt && downButt)) {
    if (upButt) {
      intake.Update(true, false);
      return this;
    } else if (downButt) {
      intake.Update(false, true);
      return this;
    } else {
      intake.Update(false, false);
      isActive = false;
      return NULL_MACRO;
    }
  } else {
    isActive = false;
    return NULL_MACRO;
  }
}
bool Stack::activate() {
  timer = 10000;
  return joystickGetDigital(1, 7, JOY_RIGHT);
}
Macro *Stack::Update() {
  if (timer > 7000) {
    printf("going: %d\n", timer);

    lift.setMotors(-127, 127);
    claw.Update(false, true);
    upperLift.Update(false, true);
    timer--;
    return this;
  } else if (timer > 6100) {
    upperLift.Update(true, false);
    printf("going part 2: %d\n", timer);
    claw.Update(false, true);
    timer--;
  } else if (timer > 6400) {
    printf("going part 3: %d\n", timer);
    upperLift.Update(false, true);
    claw.Update(false, true);
    timer--;
  } else if (timer > 5500) {
    upperLift.Update(false, false);
    printf("going part 4: %d\n", timer);
    lift.setMotors(127, -127);
    claw.Update(false, true);
    timer--;
    return this;
  } else {
    lift.setMotors(0, 0);
    claw.Update(false, false);
    isActive = false;
    return NULL_MACRO;
  }
  return NULL_MACRO;
}
bool Autonomous::activate() { return joystickGetDigital(1, 7, JOY_LEFT); }
Macro *Autonomous::Update() {
  if (timer > 49000) {
    intake.Update(true, false);
    timer--;
    return this;
  } else if (timer > 39000) {
    intake.Update(false, false);
    timer--;
    return this;
    drive.Update(127, 127);
  } else if (timer > 38000) {
    intake.Update(false, true);
    return this;
    timer--;
  } else if (timer > 33000) {
    drive.Update(-127, 127);
    return this;
    timer--;
  } else if (timer > 23000) {
    drive.Update(127, 127);
    return this;
    timer--;
  } else if (timer > 22000) {
    intake.Update(true, false);
    return this;
    timer--;
  }
}
