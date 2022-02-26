#include "Statemachine.h"
#include <cctype>
enum Statemachine::State: unsigned short {
  begin, middle, end // only usable in .cpp
};
Statemachine::Statemachine() : theState{begin} {}
void Statemachine::processInput(char const c) {
  switch(theState){
  case begin :
    if (! isspace(c))
      theState = middle;
    break;
  case middle :
    if (isspace(c))
      theState = end;
    break;
  case end : break;// ignore input
  }
}
bool Statemachine::isDone()const{
  return theState == end;
}
