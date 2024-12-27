#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"
using std::cout;
using std::endl;
using std::string;

class PhoneBook {
private:
	Contact contacts[8];
	int		lastIndex;
	void	printFirstName(Contact contact);
	void	printLastName(Contact contact);
	void	printNickname(Contact contact);
	void	printContact(Contact contact);
public:
	PhoneBook();
	void	addContact();
	void	searchContact();
};

#endif