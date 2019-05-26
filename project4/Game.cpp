/*************************************************************
** Program name: Project 4
** Author: Alex Maslar
** Date: May 21 2019
** Description:
*************************************************************/
#include "Game.hpp"

/************************************************************* ** Description: Default constructor for the Game object.
*************************************************************/
Game::Game(){
  team_one_score = 0;
  team_two_score = 0;
  player = nullptr;
}

/*************************************************************
** Description: Destuctor for the Game object.
*************************************************************/
Game::~Game(){
}

/*************************************************************
** Description: Add player to team - takes an integer as an
   argument which determines which team to add the player to.
*************************************************************/
void Game::add_team(int team){
  // store name of player
  std::string name;
 
  // initialize menu
  Menu choose_type("What type of player?");
  choose_type.addOptions("Barbarian");
  choose_type.addOptions("Vampire");
  choose_type.addOptions("Blue Men");
  choose_type.addOptions("Medusa");
  choose_type.addOptions("Harry Potter");

  // prompt user for name of player
  std::cout << "What do you want to name player?" << std::endl;
  std::cout << "---------------------------------------------" << std::endl;
  std::cin >> name;
  std::cout << std::endl;

  // prompt user for the type of player
  choose_type.outputMenu();
  character_type type = static_cast<character_type>(choose_type.getUserInput());

  // create player
  create_player(type, name);

  // add them to the correct team
  if (team == 1){
    team_one_lineup.add_winner(player);
  }
  else {
    team_two_lineup.add_winner(player);
  }
}

/************************************************************* 
** Description: Creates the players based on the type input
   by the user.
*************************************************************/
void Game::create_player(character_type type, std::string name){
  switch (type){
    case BARBARIAN:
    {
      player = new Barbarian();
      player->set_name(name);
    }
    break;
    case VAMPIRE:
    {
      player = new Vampire();
      player->set_name(name);
    }
    break;
    case BLUE_MEN: 
    {
      player = new Blue_Men();
      player->set_name(name);
    }
    break;
    case MEDUSA:
    {
      player = new Medusa();
      player->set_name(name);
    }
    break;
    case HARRY_POTTER:
    {
      player = new Harry_Potter();
      player->set_name(name);
    }
    break;
  }
}

/*************************************************************
** Description: Plays the tournament until one of the team
   has no more winners left. At this point, it prints out 
   the winning team. 
*************************************************************/
void Game::play_tournament(){
  // play until one team dies
  while (teams_alive()){
    play_matchup();
  }
  
  // print out winner based on score
  if (team_one_score < team_two_score){
    std::cout << "                 TEAM 2 WINS                 " << std::endl;
  }
  else if (team_one_score > team_two_score){
    std::cout << "                 TEAM 1 WINS                 " << std::endl;
  }
  else if (team_one_score == team_two_score){
    std::cout << "                GAME IS A TIE                " << std::endl;
  }

  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "Team 1 Score: " << team_one_score << std::endl;
  std::cout << "Team 2 Score: " << team_two_score << std::endl;
  
  Menu display_losers("Do you want to display the losers?");
  display_losers.addOptions("Yes");
  display_losers.addOptions("No");
  display_losers.outputMenu();

  if (display_losers.getUserInput() == 1){
    losers.print_losers();
  }

  team_one_lineup.clear();
  team_two_lineup.clear();
  losers.clear();
}

/*************************************************************
** Description: Check if both teams are alive - controls
   the flow of the game - tournament ends when one of the teams
   winner bracket is empty.
*************************************************************/
bool Game::teams_alive(){
  if (team_one_lineup.is_empty() || team_two_lineup.is_empty()){
    return false;
  }
  else {
    return true;
  }
}

/*************************************************************
** Description: Create players and coordinate game play - also
   output result of matchup.
*************************************************************/
void Game::play_matchup(){
  // get players on deck and remove
  Character* player_one = team_one_lineup.get_on_deck();
  team_one_lineup.remove_on_deck();

  Character* player_two = team_two_lineup.get_on_deck();
  team_two_lineup.remove_on_deck();

  // play until one player is no longer alive
  while (player_one->alive() && player_two->alive()){
    play_turn(player_one, player_two);
    if (player_two->alive()){
      play_turn(player_two, player_one);
    }
  }

  // if player one is still alive, declare them the winner
  if (player_one->alive()){
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Player 1 " << player_one->get_type() << " wins!" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    team_one_lineup.add_winner(player_one);
    team_one_score += 2;

    losers.add_loser(player_two);
    team_two_score -= 1;
  }
  // if player two is still alive, declare them the winner
  else {
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Player 2 " << player_two->get_type() << " wins!" << std::endl; 
    std::cout << "---------------------------------------------" << std::endl;

    team_two_lineup.add_winner(player_two);
    team_two_score += 2;

    losers.add_loser(player_one);
    team_one_score -= 1;
  }
}

/*************************************************************
** Description: Plays each round of game, calls functions
   for attacking and defending, calculates the resulting damage,
   and outputs the result of each round.
*************************************************************/
void Game::play_turn(Character* attacker, Character* defender){
  int damage = 0;
  int attack_points, defense_points, armor, defender_ending_strength;

  // present the beginning values to the user
  get_start_attributes(attacker, defender);
  
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
** Description: Prints the round result values.
*************************************************************/
void Game::get_start_attributes(Character* attacker, Character* defender){
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "                ROUND RESULTS                " << std::endl;
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "Attacker Type: " << attacker->get_type() << std::endl;
  std::cout << "Defender Type: " << defender->get_type() << std::endl;
  std::cout << "Defender Armor: " << defender->get_armor() << std::endl;
  std::cout << "Defender Starting Strength: " << defender->get_strength() << std::endl;
}
