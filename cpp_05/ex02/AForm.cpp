#include "AForm.hpp"

AForm::AForm() : name("FormX"), sign(false), sgrade(1), egrade(1) {}

AForm::AForm(const std::string &name, int sgrade_, int egrade_)
    : name(name), sign(false), sgrade(1), egrade(1) {

  if (sgrade_ < 1 || egrade_ < 1)
    throw AForm::GradeTooHighException();
  else if (sgrade_ > 150 || egrade_ > 150)
    throw AForm::GradeTooLowException();
  else {
    const int *p;
    p = &sgrade;
    *(int *)p = sgrade_;
    p = &egrade;
    *(int *)p = egrade_;
  }
}

AForm::~AForm() {}

AForm::AForm(const AForm &other) : sgrade(1), egrade(1) { *this = other; }

AForm &AForm::operator=(const AForm &other) {
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

std::string AForm::getName() const { return name; }

bool AForm::getSign() const { return sign; }

int AForm::getSgrade() const { return sgrade; }

int AForm::getEgrade() const { return egrade; }

std::ostream &operator<<(std::ostream &os, const AForm &AForm) {
  os << AForm.getName() << " is ";
  if (!AForm.getSign())
    os << "not ";
  os << "signed, it require grade " << AForm.getSgrade() << " to sign it and "
     << AForm.getEgrade() << " to execute it.\n";
  return os;
}

void AForm::beSigned(const Bureaucrat &b) {
  if (b.getGrade() > sgrade) {
    throw AForm::GradeTooLowException();
  } else {
    sign = true;
  }
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade too low!";
}

const char *AForm::FormNotSign::what() const throw() {
  return "Form not sign!";
}

void AForm::execute(Bureaucrat const &executor) const {
  if (!this->getSign()) {
    throw AForm::FormNotSign();
  } else if (executor.getGrade() > this->getEgrade()) {
    throw AForm::GradeTooLowException();
  }
  perfomeAction();
}
