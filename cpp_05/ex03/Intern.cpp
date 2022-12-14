#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ostream>


Form*	Intern::makeForm(std::string const &form, std::string const &target) const
{
	std::string const forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	Form *ret;

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
				ret = new RobotomyRequestForm(target);
			case 1:
				ret = new PresidentialPardonForm(target);
			case 2:
				ret = new ShrubberyCreationForm(target);
			default:
				throw Intern::FormNotFound();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (NULL);
	}
	std::cout << "Intern creates " << ret->getName() << std::endl; 
	return (ret);
}


Intern::Intern(void)
{
}

Intern::Intern(Intern const &i)
{
	(void) i;
}

Intern::~Intern(void)
{
}

Intern &Intern::operator=(Intern const &rhs)
{
	(void) rhs;
	return (*this);
}

const char* Intern::FormNotFound::what() const throw()
{
	return ("!exception: form not found");
}