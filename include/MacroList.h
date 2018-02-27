#ifndef MACROLIST_H
#define MACROLIST_H
#include "Macro.h"
#define MAX_LIST_LENGTH 32
class MacroList{
public:
  Macro* list[MAX_LIST_LENGTH];
  int end;
  Macro* at(int index);
  void push(Macro*);
  void clear();
  int size();
  MacroList();
};
#endif
