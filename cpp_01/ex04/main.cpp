#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void	ft_read_file(std::ifstream const &ifs, std::string &out_buf)
{
	std::ostringstream ostr;

	ostr << ifs.rdbuf();
	out_buf = ostr.str();
}

void	ft_replace(std::string const &file, std::string const &s1, std::string const &s2)
{
	size_t it(0);
	std::string out;
	size_t it_tmp(0);
	
	it = file.find(s1, it_tmp);
	while (it != std::string::npos)
	{
		out += file.substr(it_tmp, it);
		out += s2;
		it_tmp = it + std::strlen(s2.c_str());
		it = file.find(s1, it_tmp);
	}
	out += file.substr(it_tmp, it);

	std::cout << out;
}

int	main(int argc, char **argv)
{
	std::string filename(argv[1]);
	std::ifstream ifs(filename);
	std::string	buf;

	if (argc != 4)
		return (1);
	if (!ifs.good())
	{
		std::cout << "error occured for open " << filename << std::endl;
		return (1);
	}
	ft_read_file(ifs, buf);
	ft_replace(buf, argv[2], argv[3]);
	return (0);
}
