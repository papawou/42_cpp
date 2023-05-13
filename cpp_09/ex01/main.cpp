#include <iostream>
#include <string>
#include <stack>
#include <sstream>

void pout(std::string const &str)
{
	std::cout << "Error: " << str << std::endl;
}

int operate(int lhs, char op, int rhs)
{
	switch(op)
	{
		case '+':
			return lhs + rhs;
		case '-':
			return lhs - rhs;
		case '/':
			if (rhs == 0)
				throw ("divide by zero");
			return lhs / rhs;
		default:
			return lhs * rhs;
	}
}

int main(int argc, char *argv[])
{
	std::string const operators("+-/*");
	std::stack<int> stack;
	std::istringstream is(argv[1]);
	std::string tmp;

	if (argc != 2)
	{
		pout("expect an argument");
		return (1);
	}

	while (!is.eof())
	{
		is >> tmp;
		if (tmp.length() != 1)
		{
			pout("expect one char");
			return (1);
		}
		if (isdigit(tmp[0]))
			stack.push(tmp[0] - '0');
		else if (operators.find(tmp[0]) != std::string::npos)
		{
			if (stack.size() < 2)
			{
				pout("incorrect format");
				return (1);
			}
			int rhs = stack.top();
			stack.pop();
			int lhs = stack.top();
			stack.pop();
			try {
				stack.push(operate(lhs, tmp[0], rhs));
			}
			catch (const char *e)
			{
				pout(e);
				return (1);
			}
		}
		else
		{
			pout("unknown char");
			return (1);
		}
	}

	std::cout << stack.top() << std::endl;
	return (0);
}