#ifndef INTERN_H_
#define INTERN_H_

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
private:
public:
  Intern();
  ~Intern();
  Intern(const Intern &other);
  Intern &operator=(const Intern &other);

  class InvalidFormName : public std::exception {
  public:
    const char *what() const throw();
  };
  AForm *makeForm(const std::string &form, const std::string &target);
  AForm *makeShrubbeyCreation(const std::string &target);
  AForm *makePresidentialPardon(const std::string &target);
  AForm *makeRobotomyRequest(const std::string &target);

AForm *f2(AForm *(Intern::*forms)(const std::string &target), const std::string &form, const std::string &target);
AForm *f1(AForm *(Intern::*forms)(const std::string &target), const std::string &form, const std::string &target);
};

#endif
