#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 146, 138), target("target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 138), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other) {
  target = other.target;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    target = other.target;
  }
  return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  checkReq(executor);
  std::ofstream outFile(target + "_shrubbery");
  if (!outFile) {
    throw MyException("ShrubberyCreationForm::ErrorOpeningTheFile\n");
  }
  outFile << "               ,@@@@@@@," << std::endl;
  outFile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
  outFile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
  outFile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
  outFile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
  outFile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
  outFile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
  outFile << "       |o|        | |         | |" << std::endl;
  outFile << "       |.|        | |         | |" << std::endl;
  outFile << "  __\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
  outFile.close();
}
