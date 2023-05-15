#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <sstream>

class RPN
{
public:
	class RPNException : public std::exception
	{
		virtual const char *what() const throw();
	};
	static int process(std::string const &str);

private:
	static int operate(int lhs, char op, int rhs);

	RPN(void);
	RPN(const RPN &rhs);
	RPN &operator=(const RPN &rhs);
	virtual ~RPN(void);
};

const char *RPN::RPNException::what() const throw()
{
	return ("Error");
}

#endif