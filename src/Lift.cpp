#include "Lift.h"

bool Lift::getUpperLS() { return digitalRead(LS_TOP_LIFT_PIN); }
bool Lift::getLowerLS() { return digitalRead(LS_BOTTOM_LIFT_PIN); }
int Lift::getLeftP() { return analogRead(P_LEFT_LIFT_PIN); }
int Lift::getRightP() { return analogRead(P_RIGHT_LIFT_PIN); }
void Lift::setMotors(int R, int L) {
  RightLift.setSpeed(R);
  LeftLift.setSpeed(L);
}
