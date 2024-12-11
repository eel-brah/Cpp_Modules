#ifndef AFORM_H_
#define AFORM_H_

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class AForm {
private:
  const std::string name;
  bool sign;
  const int sgrade;
  const int egrade;

  virtual void perfomeAction() const = 0;

public:
  AForm();
  AForm(const std::string &name, int sgrade_, int egrade_);
  virtual ~AForm();
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
  class FormNotSign : public std::exception {
  public:
    const char *what() const throw();
  };
  std::string getName() const;
  bool getSign() const;
  int getSgrade() const;
  int getEgrade() const;
  void beSigned(const Bureaucrat &b);
  void execute(Bureaucrat const &executor) const;
};
std::ostream &operator<<(std::ostream &os, const AForm &From);

#endif
