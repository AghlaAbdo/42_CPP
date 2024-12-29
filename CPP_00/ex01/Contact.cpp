/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:03:40 by aaghla            #+#    #+#             */
/*   Updated: 2024/12/29 11:57:45 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string  strtrim(std::string str)
{
	size_t start;
	size_t end;

	start = str.find_first_not_of(" \n\t\r\f\v");
	end = str.find_last_not_of(" \n\t\r\f\v");
	if (start == std::string::npos || end == std::string::npos)
		return ("");
	if (start == std::string::npos && end == std::string::npos)
		return (str);
	else if (end == std::string::npos)
		return (str.substr(start));
	else if (start == std::string::npos)
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
		if (!std::cin.eof())
			std::cout << "Enter first name: ";
		if (!std::getline(std::cin, firstName))
			exit(0);
		firstName = strtrim(firstName);
	}
	while (!lastName[0]) {
		if (!std::cin.eof())
			std::cout << "Enter last name: ";
		if (!std::getline(std::cin, lastName))
			exit(0);
		lastName = strtrim(lastName);
	}
	while (!nickName[0]) {
		if (!std::cin.eof())
			std::cout << "Enter nickname: ";
		if (!std::getline(std::cin, nickName))
			exit(0);
		nickName = strtrim(nickName);
	}
	while (!phoneNumber[0]) {
		if (!std::cin.eof())
			std::cout << "Enter phone number: ";
		if (!std::getline(std::cin, phoneNumber))
			exit(0);
		phoneNumber = strtrim(phoneNumber);
	}
	while (!darkestSecret[0]) {
		if (!std::cin.eof())
			std::cout << "Enter darkest secret: ";
		if (!std::getline(std::cin, darkestSecret))
			exit(0);
		darkestSecret = strtrim(darkestSecret);
	}
}

void    Contact::search()
{
	std::cout << "first name:" << firstName << "\n";
	std::cout << "last name: " << lastName << "\n";
}

std::string	Contact::getFirstName()
{
	return (firstName);
}

std::string	Contact::getLastName()
{
	return (lastName);
}

std::string	Contact::getNickname()
{
	return (nickName);
}

std::string	Contact::getPhoneNumber()
{
	return (phoneNumber);
}

std::string	Contact::getSecret()
{
	return (darkestSecret);
}
