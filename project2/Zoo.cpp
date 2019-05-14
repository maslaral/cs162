/*************************************************************
** Program name: Project 2 - Zoo Tycoon
** Author: Alex Maslar
** Date: April 28 2019
** Description: Functions for playing the zoo tycoon game,
   including creating array of animal type objects, resizing
   those arrays, giving birth and purchasing animals, and
   removing them when they die. Also included are functions
   that calculate the bank balance and the daily profit. 
*************************************************************/
#include "Zoo.hpp"
#include<cstdlib>
#include<iostream>

/*************************************************************
** Description: Constructors - sets the zoo object initial
   values and initializes the cage arrays for each animal type.
   The constructor also sets the starting bank balance and 
   the daily revenue to zero. 
*************************************************************/
Zoo::Zoo(){
  // general variables - set beginning bank balance, revenue,
  // and number of days opening
  bank_balance = 100000;
  profit = 0;
  bonus = 0;
  number_of_days_open = 0;

  // tiger variables - initialize tiger array to nullptr
  number_of_tigers = 0;
  number_of_tiger_cages = 10;
  tiger_cage = new Tiger*[number_of_tiger_cages]();
  for (int i = 0; i < number_of_tiger_cages; i++){
    tiger_cage[i] = nullptr;
  }

  // penguin variables - initialize penguin array to nullptr
  number_of_penguins = 0;
  number_of_penguin_cages = 10;
  penguin_cage = new Penguin*[number_of_penguin_cages];
  for (int i = 0; i < number_of_penguin_cages; i++){
    penguin_cage[i] = nullptr;
  }

  // turtle variables - initialize turtle array to nullptr
  number_of_turtles = 0;
  number_of_turtle_cages = 10;
  turtle_cage = new Turtle*[number_of_turtle_cages];
  for (int i = 0; i < number_of_turtle_cages; i++){
    turtle_cage[i] = nullptr;
  }
}

/*************************************************************
** Description: Destructors - deletes the cage arrays and all
   of the objects in the array. It also sets the pointers in
   the array to nullptr to avoid dangling pointers.
*************************************************************/
Zoo::~Zoo(){
  // delete tiger array and objects
  for (int i = 0; i < number_of_tiger_cages; i++){
    if (tiger_cage[i] != nullptr){
      delete tiger_cage[i];
      tiger_cage[i] = nullptr;
    }
  }
  delete [] tiger_cage;

  // delete penguin array and objects
  for (int i = 0; i < number_of_penguin_cages; i++){
    if (penguin_cage[i] != nullptr){
      delete penguin_cage[i];
      penguin_cage[i] = nullptr;
    }
  }
  delete [] penguin_cage;

  // delete turtle array and objects
  for (int i = 0; i < number_of_turtle_cages; i++){
    if (turtle_cage[i] != nullptr){
      delete turtle_cage[i];
      turtle_cage[i] = nullptr;
    }
  }
  delete [] turtle_cage;
}

/*************************************************************
** Description: Purchases an additional animal. The argument
   for this function is the animal type and the number of
   animals purchased. The function is made up of a switch
   statement with each case representative of the animal
   type. It also includes a conditional for the age of the 
   animal purchased. If an initial animal purchase (at the
   beginning of the game) the animal age is one. If at any
   time after the first day, the animal age when purchased is
   three. This function calls the member functions for adding
   an animal. In addition, the function subtracts the cost 
   of each animal from the total bank balance.
*************************************************************/
void Zoo::animal_purchase(animal_type a, int num){
  switch (a){
  case TIGER: 
    for (int i = 0; i < num; i++){
      if (number_of_days_open == 0){
        add_tiger(1);
      }
      else {
        add_tiger(3);
      }
      bank_balance -= tiger_cage[get_animal(TIGER)]->get_cost();
    }
    break;
  case PENGUIN:
    for (int i = 0; i < num; i++){
      if (number_of_days_open == 0){
        add_penguin(1);
      }
      else {
        add_penguin(3);
      }
      bank_balance -= penguin_cage[get_animal(PENGUIN)]->get_cost();
    }
    break;
  case TURTLE:
    for (int i = 0; i < num; i++){
      if (number_of_days_open == 0){
        add_turtle(1);
      }
      else {
        add_turtle(3);
      }
      bank_balance -= turtle_cage[get_animal(TURTLE)]->get_cost();
    }
    break;
  }
}

/*************************************************************
** Description: Generates a random event. There are four events
   that can occur - a birth, a death, a boom in attendance, or
   nothing. This function determines the type of event, and then
   calls the function that actually executes the event.
*************************************************************/
void Zoo::random_event() {
  event_type e = static_cast<event_type>(rand() % 4 + 1);

  if (e == BIRTH){
    random_event_birth();
  }
  else if (e == DEATH){
    random_event_death();
  }
  else if (e == ATTEND_BOOM){
    random_event_attend_boom();
  }
  else {
    random_event_nothing();
  }
}

/*************************************************************
** Description: Generates a random animal type to give birth.
   The function uses a switch statements with cases to first
   call the check_adult function (which returns a boolean
   if the animal type has an adult) and then calls the give
   birth function. If the initial animal type generated from
   the random number doesn't have any adults, it moves on to 
   the next type and repeats the process. If there are no
   animal types with adults, then it calls the member function
   random_event_nothing.
*************************************************************/
void Zoo::random_event_birth(){
  animal_type a = static_cast<animal_type>(rand() % 3 + 1);

  switch(a){
  case TIGER:
    if (check_adult(TIGER)){
      give_birth(TIGER);
    }
    // if there are not any adult tigers, move on to checking
    // if there are any adults of the other species
    else if (check_adult(PENGUIN)){
      give_birth(PENGUIN);
    }
    else if (check_adult(TURTLE)){
      give_birth(TURTLE);
    }
    // if no adults, then just do nothing
    else {
      random_event_nothing();
    }
    break;

  case PENGUIN:
    if (check_adult(PENGUIN)){
      give_birth(PENGUIN);
    }
    // if there are not any adult penguins, move on to checking
    // if there are any adults of the other species
    else if (check_adult(TIGER)){
      give_birth(TIGER);
    }
    else if (check_adult(TURTLE)){
      give_birth(TURTLE);
    }
    // if no adults, then just do nothing
    else {
      random_event_nothing();
    }
    break;

  case TURTLE:
    if (check_adult(TURTLE)){
      give_birth(TURTLE);
    }
    // if there are not any adult turtles, move on to checking
    // if there are any adults of the other species
    else if (check_adult(TIGER)){
      give_birth(TIGER);
    }
    else if (check_adult(PENGUIN)){
      give_birth(PENGUIN);
    }
    // if no adults, then just do nothing
    else {
      random_event_nothing();
    }
    break;
  }
}

/*************************************************************
** Description: Checks if there is an adult animal of
   the type passed to the function. Each case in the switch
   statement loops through the array and calls the is_adult
   function from the Animal class. When it discovers an animal
   that is an adult, it exits the while loop and sets the bool
   return value to true.
*************************************************************/
bool Zoo::check_adult(animal_type a){

  bool check = false;
  int i = 0;
 
  switch(a){
  case TIGER:
    while (i < number_of_tiger_cages && check == false){
      if (tiger_cage[i] != nullptr){
        check = tiger_cage[i]->is_adult();
      }
      i++;
    } return check;
    break;
  case PENGUIN:
    while (i < number_of_penguin_cages && check == false){
      if (penguin_cage[i] != nullptr){
        check = penguin_cage[i]->is_adult();
      }
      i++;
    } return check;
    break;
  case TURTLE:
    while (i < number_of_turtle_cages && check == false){
      if (turtle_cage[i] != nullptr){
        check = turtle_cage[i]->is_adult();
      }
      i++;
    } return check;
    break;
  default:
    return false;
  }
} 

/*************************************************************
** Description: Creates a new animal object with an age equal
   to zero. The function takes as it's argument the animal
   type, and uses a switch statement to then add a new animal
   of that type to the corresponding array. The function then
   informs the user that a new animal was born. Note that this
   is only called if there are adult animals of the type in the
   argument.
*************************************************************/
void Zoo::give_birth(animal_type a){
  switch(a){
  case TIGER:
    for (int i = 0; i < tiger_cage[get_animal(TIGER)]->get_number_of_babies(); i++){
      add_tiger(0);
    }
    std::cout << std::endl;
    std::cout << "Good news, a baby tiger was born!" << std::endl;
    std::cout << std::endl;
    break;
  case PENGUIN:
    for (int i = 0; i < penguin_cage[get_animal(PENGUIN)]->get_number_of_babies(); i++){
      add_penguin(0);
    }
    std::cout << std::endl;
    std::cout << "Good news, baby penguins were born!" << std::endl;
    std::cout << std::endl;
    break;
  case TURTLE:
    for (int i = 0; i < turtle_cage[get_animal(TURTLE)]->get_number_of_babies(); i++){
      add_turtle(0);
    }
    std::cout << std::endl;
    std::cout << "Good news, baby turtles were born!" << std::endl;
    std::cout << std::endl;
    break;
  }
}

/*************************************************************
** Description: Generates a random animal type to get sick
   and die. The function then uses a switch statement
   to remove the animal from the array based on their type. Each
   case of the switch statement checks if there are any types of
   that animal. If not, then it continues to the next animal type
   and repeats the process of checking if that animal exists.
   Once it finds an animal that exists, it calls the 
   remove_animal function to take an animal out of the array. 
*************************************************************/
void Zoo::random_event_death(){

  animal_type a = static_cast<animal_type>(rand() % 3 + 1);

  switch(a){
  case TIGER:
    if (number_of_tigers > 0){
      remove_animal(TIGER);
    }
    // if no tigers, then check if there any penguins
    else if (number_of_penguins > 0){
      remove_animal(PENGUIN);
    }
    // if no penguins, check if there are turtles
    else if (number_of_turtles > 0){
      remove_animal(TURTLE);
    }
    // otherwise, do nothing
    else {
      random_event_nothing();
    }
    break;

  case PENGUIN:
    if (number_of_penguins > 0){
      remove_animal(PENGUIN);
    }
    // if no penguins, check if there are tigers 
    else if (number_of_tigers > 0){
      remove_animal(TIGER);
    }
    // if no tigers, check if there are turtles
    else if (number_of_turtles > 0){
      remove_animal(TURTLE);
    }
    // otherwise, do nothing
    else {
      random_event_nothing();
    }
    break;

  case TURTLE:
    if (number_of_turtles > 0){
      remove_animal(TURTLE);
    }
    // if no turtles, check if there are tigers
    else if (number_of_tigers > 0){
      remove_animal(TIGER);
    }
    // if no tigers, check if there are penguins
    else if (number_of_penguins > 0){
      remove_animal(PENGUIN);
    }
    // otherwise, do nothing
    else {
      random_event_nothing();
    }
    break;
  }
} 

/*************************************************************
** Description: Represents what happens if there is a boom
   in attendance at the zoo. The function finds a random number
   between 250 and 500 and adds it to the daily revenue. It
   then congratulates the user and informs them of their 
   windfall.
*************************************************************/
void Zoo::random_event_attend_boom(){
  bonus = rand() % 500 + 250;
  std::cout << std::endl;
  std::cout << "Good news, a surge in zoo attendance just added $" << bonus << " to the payoff for each tiger!" << std::endl;
  std::cout << std::endl;
}

/*************************************************************
** Description: This function represents nothing happening. 
   This is called when directly generated in the random event
   function, or if the birth function is called and there are 
   no adults or the death function is called and there are no
   animals.
*************************************************************/
void Zoo::random_event_nothing(){
  std::cout << std::endl;
  std::cout << "Uneventful day. Nothing random happened." << std::endl;
  std::cout << std::endl;
}

/*************************************************************
** Description: Creates a new Tiger object and increments the
   number_of_tigers variable. The function takes age as its
   only argument (this is so that the different ages like birth,
   initial purchase, and adult purchase can be represented). 
   Once the object is created, it adds the tiger to the tiger
   cage array if there's capacity. If there isn't any capacity
   in the array (i.e. there aren't any nullptrs), then it calls
   a function to double the size of the array. 
*************************************************************/
void Zoo::add_tiger(int age){
  Tiger* t = new Tiger();
  t->set_age(age);
  number_of_tigers++;

  if (open_capacity(TIGER)){
    int cage = get_open_cage(TIGER); 
    tiger_cage[cage] = t;
  }
  else {
    add_tiger_capacity();
    int cage = get_open_cage(TIGER);
    tiger_cage[cage] = t;
  }   
}

/*************************************************************
** Description: Creates a new Penguin object and increments the
   number_of_penguins variable. The function takes age as its
   only argument (this is so that the different ages like birth,
   initial purchase, and adult purchase can be represented). 
   Once the object is created, it adds the tiger to the tiger
   cage array if there's capacity. If there isn't any capacity
   in the array (i.e. there aren't any nullptrs), then it calls
   a function to double the size of the array. 
*************************************************************/
void Zoo::add_penguin(int age){
  Penguin* p = new Penguin();
  p->set_age(age);
  number_of_penguins++;

  if (open_capacity(PENGUIN)){
    int cage = get_open_cage(PENGUIN); 
    penguin_cage[cage] = p;
  }
  else {
    add_penguin_capacity();
    int cage = get_open_cage(PENGUIN);
    penguin_cage[cage] = p;
  }   
}

/*************************************************************
** Description: Creates a new Turtle object and increments the
   number_of_turtles variable. The function takes age as its
   only argument (this is so that the different ages like birth,
   initial purchase, and adult purchase can be represented). 
   Once the object is created, it adds the tiger to the tiger
   cage array if there's capacity. If there isn't any capacity
   in the array (i.e. there aren't any nullptrs), then it calls
   a function to double the size of the array. 
*************************************************************/
void Zoo::add_turtle(int age){
  Turtle* t = new Turtle();
  t->set_age(age);
  number_of_turtles++;

  if (open_capacity(TURTLE)){
    int cage = get_open_cage(TURTLE); 
    turtle_cage[cage] = t;
  }
  else {
    add_turtle_capacity();
    int cage = get_open_cage(TURTLE);
    turtle_cage[cage] = t;
  }   
}

/*************************************************************
** Description: This is a simple boolean function that checks
   if there are any open cages in the array. It takes one
   argument, the animal type, which it uses in the switch 
   statement to comapre the number of that animal type to the
   number of cages.
*************************************************************/
bool Zoo::open_capacity(animal_type a){
  switch(a){
  case TIGER:
    if (number_of_tigers > number_of_tiger_cages){
      return false;
    }
    else {
      return true;
    }
    break;
  case PENGUIN:
    if (number_of_penguins > number_of_penguin_cages){
      return false;
    }
    else {
      return true;
    }
    break;
  case TURTLE:
    if (number_of_turtles > number_of_turtle_cages){
      return false;
    }
    else {
      return true;
    }
    break;
  default:
    return false;
  }
}

/*************************************************************
** Description: This function gets the first array element that
   is a nullptr by looping through the array. This is needed
   because sometimes when an animal is removed from the array
   they are not the last animal in the array. So just adding
   to the end of the array when creating a new animal would leave
   one element as a nullptr. This ensures that that spot is filled
   back up the next time an animal is purchased or born.
*************************************************************/
int Zoo::get_open_cage(animal_type a){
  // initializes the int value used in the while loops
  int i = 0;
  
  switch(a){
  case TIGER:
    while (i < number_of_tiger_cages && tiger_cage[i] != nullptr){
      i++;
    } return i;
    break;
  case PENGUIN:
    while (i < number_of_penguin_cages && penguin_cage[i] != nullptr){
      i++;
    } return i;
    break;
  case TURTLE:
    while (i < number_of_turtle_cages && turtle_cage[i] != nullptr){
      i++;
    } return i;
    break;
  default:
    return 0;
  }
}

/*************************************************************
** Description: This function returns the position of the 
   first animal in each array. This is used in functions to
   call polymorphic functions that need an object to work
   properly.
*************************************************************/
int Zoo::get_animal(animal_type a){
  int i = 0;
  switch(a){
  case TIGER:
    while (i < number_of_tiger_cages && tiger_cage[i] == nullptr){
      i++;
    } return i;
    break;
  case PENGUIN:
    while (i < number_of_penguin_cages && penguin_cage[i] == nullptr){
      i++;
    } return i;
    break;
  case TURTLE:
    while (i < number_of_turtle_cages && turtle_cage[i] == nullptr){
      i++;
    } return i;
    break;
  default:
    return 0;
  }
}

/*************************************************************
** Description: This function initializes a new array double
   the size of the original array. It sets each pointer in the
   new array to nullptr. Then, it loops through the original
   array and copies its elements to the new array. Finally, the
   old array is destroyed and the temporary array is assigned
   the same variable name as the old array.
*************************************************************/
void Zoo::add_tiger_capacity(){
  // create a new array with an additional 10 elements
  number_of_tiger_cages *= 2;
  Tiger** temp = new Tiger*[number_of_tiger_cages];
    for (int i = 0; i < number_of_tiger_cages; i++){
      temp[i] = nullptr;
    }

  // loops through the array and copys values from original
  // array to temp, also sets empty elements to nullptr
  for (int i = 0; i < (number_of_tiger_cages / 2); i++){
    temp[i] = tiger_cage[i];
  }

  // delete the original array
  delete [] tiger_cage;
  tiger_cage = temp;
}

/*************************************************************
** Description: This function initializes a new array double
   the size of the original array. It sets each pointer in the
   new array to nullptr. Then, it loops through the original
   array and copies its elements to the new array. Finally, the
   old array is destroyed and the temporary array is assigned
   the same variable name as the old array.
*************************************************************/
void Zoo::add_penguin_capacity(){
  number_of_penguin_cages *= 2;

  // create the new array double the size of original,
  // sets each pointer to nullptr
  Penguin** temp = new Penguin*[number_of_penguin_cages];
    for (int i = 0; i < number_of_penguin_cages; i++){
      temp[i] = nullptr;
    }

  // loops through the array and copys values from original
  // array to temp, also sets empty elements to nullptr
  for (int i = 0; i < (number_of_penguin_cages / 2); i++){
    temp[i] = penguin_cage[i];
  }

  // delete the original array
  delete [] penguin_cage;
  penguin_cage = temp;
}

/*************************************************************
** Description: This function initializes a new array double
   the size of the original array. It sets each pointer in the
   new array to nullptr. Then, it loops through the original
   array and copies its elements to the new array. Finally, the
   old array is destroyed and the temporary array is assigned
   the same variable name as the old array.
*************************************************************/
void Zoo::add_turtle_capacity(){
  number_of_turtle_cages *= 2;
  
  // create the new array double the size of original,
  // sets each pointer to nullptr
  Turtle** temp = new Turtle*[number_of_turtle_cages];
    for (int i = 0; i < number_of_turtle_cages; i++){
      temp[i] = nullptr;
    }

  // loops through the array and copys values from original
  // array to temp
  for (int i = 0; i < (number_of_turtle_cages / 2); i++){
    temp[i] = turtle_cage[i];
  }

  // delete the original array
  delete [] turtle_cage;
  turtle_cage = temp;
}

/*************************************************************
** Description: This function removes an animal from the array
   and reduces the number of that animal from the counter. The
   animal object removed the array is then deleted and the pointer
   is set to nullptr. Finally, the function outputs a message
   to the user informing them of the unfortunate event.
*************************************************************/
void Zoo::remove_animal(animal_type a){
  std::cout << std::endl;
  switch(a){
  case TIGER:
    if (number_of_tigers > 0){
      int r = get_animal(TIGER);
      number_of_tigers--;
      delete tiger_cage[r];
      tiger_cage[r] = nullptr;
      std::cout << "Sorry for your loss, a tiger just died." << std::endl;
    }
    break;
  case PENGUIN:
    if (number_of_penguins > 0){
      int r = get_animal(PENGUIN);
      number_of_penguins--;
      delete penguin_cage[r];
      penguin_cage[r] = nullptr;
      std::cout << "Sorry for your loss, a penguin just died." << std::endl;
    }
    break;
  case TURTLE:
    if (number_of_turtles > 0){
      int r = get_animal(TURTLE);
      number_of_turtles--;
      delete turtle_cage[r];
      turtle_cage[r] = nullptr;
      std::cout << "Sorry for your loss, a turtle just died." << std::endl;
    }
    break;
  }
  std::cout << std::endl;
}

/*************************************************************
** Description: These functions calculate the cost of feed
   for each animal by multiplying the feed cost by the number
   of each animal. If there are not any animals of that type, 
   it skips that calculation. This is to avoid causing a seg
   fault. The function also resets the profit to zero.
*************************************************************/
void Zoo::pay_feed_cost(){
  
  // resets daily revenue back to 0
  profit = 0;

  // tiger feed cost 
  if (number_of_tigers > 0){
    bank_balance -= (tiger_cage[get_animal(TIGER)]->get_feed_cost() * number_of_tigers);
  }

  // penguin feed cost
  if (number_of_penguins > 0){
    bank_balance -= (penguin_cage[get_animal(PENGUIN)]->get_feed_cost() * number_of_penguins);
  }

  // turtle feed cost 
  if (number_of_turtles > 0){
    bank_balance -= (turtle_cage[get_animal(TURTLE)]->get_feed_cost() * number_of_turtles);
  }
}

/*************************************************************
** Description: Calculates the profit generated from each
   animal type based on the payoff multiplied by the number
   of animals of that type. The function then adds the profit
   to the bank balance, and displays a summary of the day.
   Finally, the function adds one day to the days open variable
   and increase the age of all of the animals.
*************************************************************/
void Zoo::end_of_day(){
  
  // tiger revenue
  if (number_of_tigers > 0){
    profit += (tiger_cage[get_animal(TIGER)]->get_payoff() * number_of_tigers);
    profit += (bonus * number_of_tigers);
  }

  // penguin revenue
  if (number_of_penguins > 0){
    profit += (penguin_cage[get_animal(PENGUIN)]->get_payoff() * number_of_penguins);
  }

  // turtle revenue
  if (number_of_turtles > 0){
    profit += (turtle_cage[get_animal(TURTLE)]->get_payoff() * number_of_turtles);
  }

  bank_balance += profit;

  // reset the bonus back to 0
  bonus = 0;

  number_of_days_open++;
  
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "END OF DAY SUMMARY" << std::endl;
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "Days Open: " << number_of_days_open << std::endl;
  std::cout << "Daily Profit: $" << profit << std::endl;
  std::cout << "Bank Balance: $" << bank_balance << std::endl;
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "Number of Tiger(s): " << number_of_tigers << std::endl;
  std::cout << "Number of Penguin(s): " << number_of_penguins << std::endl;
  std::cout << "Number of Turtle(s): " << number_of_turtles << std::endl;
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << std::endl;
  
  increase_age();

}

/*************************************************************
** Description: Adds one to the age of each animal in the 
   cage array. Uses a for loop to check if an Animal subclass
   object exists. If an object exists, then calls the Animal 
   member function add_day() which simply increments the member
   variable age by one.
*************************************************************/
void Zoo::increase_age(){
  for (int i = 0; i < number_of_tiger_cages; i++){  
    if (tiger_cage[i] != nullptr){
      tiger_cage[i]->add_day();
    } 
  }
  for (int i = 0; i < number_of_penguin_cages; i++){
    if (penguin_cage[i] != nullptr){
      penguin_cage[i]->add_day();
    }
  }
  for (int i = 0; i < number_of_turtle_cages; i++){
    if (turtle_cage[i] != nullptr){
      turtle_cage[i]->add_day();
    }
  }
}

/*************************************************************
** Description: Returns the number of days that zoo has been
   open. This is used in the end of day function to display 
   to the end user and for determining how many times
   to run through the menus in the main function.
*************************************************************/
int Zoo::get_number_of_days_open(){
  return number_of_days_open;
}

/*************************************************************
** Description: Returns the balance of the bank. This is used
   in the end of day function to display to the end user and in
   the main function to determine when the user has run out 
   of money. 
*************************************************************/
int Zoo::get_bank_balance(){
  return bank_balance;
}
