#ifndef BUREAUCRAT_H_
#define BUREAUCRAT_H_

#include <exception>
#include <iostream>

class Bureaucrat {
private:
  const std::string name;
  int grade;

public:
  Bureaucrat();
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(const std::string &message);
  ~Bureaucrat();
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);

  class MyException : public std::exception {
  private:
    std::string message;

  public:
    MyException(const std::string &message);
    ~MyException() throw();

    const char *what() const throw();
  };
  std::string getName() const;
  int getGrade() const;
  void promotion();
  void demotion();
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);

#endif
