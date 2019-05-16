#ifndef WINNER_QUEUE_HPP
#define WINNER_QUEUE_HPP

class Winner_Queue {
  private:
    Character* on_deck;
    Character* last;
  public:
    // constructor
    Winner_Queue();
    // destructor
    ~Winner_Queue();

    bool is_empty();
    void add_winner(Character*);
    Character* get_on_deck();
    void remove_on_deck();
};

#endif
