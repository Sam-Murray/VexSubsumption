#ifndef LIFT_H
#define LIFT_H
#include "MotorUnit.h"
#include "API.h"
#include "Actuator.h"
class Lift{
private:
  //Lift motors: right side wired together, left side wired together, and the upper lift.
  Actuator RightLift;
  Actuator LeftLift;
  Actuator UpperLift;
  //Integreated motor encoder pins: right side, left side, and upper.
  int IME_pin_R;
  int IME_pin_L;
  int IME_pin_U;
  //Limit switch pins: right side, left side, and upper.
  int LS_pin_Main_Down;
  int LS_pin_Main_Up;
  int LS_pin_Upper;
  //pin array;
  int pins[6]={0,0,0,0,0,0};
  //current action is a pointer to the current task. Should default to Macro_3 as long as not intterupted by button presses.
  //Holds focus of some motors, but not all of them, so button presses to these motors shouldn't innterupt
  bool (*currentAction)(Actuator RightLift,Actuator LeftLift,Actuator UpperLift,bool focus[3],int pins[3]);
  //The Macros. Pretty self explainitory.
  static bool Macro_1_Raise(Actuator RightLift,Actuator LeftLift,Actuator UpperLift,bool focus[3],int pins[3]);
  static bool Macro_2_Lower(Actuator RightLift,Actuator LeftLift,Actuator UpperLift,bool focus[3],int pins[3]);
  static bool Macro_3_Steady(Actuator RightLift,Actuator LeftLift,Actuator UpperLift,bool focus[3],int pins[3]);
  //List of pointers to Macros
  bool (*myMacros[3])(Actuator RightLift,Actuator LeftLift,Actuator UpperLift,bool focus[3],int pins[3]);
  //Focused motors
  bool Focus[3]={false,false,false};
  //Functions for Macros stuff
  static bool getInterrupt(bool focus[3],bool inputArray[6]);
  public:
  Lift();
  Lift(int pinR, int pinL,int pinU,int IME_Right,int IME_Left,int IME_Upper,int LS_Down,int LS_Up,int LS_Upper):RightLift(Actuator(pinR)),LeftLift(Actuator(pinL)),UpperLift(Actuator(pinU)){
    IME_pin_R=IME_Right;
    IME_pin_L=IME_Left;
    IME_pin_U=IME_Upper;
    LS_pin_Main_Down=LS_Down;
    LS_pin_Main_Up=LS_Up;
    LS_pin_Upper=LS_Upper;
    myMacros[0]= Macro_1_Raise;
    myMacros[1]=Macro_2_Lower;
    myMacros[2]=Macro_3_Steady;
    pins[0]=IME_Right;
    pins[1]=IME_Left;
    pins[2]=IME_Upper;
    pins[3]=LS_Down;
    pins[4]=LS_Up;
    pins[5]=LS_Upper;
  };
  void Update(bool R_Up,bool R_Down,bool L_Up,bool L_Down,bool U_Up,bool U_Down);
  void Update(bool R_Up,bool R_Down,bool L_Up,bool L_Down,bool U_Up,bool U_Down,int Macro);
};

#endif
