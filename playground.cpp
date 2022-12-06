
#include <iostream>

class HumanA
{
public:
	HumanA(int &a_) : a(a_){};
	int &a;
	void tostring(void) const
	{
		std::cout << a << std::endl;
	}
};


int main()
{
	int test = 58;
	int &testref = test;

	std::cout << "test: " << test << std::endl;

	int b = 542;
	
	testref = b;

	std::cout << "test: " <<  test << std::endl;

	HumanA h = HumanA(b);

	h.tostring();
	b = 42;
	h.tostring();
	int c = 80;
	h.a = c;
	h.tostring();
}

