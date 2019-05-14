/*************************************************************
** Program name: Lab 6 
** Author: Alex Maslar
** Date: May 12 2019
** Description: Node header file that includes a constructor
   that sets the value in the Node, as well as getter and
   setter functions. The getter and setter functions are
   used to access the values and next and prev variables in
   the List class. The Node object has three variables, the
   value in the node, a pointer to the next Node object in the
   list, and a pointer to the previous Node object in the list.
*************************************************************/
#ifndef NODE_HPP
#define NODE_HPP

class Node {
  private:
    int val;     // value of the node
    Node* next;  // points to next node in list
    Node* prev;  // poinst to prev node in list
  public:
    // default constructor
    Node();
    // destructor
    ~Node();
    // constructor
    Node(int);

    // getter functions
    int get_val();
    Node* get_next();
    Node* get_prev();

    // setter functions
    void set_val(int);
    void set_next(Node*);
    void set_prev(Node*); 
};

#endif
