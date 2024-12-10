#ifndef SHRUBBERYCREATIONFORM_H_
#define SHRUBBERYCREATIONFORM_H_

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
  std::string target;
public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string &target);
  ~ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

  void execute(Bureaucrat const &executor) const;
};

#endif
