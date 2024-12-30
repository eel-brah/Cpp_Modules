#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade_) : name(name) {
  if (grade_ < 1)
    throw Bureaucrat::GradeTooHighException();
  else if (grade_ > 150)
    throw Bureaucrat::GradeTooLowException();
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
    throw Bureaucrat::GradeTooHighException();
  else
    grade--;
}

void Bureaucrat::demotion() {
  if (grade + 1 > 150)
    throw Bureaucrat::GradeTooLowException();
  else
    grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
     << "." << std::endl;
  return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade too low!";
}
