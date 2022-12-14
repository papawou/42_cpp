#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(PresidentialPardonForm const &);
	virtual ~PresidentialPardonForm(void);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &);
private:
	PresidentialPardonForm(void);
	void	execute_action(void) const;
};

#endif