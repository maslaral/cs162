#ifndef DESK_HPP
#define DESK_HPP

#include "Office.hpp"
#include "Email.hpp"

#include <string>

class Desk : public Office {
  private:
    Email email1;
    Email email2;
    Email email3;
    Email email4;
    Email email5;
  public:
    Desk();
    ~Desk();
    int action();
};
#endif
