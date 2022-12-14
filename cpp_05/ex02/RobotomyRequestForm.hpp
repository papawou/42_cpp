#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &);
	virtual ~RobotomyRequestForm(void);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &);
private:
	RobotomyRequestForm(void);
	void	execute_action(void) const;
};

#endif