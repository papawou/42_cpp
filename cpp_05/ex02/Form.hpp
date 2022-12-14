#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <ostream>

class Bureaucrat;

class Form
{
public:
	void beSigned(Bureaucrat const &signor); //throw
	void execute(Bureaucrat const &executor) const; //throw

	std::string getName(void) const;
	bool	getSign(void) const;
	int	getGradeSign(void) const;
	int getGradeExec(void) const;
	std::string getTarget(void) const;

	Form(std::string const &name, int const grade_sign, int const grade_exec, std::string const &target);
	Form(Form const &);
	virtual ~Form(void);
	Form &operator=(Form const &);

private:
	std::string const _name;
	bool _sign;
	int const _grade_sign;
	int	const _grade_exec;
	std::string _target;

	virtual void execute_action(void) const = 0;
	void	checkGrade(int const grade) const;

	Form(void);

public:
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class FormUnsignedException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, Form const &form);

#include "Bureaucrat.hpp"
#endif