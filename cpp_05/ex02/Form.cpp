#include "Form.hpp"

void	Form::beSigned(Bureaucrat const &signor) throw()
{
	if (signor.getGrade() > _grade_sign)
		throw Form::GradeTooLowException();
	_sign = true;
}

void	Form::execute(Bureaucrat const &executor) const throw()
{
	if (executor.getGrade() > _grade_exec)
		throw Form::GradeTooLowException();
	if (!_sign)
		throw	Form::FormUnsignedException();
	this->execute_action();
}

//getters
std::string Form::getName(void) const
{
	return _name;
}

bool	Form::getSign(void) const
{
	return _sign;
}

int	Form::getGradeSign(void) const
{
	return _grade_sign;
}

int Form::getGradeExec(void) const
{
	return _grade_exec;
}

std::string	Form::getTarget(void) const
{
	return _target;
}

//private
void	Form::checkGrade(int const grade) const throw()
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	if (grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(std::string const &name, int const grade_sign, int const grade_exec, std::string const &target)
	: _target(target), _name(name), _sign(false), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	checkGrade(_grade_exec);
	checkGrade(_grade_sign);
}

//colpien
Form::Form(void) : _sign(false), _grade_sign(0), _grade_exec(0){}
Form::Form(Form const &form) : _target(form._target), _name(form._name), _grade_sign(form._grade_sign), _grade_exec(form._grade_exec){}
Form &Form::operator=(Form const &form)
{
	if (this != &form)
	{
		this->_sign = form._sign;
		this->_target = form._target;
	}
	return *this;
}
Form::~Form(void){}

std::ostream &operator<<(std::ostream &os, Form const &form)
{
	os << "Form: " << form.getName() << ", grade_sign " << form.getGradeSign() << ", grade_exec " << form.getGradeExec() << ", sign " << form.getSign() << ", target " << form.getTarget();
	return os;
}