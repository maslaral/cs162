/*************************************************************
** Program name: Final project
** Author: Alex Maslar
** Date: June 10 2019
** Description: 
*************************************************************/
#include "Email.hpp"

#include <string>

/*************************************************************
** Description: Default constructor - sets each email status
   to not read.
*************************************************************/
Email::Email(){
  status = 0; // unread
}

/*************************************************************
** Description: Virtual destructor
*************************************************************/
Email::~Email(){
}

/*************************************************************
** Description: Compose an email - takes the arguments sender,
   subject, and body. Used to create new emails.
*************************************************************/
void Email::compose(std::string sender, std::string subject, std::string body){
  this->sender = sender;
  this->subject = subject;
  this->body = body;
}

/*************************************************************
** Description: Prints out the entire email when called.
*************************************************************/
void Email::read(){
  std::cout << "From: " << sender << std::endl;
  std::cout << "Subject: " << subject << std::endl;
  std::cout << "Body: " << body << std::endl;
  status = 1; // read
}

/*************************************************************
** Description: Returns the read status of the email.
*************************************************************/
int Email::get_status(){
	return status;
}

/*************************************************************
** Description: Returns the email sender.
*************************************************************/
std::string Email::get_sender(){
	return sender;
}
