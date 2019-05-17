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
