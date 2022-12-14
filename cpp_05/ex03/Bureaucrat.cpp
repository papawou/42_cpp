#include "Bureaucrat.hpp"

//funcs
void	Bureaucrat::incrGrade(void)
{
	setGrade(_grade - 1);
}

void	Bureaucrat::decrGrade(void)
{
	setGrade(_grade + 1);
}

void	Bureaucrat::signForm(Form &form) const
{
	try
	{
		if (form.getSign())
			std::cout << getName() << " couldn't sign " << form.getName() << " because already signed" << std::endl;
		else
			form.beSigned(*this);
	}
	catch(Form::GradeTooLowException const &e)
	{
		std::cout << getName() << " couldn't sign " << form.getName() << " because grade too low" << std::endl;
	}
}

void	Bureaucrat::executeForm(Form const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

//private
void	Bureaucrat::setGrade(int const grade)
{
	checkGrade(grade);
	_grade = grade;
}

void	Bureaucrat::checkGrade(int const grade) const
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

//getters
std::string Bureaucrat::getName(void) const
{
	return _name;
}

int	Bureaucrat::getGrade(void) const
{
	return _grade;
}

//constructors
Bureaucrat::Bureaucrat(std::string const &name, int const grade) : _name(name)
{
	setGrade(grade);
}
//colpien
Bureaucrat::Bureaucrat(Bureaucrat const &b) : _name(b._name)
{
	setGrade(b._grade);
}

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150){}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		this->_grade = rhs._grade;
	return *this;
}

Bureaucrat::~Bureaucrat(void){}

//operators
std::ostream &operator<<(std::ostream &os, Bureaucrat const &b)
{
	os << b.getName() << ", " << "bureaucrat grade " << b.getGrade();
	return os;
}