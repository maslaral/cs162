/*************************************************************
** Program name: Lab 6
** Author: Alex Maslar
** Date: May 12 2019
** Description: List class header file that includes 
   function definitions to add a value to the head of a list,
   add a value to the end of a list, delete the head or tail
   from a list, print the list in reverse, print the first and
   last values, or read in values from a file. These are called
   from the main class based on user input. In addition,
   the class includes a function to regularly print the 
   list in order - which is used when a new node is added or
   deleted from the list.
*************************************************************/
#ifndef LIST_HPP
#define LIST_HPP

#include "Node.hpp"

class List {
  private:
    Node* head;
    Node* tail;
  public:
    // constructor
    List();
    // destructor
    ~List();

    // add to list
    void add_head(int val);
    void add_tail(int val);
    // delete from list
    void delete_first();
    void delete_last();
    // display list
    void reverse_display();
    void display();
    void print_head();
    void print_tail();
    // read from file
    void read_file();
};

#endif
