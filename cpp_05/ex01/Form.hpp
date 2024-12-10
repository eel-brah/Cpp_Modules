#ifndef FORM_H_
#define FORM_H_

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form {
  private:
    const std::string name;
    bool sign;
    const int sgrade;
    const int egrade;
  public:
    Form();
    Form(const std::string& name, int sgrade_, int egrade_);
    ~Form();
    Form(const Form& other);
    Form& operator=(const Form& other);
    
    std::string getName() const;
    bool getSign() const;
    int getSgrade() const;
    int getEgrade() const;
    void beSigned(const Bureaucrat& b);
};
std::ostream &operator<<(std::ostream &os, const Form &From);

#endif
