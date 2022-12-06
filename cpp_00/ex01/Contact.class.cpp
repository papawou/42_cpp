#include "Contact.class.hpp"

#include "phonebook.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact(
	std::string const &first_name,
	std::string const &last_name,
	std::string const &nickname,
	std::string const &darkest_secret,
	std::string const &phone_number
) : _first_name(first_name), _last_name(last_name), _nickname(nickname), _darkest_secret(darkest_secret), _phone_number(phone_number){}

void Contact::to_string(void) const
{
	std::cout << _first_name << std::endl;
	std::cout << _last_name << std::endl;
	std::cout << _nickname << std::endl;
	std::cout << _darkest_secret << std::endl;
	std::cout << _phone_number << std::endl;
}

void Contact::to_string_line(void) const
{
	std::cout << std::setfill(' ') << std::setw(10) << ft_truncate(_first_name) << '|';
	std::cout << std::setfill(' ') << std::setw(10) << ft_truncate(_last_name) << '|';
	std::cout << std::setfill(' ') << std::setw(10) << ft_truncate(_nickname);
}

//Colpien
Contact::Contact(void) : _first_name(), _last_name(), _nickname(), _darkest_secret(), _phone_number(){}

Contact::Contact(Contact const &contact) : _first_name(contact._first_name), _last_name(contact._last_name), _nickname(contact._nickname), _darkest_secret(contact._darkest_secret), _phone_number(contact._phone_number){}

Contact& Contact::operator=(Contact const &contact)
{
	this->_first_name = contact._first_name;
	this->_last_name = contact._last_name;
	this->_nickname = contact._nickname;
	this->_darkest_secret = contact._darkest_secret;
	this->_phone_number = contact._phone_number; 
	return (*this);
}

Contact::~Contact(void){};