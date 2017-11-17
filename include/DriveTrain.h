#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H
#include "MotorUnit.h"
#include "API.h"
#include "math.h"

class DriveTrain{
private:
  // MotorUnit FR; //front right motor
  // MotorUnit FL; //front left motor
  MotorUnit L;//back left motor
  MotorUnit R;//back right motor
  int speedConvertion;
  void allMotorSet(int speed);
  void MotorSet(int Rs, int Ls);
  // void MotorSet(int FRs, int FLs, int BLs, int BRs);

public:
  DriveTrain();
  DriveTrain(int Rpin, int Lpin,int speedC);
  void Update(int L_MOVE, int R_MOVE);
};



#endif
