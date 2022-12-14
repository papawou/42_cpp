#include "PresidentialPardonForm.hpp"
#include <fstream>

void PresidentialPardonForm::execute_action(void) const
{
	std::cout << "T'es pardonne " << _target << " by Zaphod Beeblerox" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Form("PresidentialPardonForm", 25, 5, target){}

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5, ""){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &f) : Form(f){}

PresidentialPardonForm::~PresidentialPardonForm(void){}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
	{
		Form::operator=(rhs);
	}
	return *this;
}