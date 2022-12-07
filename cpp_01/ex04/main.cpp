#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void	ft_exit(std::string const &str)
{
	std::cout << "error occured: " << str << std::endl;
	exit(1);
}

void	ft_read_file(std::ifstream const &ifs, std::string &str)
{
	std::ostringstream ostr;

	ostr << ifs.rdbuf();
	if (ifs.fail())
		ft_exit("read ifs");
	if (ostr.fail())
		ft_exit("write ostr");
	str = ostr.str();
}

void	ft_write_file(std::ofstream &ofs, std::string const &str)
{
	ofs << str;
	if (ofs.fail())
		ft_exit("write ofs");
}

void	ft_replace(std::string const &file, std::string const &s1, std::string const &s2, std::string &out)
{
	size_t			n(0);
	size_t			it_tmp(0);

	it_tmp = file.find(s1, n);
	while (it_tmp != std::string::npos)
	{
		out += file.substr(n, it_tmp);
		out += s2;
		n = it_tmp + std::strlen(s1.c_str());
		it_tmp = file.find(s1, n);
	}
	out += file.substr(n, std::string::npos);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		ft_exit("bad usage");
	
	std::ifstream ifs(argv[1]);
	if (!ifs.good())
		ft_exit("ifs");
	std::string	in;
	ft_read_file(ifs, in);

	std::string out;
	ft_replace(in, argv[2], argv[3], out);

	std::ofstream ofs((std::string)argv[1] + ".replace");
	if (!ofs.good())
		ft_exit("ofs");
	ft_write_file(ofs, out);
	return (0);
}
