#include <sstream>
#include <iostream>
#include "Conversion.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	Conversion c(argv[1]);
	c.castType();
	return (0);
}
