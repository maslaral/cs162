#include "Desk.hpp"
#include "Menu.hpp"

Desk::Desk(){
  inbox = new Inbox;
}

Desk::~Desk(){
}

int Desk::action(){
  int time_taken = 0;
  return time_taken;
}

Inbox* Desk::get_inbox(){
  return inbox;
}
