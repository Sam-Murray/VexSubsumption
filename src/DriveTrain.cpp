#include "DriveTrain.h"
DriveTrain::DriveTrain():L(MotorUnit(3)), R(MotorUnit(2)) {
  speedConvertion=1;
}

DriveTrain::DriveTrain(int Rpin, int Lpin,int speedC):L(MotorUnit(Lpin)), R(MotorUnit(Rpin)) {
  speedConvertion=speedC;
}
void DriveTrain::MotorSet(int Rs, int Ls){
  R.setSpeed(Rs);
  L.setSpeed(Ls);
}
void DriveTrain::allMotorSet(int speed){
  MotorSet(speed,speed);
}


void DriveTrain::Update(int LMove, int RMove){
  double moveSpeedR=RMove;
  double moveSpeedL=LMove;
  if(moveSpeedR<=4 && moveSpeedR>=-4){//prevents annoying miro-inputs
    moveSpeedR=0;
  }
  if(moveSpeedL<=4 && moveSpeedL>=-4){//prevents annoying miro-inputs
    moveSpeedL=0;
  }
    MotorSet(-moveSpeedR,moveSpeedL);
}
DriveTrain *drivetrain=new DriveTrain();
