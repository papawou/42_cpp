#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "Form.hpp"

class Intern
{
public:
	Form* makeForm(std::string const &form, std::string const &target) const;

	Intern(void);
	Intern(Intern const &);
	~Intern(void);
	Intern &operator=(Intern const &);

public:
	class FormNotFound : public std::exception
	{
		virtual const char* what() const throw()
		{
			return ("!exception: form not found");
		}
	};
};

#endif