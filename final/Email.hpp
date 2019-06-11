#ifndef EMAIL_HPP
#define EMAIL_HPP

#include <string>
#include <iostream>

class Email {
  private:
    std::string sender;
    std::string subject;
    std::string body;
    int status; // indicate whether email is read
  public:
    Email();
    ~Email();
    void compose(std::string,std::string,std::string);
    void read();
		int get_status();
		std::string get_sender();
};

#endif
