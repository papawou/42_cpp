#include "RPN.hpp"

int RPN::operate(int lhs, char op, int rhs)
{
	switch (op)
	{
	case '+':
		return lhs + rhs;
	case '-':
		return lhs - rhs;
	case '/':
		if (rhs == 0)
			throw RPN::RPNException();
		return lhs / rhs;
	default:
		return lhs * rhs;
	}
}

int RPN::process(std::string const &str)
{
	std::string const operators("+-/*");
	std::stack<int> stack;
	std::istringstream is(str);
	std::string tmp;

	while (!is.eof())
	{
		is >> tmp;
		if (tmp.length() != 1)
			RPN::RPNException();
		if (isdigit(tmp[0]))
			stack.push(tmp[0] - '0');
		else if (operators.find(tmp[0]) != std::string::npos)
		{
			if (stack.size() < 2)
				throw RPN::RPNException();
			int rhs = stack.top();
			stack.pop();
			int lhs = stack.top();
			stack.pop();
			stack.push(RPN::operate(lhs, tmp[0], rhs));
		}
		else
			throw (RPN::RPNException());
	}
	if (stack.size() != 1)
		throw (RPN::RPNException());
	return stack.top();
}

RPN::RPN(void)
{
}

RPN::RPN(const RPN &rhs)
{
	(void) rhs;
}

RPN &RPN::operator=(const RPN &rhs)
{
	(void) rhs;
	return *this;
}

RPN::~RPN(void)
{
}