#ifndef INTERN_H_
#define INTERN_H_

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
private:

public:
  Intern();
  // Intern(const std::string &form, const std::string &target);
  ~Intern();
  Intern(const Intern &other);
  Intern &operator=(const Intern &other);

  AForm* makeForm(const std::string &form, const std::string &target);
  AForm* makeShrubbeyCreation(const std::string &target);
  AForm* makePresidentialPardon(const std::string &target);
  AForm* makeRobotomyRequest(const std::string &target);
};

#endif
