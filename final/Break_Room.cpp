#include "Break_Room.hpp"
#include "Menu.hpp"

#include <iostream>

/*************************************************************
** Description:
*************************************************************/
Break_Room::Break_Room(){
}

/*************************************************************
** Description:
*************************************************************/
Break_Room::~Break_Room(){
}

/*************************************************************
** Description:
*************************************************************/
int Break_Room::action(){
  int time_taken = 0;

  std::cout << "Your coworker " << employee->get_name() << " approaches you for a conversation." << std::endl;
  std::cout << "Do your best to get out of the conversation as fast" << std::endl;
  std::cout << "as possible without being too blunt." << std::endl;
  
  // initialize the menu
  Menu stop_talking("What is your reply?");
  stop_talking.addOptions("Mhmmmm");
  stop_talking.addOptions("Well that's nice...");
  stop_talking.addOptions("Well, anyway...");
  stop_talking.addOptions("I don't have time for this.");

  // keep talking to employee until she is out of talkative points
  while (employee->get_talkative_level() > 0){
    std::cout << "employee: Blah blah blah blah" << std::endl;
    stop_talking.outputMenu();
    switch (stop_talking.getUserInput()){
      case 1:
        employee->reduce_talkative_level(1);
        std::cout << "Response reudced talkative level by 1" << std::endl;
        break;
      case 2:
        employee->reduce_talkative_level(0);
        std::cout << "Response was ineffective" << std::endl;
        break;
      case 3:
        employee->reduce_talkative_level(2);
        std::cout << "Response reudced talkative level by 2" << std::endl;
        break;
      case 4:
        employee->reduce_talkative_level(0);
        std::cout << "Response was too blunt and you're fired" << std::endl;
        break;
    }
    time_taken += 10; 
  }
  return time_taken;
}

/*************************************************************
** Description:
*************************************************************/
void Break_Room::set_employee_characteristics(std::string name, int talkative_level){
  employee->set_name(name);
  employee->set_talkative_level(talkative_level);
}
