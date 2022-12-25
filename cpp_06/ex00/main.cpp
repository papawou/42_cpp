#include <sstream>
#include "Conversion.hpp"

int	main(int argc, char **argv)
{
	Conversion	c((std::string)argv[1]);

	if (argc != 2)
		return (1);

	std::string str = argv[1];
	
}
