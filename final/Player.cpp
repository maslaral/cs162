/*************************************************************
** Program name:
** Author: Alex Maslar
** Date: June 10 2019
** Description: Player object
*************************************************************/
#include "Player.hpp"

Player::Player(){
	fired = false;
}

Player::~Player(){
}

void Player::set_location(Office* location){
	this->location = location;
}

Office* Player::get_location(){
	return location;
}

void Player::set_employment_status(bool fired){
	this->fired = fired;
}

bool Player::get_employment_status(){
	return fired;
}
