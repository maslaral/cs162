#include "Desk.hpp"
#include "Email.hpp"
#include "Menu.hpp"

Desk::Desk(){
  email1.compose("Tom", "Weekly Meeting", "Here are the notes from our meeting...");
  email2.compose("Janice", "Birthday Cake", "Leftover birthday cake in the breakroom!");
  email3.compose("Peg", "Important Changes", "We've made the decision to restructure departments...");
  email4.compose("Janice", "Re:Birthday Cake", "It's gone.");
  email5.compose("Jerry", "Meeting last week", "Thanks for volunteering to write the report for Dave...");
}

Desk::~Desk(){
}

int Desk::action(){
  int time_taken = 0;

  // initialize inbox
  Menu emails("Vandelay Industries Inbox");
  emails.addOptions(email1.get_sender());
  emails.addOptions(email2.get_sender());
  emails.addOptions(email3.get_sender());
  emails.addOptions(email4.get_sender());
  emails.addOptions(email5.get_sender());
  emails.addOptions("Leave Inbox");
  emails.outputMenu();

  while (emails.getUserInput() != 6){
    switch (emails.getUserInput()){
      case 1: 
        if (email1.get_status() != 1){
          email1.read();
          time_taken += 10;
        }
        else {
          std::cout << "Message already read!" << std::endl;
        }
        break;
      case 2:
        if (email2.get_status() != 1){
          email2.read();
          time_taken += 10;
        }
        else {
          std::cout << "Message already read!" << std::endl;
        }
        break;
      case 3:
        if (email3.get_status() != 1){
          email3.read();
          time_taken += 10;
        }
        else {
          std::cout << "Message already read!" << std::endl;
        }
        break;
      case 4:
        if (email4.get_status() != 1){
          email4.read();
          time_taken += 10;
        }
        else {
          std::cout << "Message already read!" << std::endl;
        }
        break;
      case 5:
        if (email5.get_status() != 1){
          email5.read();
          time_taken += 10;
        }
        else {
          std::cout << "Message already read!" << std::endl;
        }
        break;
    }
  }
  return time_taken;
}
