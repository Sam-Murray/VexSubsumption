// #include "Robot.h"
//
// Robot::Robot()
// {
// }
// Robot::Robot(int DRpin,int DLpin,int LRpin,int LLpin,int Cpin,int Ipin,int SLpin,int speedC){
//   driveT=DriveTrain(DRpin, DLpin,speedC);
//   liftL=Actuator(LLpin);
//   liftR=Actuator(LRpin);
//   intake=Actuator(Ipin);
//   claw=Claw(Cpin,50);
//   secondaryLift=Actuator(SLpin);
//
// }
// void Robot::Update(int joystickSlot)
// {
//   //Update(joystickGetAnalog(joystickSlot,L_MOVE),joystickGetAnalog(joystickSlot,R_MOVE),joystickGetDigital(joystickSlot,6,JOY_UP),joystickGetDigital(joystickSlot,6,JOY_DOWN),joystickGetDigital(joystickSlot,5,JOY_UP),joystickGetDigital(joystickSlot,5,JOY_DOWN),joystickGetDigital(joystickSlot,7,JOY_UP),joystickGetDigital(joystickSlot,7,JOY_DOWN),joystickGetDigital(joystickSlot,8,JOY_RIGHT),joystickGetDigital(joystickSlot,8,JOY_UP),joystickGetDigital(joystickSlot,8,JOY_DOWN));
//   driveT.Update(joystickGetAnalog(joystickSlot,L_MOVE),joystickGetAnalog(joystickSlot,R_MOVE));
//   liftL.Update(joystickGetDigital(joystickSlot,5,JOY_UP),joystickGetDigital(joystickSlot,5,JOY_DOWN));
//   liftR.Update(joystickGetDigital(joystickSlot,6,JOY_DOWN),joystickGetDigital(joystickSlot,6,JOY_UP));
//   intake.Update(joystickGetDigital(joystickSlot,7,JOY_UP),joystickGetDigital(joystickSlot,7,JOY_DOWN));
//   claw.Update(joystickGetDigital(joystickSlot,8,JOY_RIGHT));
//   secondaryLift.Update(joystickGetDigital(joystickSlot,8,JOY_DOWN),joystickGetDigital(joystickSlot,8,JOY_UP));
// }
// void Robot::Update(int LMOVE,int RMOVE,bool liftUpR,bool liftDownR,bool liftUpL,bool liftDownL,bool intakeUp,bool intakeDown,bool clawToggle,bool secondUp,bool secondDown)
// {
//   driveT.Update(L_MOVE,R_MOVE);
//   liftL.Update(liftUpL,liftDownL);
//   liftR.Update(liftDownR,liftUpR);
//   intake.Update(intakeUp,intakeDown);
//   claw.Update(clawToggle);
//   secondaryLift.Update(secondDown,secondUp);
// }
// void Robot::SpecialUpdate(int LMOVE,int RMOVE,bool liftUpR,bool liftDownR,bool liftUpL,bool liftDownL,bool intakeUp,bool intakeDown,bool clawSet,bool secondUp,bool secondDown)
// {
//   driveT.Update(LMOVE,RMOVE);
//   liftL.Update(liftUpL,liftDownL);
//   liftR.Update(liftDownR,liftUpR);
//   intake.Update(intakeUp,intakeDown);
//   claw.clawSet(clawSet);
//   secondaryLift.Update(secondDown,secondUp);
// }
