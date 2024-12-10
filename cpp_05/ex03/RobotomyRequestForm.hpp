#ifndef ROBOTOMYREQUESTFORM_H_
#define ROBOTOMYREQUESTFORM_H_

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
  std::string target;
  static int robo_rate;

public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string &target);
  ~RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm &other);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

  void execute(Bureaucrat const &executor) const;
};

#endif
