#include "QueueNode.hpp"

#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue {
  private:
    QueueNode* head;
  public:
    // constructor
    Queue();
    // destructor
    ~Queue();

    bool isEmpty() const;
    void addBack(int);
    int getFront();
    void removeFront();
    void printQueue();

    // queue exception
    class Empty {};
};

#endif
