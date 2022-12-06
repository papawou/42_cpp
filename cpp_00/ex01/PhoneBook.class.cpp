#include "PhoneBook.class.hpp"

#include "phonebook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(void) : _index(0){}

void	PhoneBook::add_contact(void)
{
	std::string	buf[5];

	ft_nonempty_getline(buf[0],"first name: ");
	ft_nonempty_getline(buf[1], "last name: ");
	ft_nonempty_getline(buf[2], "nickname: ");
	ft_nonempty_getline(buf[3], "darkest secret: ");
	ft_getint(buf[4], "phone number: ");
	if (_index == 8)
	{
		for(int i = 1; i < 8; ++i)
			_contacts[i - 1] = _contacts[i];
		--_index;
	}
	_contacts[_index] = Contact(buf[0], buf[1], buf[2], buf[3], buf[4]);
	++_index;
}

void	PhoneBook::print_contact(int const index) const
{
	if (_index <= index)
	{
		std::cout << "*contact not found*" << std::endl;
		return ;
	}
	_contacts[index].to_string();
}

void	PhoneBook::to_string(void) const
{
	if (_index == 0)
	{
		std::cout << "*phonebook empty*" << std::endl;
		return ;
	}
	for (int i = 0; i < _index; ++i)
	{
		std::cout << std::setfill(' ') << std::setw(10) << i << '|';
		_contacts[i].to_string_line();
		std::cout << std::endl; 
	}
}

int PhoneBook::getIndex(void) const
{
	return (_index);
}
