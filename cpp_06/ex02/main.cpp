#include <sstream>
#include <iostream>
#include "Base.hpp"

Base *generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			return new A();
			break ;
		case 1:
			return new B();
			break ;
	}
	return new C();
}

void	identify(Base *p)
{
	A* a = dynamic_cast<A*>(p);
	if (a != NULL)
	{
		std::cout << "is A" << std::endl;
		return ;
	}
	
	B* b = dynamic_cast<B*>(p);
	if (b != NULL)
	{
		std::cout << "is B" << std::endl;
		return ;
	}

	C* c = dynamic_cast<C*>(p);
	if (c != NULL)
	{
		std::cout << "is C" << std::endl;
		return ;
	}
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "is A" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
	}

	try
	{
		B &b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "is B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		C &c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "is C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	
	srand (time(NULL));

	Base *b = generate();
	identify(b);
	identify(*b);
	delete b;
	return (0);
}
