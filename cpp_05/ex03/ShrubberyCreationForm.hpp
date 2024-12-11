#ifndef SHRUBBERYCREATIONFORM_H_
#define SHRUBBERYCREATIONFORM_H_

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
  std::string target;

  void perfomeAction() const;

public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string &target);
  ~ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

  class ErrorOpeningTheFile : public std::exception {
  public:
    const char *what() const throw();
  };
};

#endif
