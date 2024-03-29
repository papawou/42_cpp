#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main(void)
{
	{
		MutantStack<int> mstack;

		mstack.push(1);
		mstack.push(2);

		std::cout << "top: " << mstack.top() << std::endl;

		mstack.pop();
		std::cout << "top: " << mstack.top() << std::endl;

		mstack.push(3);
		mstack.push(4);
		mstack.push(5);
		mstack.push(6);

		std::cout << "top: " << mstack.top() << std::endl;
		std::cout << "size: " << mstack.size() << std::endl;

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		while(it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);

		std::cout << "copy size: " << s.size() << std::endl;
		std::cout << "original size: "<< mstack.size() << std::endl;

		MutantStack<int>::reverse_iterator it_reverse = mstack.rbegin();
		MutantStack<int>::reverse_iterator ite_reverse = mstack.rend();

		while(it_reverse != ite_reverse)
		{
			std::cout << *it_reverse << std::endl;
			++it_reverse;
		}
	}
	std::cout << "--------------" << std::endl;
	{
		MutantStack<int, std::list<int> > mstack;

		mstack.push(1);
		mstack.push(2);

		std::cout << "top: " << mstack.top() << std::endl;

		mstack.pop();
		std::cout << "top: " << mstack.top() << std::endl;

		mstack.push(3);
		mstack.push(4);
		mstack.push(5);
		mstack.push(6);

		std::cout << "top: " << mstack.top() << std::endl;
		std::cout << "size: " << mstack.size() << std::endl;

		MutantStack<int, std::list<int> >::iterator it = mstack.begin();
		MutantStack<int, std::list<int> >::iterator ite = mstack.end();

		++it;
		--it;

		while(it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int, std::list<int> > s(mstack);

		std::cout << "copy size: " << s.size() << std::endl;
		std::cout << "original size: "<< mstack.size() << std::endl;

		MutantStack<int, std::list<int> >::reverse_iterator it_reverse = mstack.rbegin();
		MutantStack<int, std::list<int> >::reverse_iterator ite_reverse = mstack.rend();

		while(it_reverse != ite_reverse)
		{
			std::cout << *it_reverse << std::endl;
			++it_reverse;
		}
	}

	return 0;
}
