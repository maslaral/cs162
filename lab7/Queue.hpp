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
   queue next node is the head. 
*************************************************************/
#include "QueueNode.hpp"

#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue {
  private:
    struct QueueNode {
      QueueNode* next;
      QueueNode* prev; 
      int val;
    };
    QueueNode* head;

  public:
    // constructor
    Queue();
    // destructor
    ~Queue();

    // handle empty queue
    bool isEmpty() const;
    void outputEmpty();

    // queue functions
    void addBack(int);
    int getFront();
    void removeFront();
    void printQueue();

    // queue exception
    class Empty {};
};

#endif
