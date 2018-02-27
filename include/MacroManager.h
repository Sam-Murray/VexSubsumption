#ifndef MACROMANAGER_H
#define MACROMANAGER_H
#include <vector>
#include "Macro.h"
#include "MacroList.h"

class MacroManager{
public:
//list of active macros.
MacroList *activeMacros;
//list of all macros, ordered by way of priority
MacroList *allMacros;
//Update function, called every frame, checks macro list
MacroList *standbyMacros;
//Update function, called every frame, checks macro list
void Update();
//Runs macro on active list
void runMacros();
//Adds all excited macros to the active macro list
void activateMacros();

void detectInterupt();

MacroManager();

};
#endif
