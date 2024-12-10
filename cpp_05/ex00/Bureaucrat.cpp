#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade_) : name(name) {
  if (grade_ < 1)
    throw MyException("Bureaucrat::GradeTooHighException\n");
  else if (grade_ > 150)
    throw MyException("Bureaucrat::GradeTooLowException\n");
  else
    grade = grade_;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) { *this = other; }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    (std::string) name = other.name;
    grade = other.grade;
  }
  return *this;
}

std::string Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::promotion() {
  if (grade - 1 < 1)
    throw MyException("Bureaucrat::GradeTooHighException\n");
  else
    grade--;
}

void Bureaucrat::demotion() {
  if (grade + 1 > 150)
    throw MyException("Bureaucrat::GradeTooLowException\n");
  else
    grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return os;
}

Bureaucrat::MyException::MyException(const std::string &message)
    : message(message) {}
Bureaucrat::MyException::~MyException() throw() {}

const char *Bureaucrat::MyException::what() const throw() {
  return message.c_str();
}
