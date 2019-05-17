#include "QueueNode.hpp"

#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue {
  private:
    QueueNode* head;
    QueueNode* rear;
  public:
    // constructor
    Queue();
    // destructor
    ~Queue();

    bool isEmpty() const;
    void addBack(int);
    void getFront();
    void removeFront();
    void printQueue();
};

#endif
