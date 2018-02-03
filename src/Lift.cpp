#include "Lift.h"

void Lift::Update(bool R_Up,bool R_Down,bool L_Up,bool L_Down,bool U_Up,bool U_Down,int Macro){
  bool inputArray[6]={R_Up,R_Down,L_Up,L_Down,U_Up,U_Down};
  bool interupt=getInterrupt(Focus, inputArray);
  if(!interupt){
    if(!currentAction(RightLift,LeftLift,UpperLift,Focus,pins)){
      currentAction=Macro_3_Steady;
    }
  }else{
    if(Macro!=0){
      currentAction=myMacros[Macro];
    }else{
      Update(R_Up,R_Down, L_Up, L_Down, U_Up, U_Down);
    }
  }
}
void Lift::Update(bool R_Up,bool R_Down,bool L_Up,bool L_Down,bool U_Up,bool U_Down){
  RightLift.Update(R_Up, R_Down);
  LeftLift.Update( L_Up, L_Down);
  UpperLift.Update( U_Up, U_Down);
}
bool Lift::getInterrupt(bool focus[3],bool inputArray[6]){
  bool interrupt=false;
  for(unsigned int i=0;i<3;i++){
      interrupt=interrupt||(focus[i]&&(inputArray[2*i]||inputArray[2*i+1]));\
  }
  return interrupt;
}
bool Lift::Macro_1_Raise(Actuator RightLift,Actuator LeftLift,Actuator UpperLift,bool focus[3],int pins[6]){
  focus[0]=true;
  focus[1]=true;
  RightLift.Update(true,false);
  LeftLift.Update(true,false);
  return digitalRead(pins[4]);

}
bool Lift::Macro_2_Lower(Actuator RightLift,Actuator LeftLift,Actuator UpperLift,bool focus[3],int pins[6]){
  focus[0]=true;
  focus[1]=true;
  RightLift.Update(true,false);
  LeftLift.Update(true,false);
  return digitalRead(pins[3]);

}
bool Lift::Macro_3_Steady(Actuator RightLift,Actuator LeftLift,Actuator UpperLift,bool focus[3],int pins[3]){
  focus[0]=true;
  focus[1]=true;
  focus[2]=true;
  return true;
}
