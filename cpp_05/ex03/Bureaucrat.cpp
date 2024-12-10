#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
     << "." << std::endl;
  return os;
}

MyException::MyException(const std::string &message) : message(message) {}
MyException::~MyException() throw() {}

const char *MyException::what() const throw() { return message.c_str(); }

void Bureaucrat::signForm(AForm &form) {
  if (grade <= form.getSgrade()) {
    form.beSigned(*this);
    std::cout << name << " signed " << form.getName() << std::endl;
  } else
    std::cout << name << " couldn't sign " << form.getName()
              << " because his grade " << grade << " is lower then "
              << form.getSgrade() << std::endl;
}
void Bureaucrat::executeForm(AForm const &form) {
  form.checkReq(*this);
  form.execute(*this);
  std::cout << getName() << " executed " << form.getName() << std::endl;
}
