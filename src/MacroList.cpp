#include "MacroList.h"
Macro* MacroList::at(int index){
  if(index<end){
    return list[index];
  }else{
    return NULL_MACRO;
  }
}
void MacroList::clear(){
  end=0;
}
void MacroList::push(Macro *macro){
  if(end<MAX_LIST_LENGTH){
    list[end++]=macro;
  }
}
int MacroList::size(){
  return end;
}
MacroList::MacroList(){
  end=0;
}
