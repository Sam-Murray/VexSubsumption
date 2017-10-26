#include "Robot.h"

Robot::Robot()
{

}
Robot::Robot(int DRpin, int DLpin,int Lpin,int ILpin,int IRpin,int CLpin,int CUpin,int speedC){
  driveT=DriveTrain(DRpin, DLpin,speedC);
  lift=Actuator(Lpin,127);
  intake=ActuatorArray(ILpin,IRpin);
  upperClaw=Actuator(CUpin,50);
  lowerClaw=Actuator(CLpin,100);
}
void Robot::Update(int joystickSlot)
{
    driveT.Update(joystickGetAnalog(joystickSlot,L_MOVE),joystickGetAnalog(joystickSlot,R_MOVE));
    lift.Update(joystickGetDigital(joystickSlot,8,JOY_UP),joystickGetDigital(joystickSlot,8,JOY_DOWN));
    intake.Update(joystickGetDigital(joystickSlot,7,JOY_UP),joystickGetDigital(joystickSlot,7,JOY_DOWN),0,1,0,0);
    upperClaw.Update(joystickGetDigital(joystickSlot,5,JOY_UP),joystickGetDigital(joystickSlot,5,JOY_DOWN));
    lowerClaw.Update(joystickGetDigital(joystickSlot,6,JOY_UP),joystickGetDigital(joystickSlot,6,JOY_DOWN));
}
