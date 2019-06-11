/*************************************************************
** Program name: Final
** Author: Alex Maslar
** Date: June 11 2019
** Description: 
*************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Office.hpp"

class Player {
	private:
    // player location
		Office* location;
    // whether or not the player is fired
		bool fired;
	public:
    // constructor and destructor
		Player();
		~Player();
    
    // setter functions
		void set_location(Office*);
		void set_employment_status(bool);
		
    // getter functions
		Office* get_location();
		bool get_employment_status();
};

#endif
