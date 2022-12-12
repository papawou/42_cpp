#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
public:
//classes
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw()
		{
			return ("grade too high");
		}
	};
	class GradeTooLowException
	{
		virtual const char* what() const throw()
		{
			return ("grade too low");
		}
	};
//func
	void	incrGrade(void);
	void	decrGrade(void);

//getters
	std::string getName(void) const;
	int	getGrade(void) const;
	
//constructors
	Bureaucrat(std::string const &name, int const grade);
//colpien
	Bureaucrat(Bureaucrat const &);
	Bureaucrat &operator=(Bureaucrat const &);
	virtual ~Bureaucrat(void);
private:
	std::string const _name;
	int _grade;

	void checkGrade(int const grade) throw();
	void setGrade(int const grade);
	Bureaucrat(void);
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);

#endif