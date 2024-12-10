#include "RobotomyRequestForm.hpp"

int RobotomyRequestForm::robo_rate = 1;

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other) {
  target = other.target;
  robo_rate = other.robo_rate;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    target = other.target;
    robo_rate = other.robo_rate;
  }
  return *this;
}

void RobotomyRequestForm::perfomeAction() const {
  if (robo_rate % 2)
    std::cout << "BRRRRRRRRRRRR\n"
              << target << " has been robotomized successfully." << std::endl;
  else
    std::cout << "Robotomy failed." << std::endl;
  robo_rate++;
}
