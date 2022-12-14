#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <ostream>

class Bureaucrat;

class Form
{
public:
//classes
class GradeTooHighException : public std::exception
{
	virtual const char* what() const throw()
	{
		return ("!exception: grade too high");
	}
};
class GradeTooLowException : public std::exception
{
	virtual const char* what() const throw()
	{
		return ("!exception: grade too low");
	}
};
class FormUnsignedException : public std::exception
{
	virtual const char* what() const throw()
	{
		return ("!exception: form unsigned");
	}
};

	void beSigned(Bureaucrat const &signor);
	void execute(Bureaucrat const &executor) const;
//getters
	std::string getName(void) const;
	bool	getSign(void) const;
	int	getGradeSign(void) const;
	int getGradeExec(void) const;
	std::string getTarget(void) const;

	Form(std::string const &name, int const grade_sign, int const grade_exec, std::string const &target);
//colpien
	Form(Form const &);
	virtual ~Form(void);
	Form &operator=(Form const &);
protected:
	std::string _target;
private:
	std::string const _name;
	bool _sign;
	int const _grade_sign;
	int	const _grade_exec;

	virtual void execute_action(void) const = 0;
	void	checkGrade(int const grade) const;
//colpien
	Form(void);
};

std::ostream &operator<<(std::ostream &os, Form const &form);

#include "Bureaucrat.hpp"
#endif