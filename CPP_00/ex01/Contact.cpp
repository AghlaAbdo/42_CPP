#include "PhoneBook.hpp"

string  strtrim(string str)
{
	int start;
	int end;

	start = str.find_first_not_of(" \n\t\r\f\v");
	end = str.find_last_not_of(" \n\t\r\f\v");
	if (start == string::npos && end == string::npos)
		return (str);
	else if (end == string::npos)
		return (str.substr(start));
	else if (start == string::npos)
		return (str.substr(0, end + 1));
	else
		return (str.substr(start, end + 1));
}

void    Contact::fillContact()
{
	firstName.clear();
	lastName.clear();
	nickName.clear();
	phoneNumber.clear();
	darkestSecret.clear();
	while (!firstName[0]) {
		cout << "Enter first name: ";
		getline(std::cin, firstName);
	}
	while (!lastName[0]) {
		cout << "Enter last name: ";
		getline(std::cin, lastName);
	}
	while (!nickName[0]) {
		cout << "Enter nickname: ";
		getline(std::cin, nickName);
	}
	while (!phoneNumber[0]) {
		cout << "Enter phone number: ";
		getline(std::cin, phoneNumber);
	}
	while (!darkestSecret[0]) {
		cout << "Enter darkest secret: ";
		getline(std::cin, darkestSecret);
	}
	firstName = strtrim(firstName);
	lastName = strtrim(lastName);
	nickName = strtrim(nickName);
	phoneNumber = strtrim(phoneNumber);
	darkestSecret = strtrim(darkestSecret);
}

void    Contact::search()
{
	cout << "first name:" << firstName << endl;
	cout << "last name: " << lastName << endl;
}

string	Contact::getFirstName()
{
	return (firstName);
}

string	Contact::getLastName()
{
	return (lastName);
}

string	Contact::getNickname()
{
	return (nickName);
}

string	Contact::getPhoneNumber()
{
	return (phoneNumber);
}

string	Contact::getSecret()
{
	return (darkestSecret);
}
