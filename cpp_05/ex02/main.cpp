#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat b("name", 1);
	Form *f = new RobotomyRequestForm("test");

	b.signForm(*f);
	b.executeForm(*f);
}