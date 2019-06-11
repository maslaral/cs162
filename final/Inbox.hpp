/*************************************************************
** Program name: Lab 7
** Author: Alex Maslar
** Date: May 18 2019
** Description: Function header file for the Queue class. 
   Includes functions to add a node to the back of the queue,
   to get the front value in the queue, remove the front node
   from the queue, and to print the values of each node in the
   queue. The Queue is a circular queue, meaning that the head
   previous node is the tail of the queue, and the tail of the
   queue next node is the head. The variables of the Queue 
   class include a structure which represents a node and a
   pointer to a head.
*************************************************************/
#ifndef INBOX_HPP
#define INBOX_HPP

#include <string>

struct Email {
  Email* next;
  Email* prev; 
  std::string sender;
  std::string subject;
  std::string body;
};

class Inbox {
  private:
    Email* head;

  public:
    // constructor
    Inbox();
    // destructor
    ~Inbox();

    // handle empty queue
    bool isEmpty() const;
    void outputEmpty();

    // queue functions
    void addBack(std::string, std::string, std::string);
    std::string getFront();
    void removeFront();
    void printInbox();

    // queue exception
    class Empty {};
};

#endif
