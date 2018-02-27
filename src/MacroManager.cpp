#include "MacroManager.h"

MacroManager::MacroManager() {
  allMacros = new MacroList;
  standbyMacros = new MacroList;
  activeMacros = new MacroList;

  allMacros->push(new SpinDrive());
  allMacros->push(new ManualDrive());
  allMacros->push(new ToggleClaw());
  allMacros->push(new ManualLift());
}

void MacroManager::runMacros() {
  for (int m = activeMacros->size() - 1; m >= 0; m--) {
    Macro *macro = activeMacros->at(m)->Update();
    activeMacros->at(m)->isActive = false;
    if (macro != NULL_MACRO) {
      standbyMacros->push(macro);
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
      standbyMacros->at(m)->isActive = true;
      activeMacros->push(standbyMacros->at(m));
      accumulater |= standbyMacros->at(m)->pinBit;
    }
  }
}
void MacroManager::Update() { runMacros(); }
