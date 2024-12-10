#ifndef FORM_H_
#define FORM_H_

#include "Bureaucrat.hpp"
#include <iostream>

class Form {
private:
  const std::string name;
  bool sign;
  const int sgrade;
  const int egrade;

public:
  Form();
  Form(const std::string &name, int sgrade_, int egrade_);
  ~Form();
  Form(const Form &other);
  Form &operator=(const Form &other);

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
  std::string getName() const;
  bool getSign() const;
  int getSgrade() const;
  int getEgrade() const;
  void beSigned(const Bureaucrat &b);
};
std::ostream &operator<<(std::ostream &os, const Form &From);

#endif
