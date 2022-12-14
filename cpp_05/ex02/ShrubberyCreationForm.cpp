#include "ShrubberyCreationForm.hpp"

#include <fstream>

void ShrubberyCreationForm::execute_action(void) const
{
	std::string tree((std::string)
		"       _-_\n" +
		"    /~~   ~~\\\n" +
		" /~~         ~~\\\n" +
		"{               }\n" +
		" \\  _-     -_  /\n" +
		"   ~  \\ //  ~\n" +
		"_- -   | | _- _\n" +
		"  _ -  | |   -_\n" +
		"      // \\\n"
	);

	std::ofstream ofs(getTarget() + "_shruberry");
	if (!ofs.good())
		std::cerr << "ofs open error" << std::endl;
	ofs << tree;
	if (ofs.fail())
		std::cerr << "ofs write error" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form("ShrubberyCreationForm", 145, 137, target){}

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 145, 137, ""){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &f) : Form(f){}

ShrubberyCreationForm::~ShrubberyCreationForm(void){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
	{
		Form::operator=(rhs);
	}
	return *this;
}