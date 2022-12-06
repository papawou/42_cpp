#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"

class PhoneBook
{
public:
	void	add_contact(void);
	void	print_contact(int const index) const;
	void	to_string(void) const;

	int getIndex(void) const;

	PhoneBook(void);
private:
	int	_index;
	Contact _contacts[8];
};

#endif