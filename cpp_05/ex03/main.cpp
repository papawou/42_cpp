#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <unistd.h>

int main()
{
	std::cout << "\n\n";

	Bureaucrat	Judas("Judas", 1);

	Form					*Buisson = new ShrubberyCreationForm("buisson");
	ShrubberyCreationForm	Arbres("Garden");
	RobotomyRequestForm		robot("Jean");
	PresidentialPardonForm	pres("Judas Iscariot");
//	Form					NotPossible;

//	Judas.signForm(Arbres);
	Judas.executeForm(Arbres);
	Judas.signForm(Arbres);
	Judas.executeForm(Arbres);
	Judas.signForm(robot);

	std::cout << "\n\n";
	
	for (int i = 0; i < 10; i++)
	{
		sleep(1);
		Judas.executeForm(robot);
	}

	Judas.signForm(pres);
	Judas.executeForm(pres);

	std::cout << "\n\n";

	std::cout << Judas << std::endl;
	std::cout << *Buisson << std::endl;
	std::cout << Arbres << std::endl;

	delete (Buisson);
	return (0);
}
