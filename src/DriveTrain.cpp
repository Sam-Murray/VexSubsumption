#include "DriveTrain.h"
DriveTrain::DriveTrain():R(MotorUnit(2)), L(MotorUnit(3)){
  speedConvertion=1;
}

DriveTrain::DriveTrain(int Rpin, int Lpin,int speedC):R(MotorUnit(Rpin)), L(MotorUnit(Lpin)){
  speedConvertion=speedC;
}
void DriveTrain::MotorSet(int Rs, int Ls){
  R.setSpeed(Rs);
  L.setSpeed(Ls);
}
void DriveTrain::allMotorSet(int speed){
  // FR.setSpeed(-speed);
  // FL.setSpeed(speed);
  // BL.setSpeed(speed);
  // BR.setSpeed(-speed);
  MotorSet(speed,speed);
}


void DriveTrain::Update(int LMove, int RMove){
  //Working X Y translation
  // if(abs(yMove) >= abs(xMove)){
  //   allMotorSet(yMove/speedConvertion);
  // }
  // if(abs(xMove) >= abs(yMove)){
  //   allMotorSetStrafe(xMove/speedConvertion);
  // }
  //strafe code
  double moveSpeedR=RMove;
  double moveSpeedL=LMove;
  if(moveSpeedR<=4 && moveSpeedR>=-4){//prevents annoying miro-inputs
    moveSpeedR=0;
  }
  if(moveSpeedL<=4 && moveSpeedL>=-4){//prevents annoying miro-inputs
    moveSpeedL=0;
  }
    MotorSet(-moveSpeedR,moveSpeedL);
  // if(xMove > 0 && yMove >= 0 ){// 1st quadrant
  //   dFR=(int)moveSpeed*-1;
  //   dFL=(int)moveSpeed*cos(2*unroundedAngle)*-1;
  //   dBL=(int)moveSpeed;
  //   dBR=(int)moveSpeed*cos(2*unroundedAngle);
  // }
  // if(xMove >= 0 && yMove < 0 ){//2nd quadrant
  //   dFR=(int)moveSpeed*cos(2*unroundedAngle)*-1;
  //   dFL=(int)moveSpeed*-1;
  //   dBL=(int)moveSpeed*cos(2*unroundedAngle);
  //   dBR=(int)moveSpeed;
  // }
  // if(xMove < 0 && yMove <= 0 ){//3rd quadrant
  //   dFR=(int)moveSpeed;
  //   dFL=(int)moveSpeed*cos(2*unroundedAngle);
  //   dBL=(int)moveSpeed*-1;
  //   dBR=(int)moveSpeed*cos(2*unroundedAngle)*-1;
  //
  // }
  // if(xMove <= 0 && yMove > 0 ){//4th quadrant
  //   dFR=(int)moveSpeed*cos(2*unroundedAngle);
  //   dFL=(int)moveSpeed;
  //   dBL=(int)moveSpeed*cos(2*unroundedAngle)*-1;
  //   dBR=(int)moveSpeed*-1;
  //
  // }
  // dFR += -xTurn/speedConvertion;
  // dFL += -xTurn/speedConvertion;
  // dBL += -xTurn/speedConvertion;
  // dBR += -xTurn/speedConvertion;
  // dFR += -xTurn/4;
  // dFL += -xTurn/4;
  // dBL += -xTurn/4;
  // dBR += -xTurn/4;


}
