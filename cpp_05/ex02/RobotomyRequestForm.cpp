#include "RobotomyRequestForm.hpp"

#include <cstdlib>

void RobotomyRequestForm::execute_action(void) const
{
	std::cout << "Bzz bzz (c'est une perceuse)" << std::endl;
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Failed operation ! " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
	: Form("RobotomyRequestForm", 72, 45, target)
{
}

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequestForm", 72, 45, ""){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &f) : Form(f){}

RobotomyRequestForm::~RobotomyRequestForm(void){}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
	{
		Form::operator=(rhs);
	}
	return *this;
}