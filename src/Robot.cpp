#include "Robot.h"

Robot::Robot()
{
 claw=Claw();
}
Robot::Robot(int DRpin,int DLpin,int LRpin,int LLpin,int LURpin,int LULpin,int Cpin,int speedC){
  driveT=DriveTrain(DRpin, DLpin,speedC);
  lift=ActuatorArray(LRpin,LLpin,LURpin,LLpin);
  claw=Claw(Cpin);
}
void Robot::Update(int joystickSlot)
{
    bool liftup=joystickGetDigital(joystickSlot,5,JOY_UP);
    bool liftlower=joystickGetDigital(joystickSlot,5,JOY_DOWN);
    driveT.Update(joystickGetAnalog(joystickSlot,L_MOVE),joystickGetAnalog(joystickSlot,R_MOVE));
    lift.Update(liftup,liftlower);
    claw.Update(joystickGetDigital(joystickSlot,6,JOY_UP),joystickGetDigital(joystickSlot,6,JOY_DOWN));
}
