#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

class Person
{
  protected:
    std::string name;
    int age;
    double rating_gpa;
  public:
    Person();
    virtual ~Person();
    int get_age();
    std::string get_name();
    double get_rating_gpa();
    virtual int get_type() = 0;
    virtual void set_rating_gpa() = 0;
    virtual void set_age() = 0;
    virtual void do_work() = 0;
    virtual void print_rating_gpa() = 0;
    virtual void set_rating_gpa_file(double) = 0;
    virtual void set_name(std::string) = 0;
    virtual void set_age_file(int) = 0;
};

#endif
