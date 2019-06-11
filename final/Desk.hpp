#ifndef DESK_HPP
#define DESK_HPP

#include "Office.hpp"
#include "Inbox.hpp"

#include <string>

class Desk : public Office {
  private:
    Inbox* inbox;
  public:
    Desk();
    ~Desk();
    int action();
    Inbox* get_inbox();
};

#endif
