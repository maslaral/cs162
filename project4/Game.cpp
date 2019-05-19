/*************************************************************
** Program name: Project 3
** Author: Alex Maslar
** Date: May 12 2019
** Description: Game functions used to create players,
   coordinate the game and when the game is over, and call
   functions to attack, defend, and inflict damage. 
*************************************************************/
#include "Game.hpp"
#include <iostream>

/*************************************************************
** Description: Default constructor for the Game object.
*************************************************************/
Game::Game(){
}

/*************************************************************
** Description: Destuctor for the Game object.
*************************************************************/
Game::~Game(){
}

/*************************************************************
** Description: Create players and coordinate game play - also
   output result of match
*************************************************************/
void Game::play(character_type p_one, character_type p_two){
  // call create player function
  Character* player_one = create_player(p_one);
  Character* player_two = create_player(p_two);

  // play until one player is no longer alive
  while (player_one->alive() && player_two->alive()){
    play_round(player_one, player_two);
    if (player_two->alive()){
      play_round(player_two, player_one);
    }
  }

  // if player one is still alive, declare them the winner
  if (player_one->alive()){
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Player 1 " << player_one->get_type() << " wins!" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    winners.add_winner(player_one);
  }
  // if player two is still alive, declare them the winner
  else {
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Player 2 " << player_two->get_type() << " wins!" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    winners.add_winner(player_two);
  }

  // deallocate players
  delete player_one;
  delete player_two;
}

/*************************************************************
** Description: Creates the players based on the type input
   by the user
*************************************************************/
Character* Game::create_player(character_type type){
  switch (type){
    case BARBARIAN:
    {
      Character* barbarian = new Barbarian();
      return barbarian;
    }
    break;
    case VAMPIRE:
    {
      Character* vampire = new Vampire();
      return vampire;
    }
    break;
    case BLUE_MEN:
    {
      Character* blue_men = new Blue_Men();
      return blue_men;
    }
    break;
    case MEDUSA:
    {
      Character* medusa = new Medusa();
      return medusa;
    }
    break;
    case HARRY_POTTER:
    {
      Character* harry_potter = new Harry_Potter();
      return harry_potter;
    }
    break;
    default:
    {
      return 0;
    }
  }
}

/*************************************************************
** Description: Plays each round of game, calls functions
   for attacking and defending, calculates the resulting damage,
   and outputs the result of each round.
*************************************************************/
void Game::play_round(Character* attacker, Character* defender){
  int damage = 0;
  int attack_points, defense_points, armor, defender_ending_strength;

  // present the beginning values to the user
  get_round_start_values(attacker, defender);
  
  // calling the attack and defend functions
  attack_points = attacker->attack();
  defense_points = defender->defense();
  armor = defender->get_armor();

  // calculating the total damage
  damage = attack_points - defense_points - armor;

  // if damage is less than zero, then set to zero
  if (damage < 0){
    damage = 0;
  }

  // inflict damage on the defender
  defender->inflict_damage(damage);
  defender_ending_strength = defender->get_strength();

  // vampire charm
  if (defense_points == 100){
    return;
  }

  // medusa attack
  if (damage >= 82){
    return;
  }
  
  // set ending strength to 0 if it's negative
  if (defender_ending_strength < 0){
    defender_ending_strength = 0;
  }

  // output results from round
  std::cout << "Attack: " << attack_points << std::endl;
  std::cout << "Defense: " << defense_points << std::endl;
  std::cout << "Damage: " << damage << std::endl;
  std::cout << "Defender Ending Strength: " << defender_ending_strength << std::endl;
}

/*************************************************************
** Description: Prints the round result values
*************************************************************/
void Game::get_round_start_values(Character* attacker, Character* defender){
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "                ROUND RESULTS                " << std::endl;
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "Attacker Type: " << attacker->get_type() << std::endl;
  std::cout << "Defender Type: " << defender->get_type() << std::endl;
  std::cout << "Defender Armor: " << defender->get_armor() << std::endl;
  std::cout << "Defender Starting Strength: " << defender->get_strength() << std::endl;
}
