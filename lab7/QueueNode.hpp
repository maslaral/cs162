/*************************************************************
** Program name: Lab 7
** Author: Alex Maslar
** Date: May 18 2019
** Description: Function header file for the QueueNode
   class. Includes functions to get the next, previous, and
   value of each QueueNode object. In addition, functions to
   set the next and previous nodes.
*************************************************************/
#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP

class QueueNode {
  private:
    QueueNode* next;
    QueueNode* prev;
    int val;
  public:
    // constructor
    QueueNode();
    QueueNode(int);
    // destructor
    ~QueueNode();

    // getter functions
    QueueNode* get_next();
    QueueNode* get_prev();
    int get_val();
    // setter functions
    void set_next(QueueNode*);
    void set_prev(QueueNode*);
};

#endif
