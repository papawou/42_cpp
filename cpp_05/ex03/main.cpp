#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <unistd.h>

int main()
{
	std::cout << "\n\n";

	Bureaucrat				Judas("Judas", 1);
	Intern					slave;
	PresidentialPardonForm	pres("Judas Iscariot");
	Form					*kew;
	Form					*aha;


	Judas.signForm(pres);
	Judas.executeForm(pres);

	kew = slave.makeForm("RobotomyRequestForm", "Tamer");
	if (kew != NULL)
	{
		std::cout << *kew << std::endl;
		Judas.signForm(*kew);
		Judas.executeForm(*kew);
		delete (kew);
	}
	aha = slave.makeForm("NotAValidForm", "himself");
	if (aha != NULL)
	{
		std::cout << *aha << std::endl;
		Judas.signForm(*aha);
		Judas.executeForm(*aha);
		delete aha;
	}
	return (0);
}
