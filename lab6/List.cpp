/*************************************************************
** Program name: Lab 6
** Author: Alex Maslar
** Date: May 12 2019
** Description: List class implementation that includes 
   function definitions to add a value to the head of a list,
   add a value to the end of a list, delete the head or tail
   from a list, print the list in reverse, print the first and
   last values, or read in values from a file. These are called
   from the main class based on user input. In addition,
   the class includes a function to regularly print the 
   list in order - which is used when a new node is added or
   deleted from the list.
*************************************************************/
#include "List.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

/*************************************************************
** Description: List constructor - sets head and tail to 
   nullptr by default.
*************************************************************/
List::List(){
  head = nullptr;
  tail = nullptr;
}

/*************************************************************
** Description: List destructor - loops through the list
   and deletes each node until it reaches the tail of the 
   list.
*************************************************************/
List::~List(){
  // start at head
  Node* ptr = head;
  // loop until reach the tail
  while (ptr != nullptr){
    Node* garbage = ptr; 
    ptr = ptr->get_next();
    delete garbage;
  }
}

/*************************************************************
** Description: Function adds a node to the head of the list
   by setting the next variable to the current head of the
   list, setting the previous to nullptr, and then setting
   the previous of the head to the new node. Finally, the 
   head variable is assigned to the new node. If the tail
   is a nullptr (i.e. this is the first element added to the
   list) it is also set to the new node.
*************************************************************/
void List::add_head(int val){
  Node* new_node = new Node(val);
  // set the new node's next var to the old head
  new_node->set_next(head);
  // set the new node's previous var to nullptr
  new_node->set_prev(nullptr);

  if (head != nullptr){
    // set the old head previous to new node
    head->set_prev(new_node);
  }

  // if tail is nullptr, then set it to the new node too
  if (tail == nullptr){
    tail = new_node;
  }
  
  // set the head to the new_node
  head = new_node;
}

/*************************************************************
** Description: Function adds a node to the tail of the list
   by setting the previous variable to the current tail of
   the list, setting the next to nullptr, and then setting
   the next of the tail to the new node. Finally, the tail
   variable is assigned to the new node. If the head is a
   nullptr (i.e. this is the first element added to the list)
   it is also set to the new node.
*************************************************************/
void List::add_tail(int val){
  Node* new_node = new Node(val);
  // set the new node's previous var to the old tail
  new_node->set_prev(tail);
  // set the new node's next var to nullptr
  new_node->set_next(nullptr);

  if (tail != nullptr){
    // set the old tail previous to new node
    tail->set_next(new_node);
  }

  // if head is nullptr, then set it to the new node too
  if (head == nullptr){
    head = new_node;
  }

  // set the tail to the new node
  tail = new_node;
}

/*************************************************************
** Description: Function deletes the head of the list by 
   setting the setting the new head of the list to the value
   after the current head, deleting the old head, and setting
   the previous varaible to nullptr on the new head. Finally,
   the head variable is set to new head. The old head is
   deleted and set to nullptr. If the head is nullptr (i.e. 
   the list is empty) the console will print the list is 
   empty and exit the function. If the head next value
   is nullptr (i.e. this is the last value in the list) then 
   the head and tail are set to nullptr and the console 
   outputs that the list is empty.
*************************************************************/
void List::delete_first(){

  // if head is null list is empty
  if (head == nullptr){
    std::cout << std::endl;
    std::cout << "List is empty." << std::endl;
    return;
  }
  
  // if the next value is null then this is the last number
  if (head->get_next() == nullptr){
    head = nullptr;
    tail = nullptr;
    std::cout << std::endl;
    std::cout << "List is empty." << std::endl;
    return;
  }

  // set new head to second position
  Node* new_head = head->get_next();
  // delete the old head
  delete new_head->get_prev();

  // nullptr prev indicates its the head
  new_head->set_prev(nullptr); 

  // make the head the new head
  head = new_head;
}

/*************************************************************
** Description: Function deletes the tail of the list by 
   setting the setting the new tail of the list to the value
   before the current tail, deleting the old tail, and setting
   the next varaible to nullptr on the new tail. Finally,
   the tail variable is set to new tail. The old tail is
   deleted and set then its set to nullptr. If the tail is
   nullptr (i.e. the list is empty) the console will print
   list is empty and exit the function. If the tail previous
   value is nullptr (i.e. this is the last value in the list)
   then the head and tail are set to nullptr and the console
   outputs the list is empty.
*************************************************************/
void List::delete_last(){

  // if tail is null list is empty
  if (tail == nullptr){
    std::cout << std::endl;
    std::cout << "List is empty." << std::endl;
    return;
  }

  // if the prev value is null then this is the last number
  if (tail->get_prev() == nullptr){
    head = nullptr;
    tail = nullptr;
    std::cout << std::endl;
    std::cout << "List is empty." << std::endl;
    return;
  }

  // set new tail to second to last position
  Node* new_tail = tail->get_prev();
  // delete the old tail
  delete new_tail->get_next();

  // nullptr next indicates its the tail
  new_tail->set_next(nullptr);

  // make the tail the new tail
  tail = new_tail;
}

/*************************************************************
** Description: Function prints the list in reverse order by
   starting at the tail and getting the previous node until
   it reaches nullptr (i.e. the head of the list).
*************************************************************/
void List::reverse_display(){
  // if tail is nullptr the list is empty
  if (tail == nullptr){
    std::cout << std::endl;
    std::cout << "List is empty." << std::endl;
    return;
  }

  // setting the starting point
  Node* ptr = tail;
  
  // go from tail until reach nullptr (head)
  while (ptr != nullptr){
    std::cout << ptr->get_val() << " ";
    ptr = ptr->get_prev();
  }
}

/*************************************************************
** Description: Function prints the list starting from the
   head until it reaches nullptr (i.e. the tail of the list).
*************************************************************/
void List::display(){
  // if head is nullptr the list is empty
  if (head == nullptr){
    return;
  }

  // setting the starting point
  Node* ptr = head;

  // go from head until reach nullptr (tail)
  std::cout << "The values in the list include:" << std::endl;
  while (ptr != nullptr){
    std::cout << ptr->get_val() << " ";
    ptr = ptr->get_next();
  }
}

/*************************************************************
** Description: Function prints the value in the list head.
*************************************************************/
void List::print_head(){
  std::cout << head->get_val() << std::endl;
}

/*************************************************************
** Description: Function prints the value in the tail head.
*************************************************************/
void List::print_tail(){
  std::cout << tail->get_val() << std::endl;
}

/*************************************************************
** Description: Function takes a file and gets each line 
   (which has a single integer) and sets it to the val 
   variable. Then, the val variable is used to call the add_tail
   function to add it to the list.
*************************************************************/
void List::read_file(){
  // initialize ifstream object
  std::ifstream ifs;
  // open file
  ifs.open("file.txt");

  std::string input;

  // read until end of file
  while (std::getline(ifs, input)){
      // istring stream to get int values
      std::istringstream ss(input);

      int val;
      ss >> val;     // save line integer to val
      add_tail(val); // add a node to end of list
  }
}
