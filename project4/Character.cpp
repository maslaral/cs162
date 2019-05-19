#include "Character.hpp"

Character::Character(){
}

Character::~Character(){
}

/*************************************************************
** Description:
*************************************************************/
Character* Character::get_next(){
	return next;
}

/*************************************************************
** Description:
*************************************************************/
void Character::set_next(Character* next){
	this->next = next;	
}
