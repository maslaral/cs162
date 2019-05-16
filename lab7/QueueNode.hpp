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
    int get_next();
    int get_prev();
    int get_val();
};

#endif
