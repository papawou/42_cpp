#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

#include <string>

class Contact
{
public:
	Contact(
		std::string const &first_name,
		std::string const &last_name,
		std::string const &nickname,
		std::string const &darkest_secret,
		std::string const &phone_number
	);

	void to_string(void) const;
	void to_string_line(void) const;
	
	//Colpien
	Contact(void);
	Contact(Contact const &);
	Contact &operator=(Contact const &);
	~Contact(void);
private:
	std::string	_first_name;
	std::string	_last_name;
	std::string _nickname;
	std::string	_darkest_secret;
	std::string	_phone_number;
};


#endif