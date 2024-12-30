#ifndef BUREAUCRAT_H_
#define BUREAUCRAT_H_

#include <exception>
#include <iostream>
class Form;

class Bureaucrat {
private:
  const std::string name;
  int grade;

public:
  Bureaucrat();
  Bureaucrat(const std::string &name, int grade);
  ~Bureaucrat();
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
  std::string getName() const;
  int getGrade() const;
  void promotion();
  void demotion();
  void signForm(Form &form);
};
std::ostream &operator<<(std::ostream &os, const Bureaucrat &Bureaucrat);

#endif
