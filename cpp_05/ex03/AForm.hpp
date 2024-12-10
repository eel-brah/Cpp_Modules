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

public:
  AForm();
  AForm(const std::string &name, int sgrade_, int egrade_);
  virtual ~AForm();
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);

  std::string getName() const;
  bool getSign() const;
  int getSgrade() const;
  int getEgrade() const;
  void beSigned(const Bureaucrat &b);
  virtual void execute(Bureaucrat const &executor) const = 0;
  void checkReq(const Bureaucrat &b) const;
};
std::ostream &operator<<(std::ostream &os, const AForm &From);

#endif
