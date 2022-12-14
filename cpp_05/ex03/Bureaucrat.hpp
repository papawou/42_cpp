#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Form;

class Bureaucrat
{
public:
	void	incrGrade(void); //throw
	void	decrGrade(void); //throw
	void	signForm(Form &form) const;
	void	executeForm(Form const & form) const;

	std::string getName(void) const;
	int	getGrade(void) const;
	
	Bureaucrat(std::string const &name, int const grade);
	Bureaucrat(Bureaucrat const &);
	Bureaucrat &operator=(Bureaucrat const &);
	virtual ~Bureaucrat(void);

private:	
	std::string const _name;
	int _grade;

	void checkGrade(int const grade) const;
	void setGrade(int const grade);

	Bureaucrat(void);

public:
//classes
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);

#include "Form.hpp"
#endif