#include "Bureaucrat.hpp"

int	main(void)
{	
	try
	{
		std::cout << "Bureaucrat b = Bureaucrat(\"test\", 1)" << std::endl;
		Bureaucrat b = Bureaucrat("test", 1);
		std::cout << b << std::endl;
		std::cout << "b.incrGrade()" << std::endl;
		b.incrGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "Bureaucrat b = Bureaucrat(\"test\", 150)" << std::endl;
		Bureaucrat b = Bureaucrat("test", 150);
		std::cout << b << std::endl;
		std::cout << "b.decrGrade()" << std::endl;
		b.decrGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "Bureaucrat b = Bureaucrat(\"test\", 0)" << std::endl;
		Bureaucrat b = Bureaucrat("test", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "Bureaucrat b = Bureaucrat(\"test\", 151)" << std::endl;
		Bureaucrat b = Bureaucrat("test", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}