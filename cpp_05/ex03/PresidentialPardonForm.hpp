#ifndef PRESIDENTIALPARDONFORM_H_
#define PRESIDENTIALPARDONFORM_H_

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
  std::string target;
public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string &target);
  ~PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm &other);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

  void execute(Bureaucrat const &executor) const;
};

#endif
