#include "phonebook.hpp"

#include "PhoneBook.class.hpp"
#include "phonebook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook book;
	std::string entry;

	do
	{
		ft_nonempty_getline(entry, "[ADD, SEARCH, EXIT]: ");	
		if (entry == "ADD")
			book.add_contact();
		else if (entry == "SEARCH")
		{
			book.to_string();
			if (book.getIndex() == 0)
				continue ;
			ft_getint(entry, "select contact: ");
			book.print_contact(std::atoi(entry.c_str()));
		}
		else if (entry == "EXIT")
			return (0);	
	} while (1);
}
