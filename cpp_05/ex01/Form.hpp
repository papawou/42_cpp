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
	virtual const char* what() const throw();
};
class GradeTooLowException : public std::exception
{
	virtual const char* what() const throw();
};

	void beSigned(Bureaucrat const &Bureaucrat);
//getters
	std::string getName(void) const;
	bool	getSign(void) const;
	int	getGradeSign(void) const;
	int getGradeExec(void) const;

	Form(std::string const &name, int const grade_sign, int const grade_exec);
//colpien
	Form(Form const &);
	virtual ~Form(void);
	Form &operator=(Form const &);
private:
	std::string const _name;
	bool _sign;
	int const _grade_sign;
	int	const _grade_exec;

	void	checkGrade(int const grade) const;
//colpien
	Form(void);
};

std::ostream &operator<<(std::ostream &os, Form const &form);

#include "Bureaucrat.hpp"
#endif