/*************************************************************
** Program name: Final
** Author: Alex Maslar
** Date: June 10 2019
** Description: Class header file for the Office abstract class.
   Contains the attributes room name and objective, which is 
   the goal for each room that is presented in the user menu.
   In addition, the Office abstract class includes pointers that
   point to adjacent derived Office classes.
*************************************************************/
#ifndef OFFICE_HPP
#define OFFICE_HPP

#include <string>

class Office {
  protected:
    std::string room_name;
    std::string objective;
    Office* top;
    Office* bottom;
    Office* left;
    Office* right;
  public:
    Office();
    virtual ~Office();
    
    // setter functions
    virtual void set_adjacent(Office*, Office*, Office*, Office*);
    virtual void set_room_name(std::string);

    // getter functions
    virtual Office* get_top();
    virtual Office* get_bottom();
    virtual Office* get_left();
    virtual Office* get_right();
    virtual std::string get_room_name();

    // gameplay function
    virtual int action() = 0;
};

#endif
