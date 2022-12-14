#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ostream>


Form*	Intern::makeForm(std::string const &form, std::string const &target) const
{
	static std::string const forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	int n = -1;

	for(int i = 0; i < 3; ++i)
		if (forms[i] == form)
		{
			n = i;
			break ;
		}

	try
	{
		switch (n)
		{
			case 0:
				return new RobotomyRequestForm(target);
			case 1:
				return new PresidentialPardonForm(target);
			case 2:
				return new ShrubberyCreationForm(target);
			default:
				throw Intern::FormNotFound();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (NULL);
	}
}


Intern::Intern(void)
{
}

Intern::Intern(Intern const &i)
{
}

Intern::~Intern(void)
{
}

Intern &Intern::operator=(Intern const &rhs)
{
	(void) rhs;
	return (*this);
}