#include "MacroManager.h"

MacroManager::MacroManager() {
  allMacros = new MacroList;
  standbyMacros = new MacroList;
  activeMacros = new MacroList;
  allMacros->push(new Autonomous());
  allMacros->push(new Stack());
  allMacros->push(new ManualDrive());
  allMacros->push(new ToggleClaw());
  allMacros->push(new UpperLift());
  allMacros->push(new Intake());
  allMacros->push(new ManualLift());
}
MacroManager::MacroManager() {
  allMacros = new MacroList;
  standbyMacros = new MacroList;
  activeMacros = new MacroList;
  allMacros->push(new Autonomous())
}

void MacroManager::runMacros() {
  for (int m = activeMacros->size() - 1; m >= 0; m--) {
    Macro *macro = activeMacros->at(m)->Update();

    if (macro != NULL_MACRO) {
      standbyMacros->push(macro);
    } else {
    }
  }

  activeMacros->clear();
  activateMacros();
  standbyMacros->clear();
}
void MacroManager::activateMacros() {
  for (int m = 0; m < allMacros->size(); m++) {
    if ((!allMacros->at(m)->isActive) && (allMacros->at(m)->activate())) {
      standbyMacros->push(allMacros->at(m));
    }
  }
  detectInterupt();
}
void MacroManager::detectInterupt() {
  int accumulater = 0;
  for (int m = standbyMacros->size() - 1; m >= 0; m--) {
    if (!(accumulater & standbyMacros->at(m)->pinBit)) {
      activeMacros->push(standbyMacros->at(m));
      standbyMacros->at(m)->isActive = true;
      accumulater |= standbyMacros->at(m)->pinBit;
    } else {
      standbyMacros->at(m)->isActive = false;
    }
  }
}
void MacroManager::Update() { runMacros(); }
