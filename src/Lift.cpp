#include "Lift.h"

void Update(bool R_Up,bool R_Down,bool L_Up,bool L_Down,bool U_Up,bool U_Down,int Macro){
  bool interupt=R_Up||R_Down||L_Up||L_Down||U_Up||U_Down||Macro;
  if(!interupt){
    if(!currentAction()){
      currentAction=Macro_3_Steady
    }
  }else{
    if(Macro!=0){
      currentAction
    }else{
      Update(R_Up,R_Down, L_Up, L_Down, U_Up, U_Down);
    }
  }
}
void Update(bool R_Up,bool R_Down,bool L_Up,bool L_Down,bool U_Up,bool U_Down){
  RightLift.Update(R_Up, R_Down);
  LeftLift.Update( L_Up, L_Down);
  UpperLift.Update( U_Up, U_Down);
}
bool Macro_1_Raise(Actuator RightLift,Actuator LeftLift,bool focus[5]){

}
bool Macro_2_Lower(Actuator RightLift,Actuator LeftLift){

}
bool Macro_3_Steady(Actuator RightLift,Actuator LeftLift){

}
