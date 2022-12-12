#include "Bureaucrat.hpp"

int	main(void)
{	
	try
	{
		Bureaucrat b = Bureaucrat("test", 1);
		std::cout << b << std::endl;
		b.incrGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat b = Bureaucrat("test", 150);
		std::cout << b << std::endl;
		b.decrGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b = Bureaucrat("test", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b = Bureaucrat("test", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}