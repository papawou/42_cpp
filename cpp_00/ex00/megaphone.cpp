#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for(int i = 1; i < argc; i++)
	{
		for(std::size_t j = 0; j < std::strlen(argv[i]); j++)
			std::cout << (char)std::toupper(argv[i][j]);
		if (i != argc - 1)
			std::cout << ' ';
	}
	std::cout << std::endl;
	return (0);
}
