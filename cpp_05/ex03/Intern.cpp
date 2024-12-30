#include "Intern.hpp"

Intern::Intern() {}
Intern::~Intern() {}

Intern::Intern(const Intern &other) { (void)other; }

Intern &Intern::operator=(const Intern &other) {
  (void)other;
  return *this;
}

AForm *Intern::makeShrubbeyCreation(const std::string &target) {
  return (new ShrubberyCreationForm(target));
}
AForm *Intern::makePresidentialPardon(const std::string &target) {
  return (new PresidentialPardonForm(target));
}
AForm *Intern::makeRobotomyRequest(const std::string &target) {
  return (new RobotomyRequestForm(target));
}

AForm *Intern::makeForm(const std::string &form, const std::string &target) {
  AForm *(Intern::*forms[3])(const std::string &target) = {
      &Intern::makeRobotomyRequest, &Intern::makePresidentialPardon,
      &Intern::makeShrubbeyCreation};

  std::string forms_name[3] = {"robotomy request", "presidential pardon",
                               "shrubbey creation"};

  for (int i = 0; i < 3; ++i) {
    if (form == forms_name[i]) {
      std::cout << "Intern creates " << form << std::endl;
      try {
        return (this->*forms[i])(target);
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return NULL;
      }
    }
  }
  throw Intern::InvalidFormName();
  return NULL;
}

const char *Intern::InvalidFormName::what() const throw() {
  return "Invalid form name!";
}
