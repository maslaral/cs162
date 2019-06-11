/*************************************************************
** Program name: Final
** Author: Alex Maslar
** Date: June 10 2019
** Description: Employee class - used for Angela
*************************************************************/
#include "Employee.hpp"

Employee::Employee(){
}

Employee::~Employee(){
}

void Employee::reduce_talkative_level(int i){
  talkative_level -= i;
}

int Employee::get_talkative_level(){
  return talkative_level;
}

std::string Employee::get_name(){
  return name;
}

void Employee::set_talkative_level(int talkative_level){
  this->talkative_level = talkative_level;
}

void Employee::set_name(std::string name){
  this->name = name;
}
