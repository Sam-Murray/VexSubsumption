#ifndef CLAW_H
#define CLAW_H
#include "API.h"
#include "Actuator.h"
#include "pins.h"

class Claw {
private:
  Actuator claw;

public:
  Claw() { claw = Actuator(CLAW_PIN); }
  bool getLS() { return digitalRead(LS_CLAW_PIN); }
  void Update(bool open, bool close) { claw.Update(open, close); }
};

#endif
