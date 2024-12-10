#include "Form.hpp"

Form::Form() : name("FormX"), sign(false), sgrade(1), egrade(1) {}

Form::Form(const std::string &name, int sgrade_, int egrade_)
    : name(name), sign(false), sgrade(1), egrade(1) {

  if (sgrade < 1 || egrade_ < 1)
    throw Form::GradeTooHighException();
  else if (sgrade_ > 150 || egrade_ > 150)
    throw Form::GradeTooLowException();
  else {
    const int *p;
    p = &sgrade;
    *(int *)p = sgrade_;
    p = &egrade;
    *(int *)p = egrade_;
  }
}

Form::~Form() {}

Form::Form(const Form &other) : sgrade(1), egrade(1) { *this = other; }

Form &Form::operator=(const Form &other) {
  if (this != &other) {
    (std::string) name = other.name;
    const int *p;
    p = &sgrade;
    *(int *)p = other.sgrade;
    p = &egrade;
    *(int *)p = other.egrade;
    sign = other.sign;
  }
  return *this;
}

std::string Form::getName() const { return name; }

bool Form::getSign() const { return sign; }

int Form::getSgrade() const { return sgrade; }

int Form::getEgrade() const { return egrade; }

std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << form.getName() << " is ";
  if (!form.getSign())
    os << "not ";
  os << "signed, it require grade " << form.getSgrade() << " to sign it and "
     << form.getEgrade() << " to execute it.\n";
  return os;
}

void Form::beSigned(const Bureaucrat &b) {
  if (b.getGrade() > sgrade) {
    throw Form::GradeTooLowException();
  } else {
    sign = true;
  }
}

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade too low!";
}
