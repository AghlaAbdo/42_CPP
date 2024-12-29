/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:03:45 by aaghla            #+#    #+#             */
/*   Updated: 2024/12/29 11:55:37 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	lastIndex= 0;
}

void    PhoneBook::addContact()
{
	contacts[lastIndex].fillContact();
	if (lastIndex < 7)
		lastIndex++;
}

void	PhoneBook::printFirstName(Contact contact) const
{
	int	len;
	int	j;

	len = contact.getFirstName().length();
	if (len > 10)
	{
		j = -1;
		while (++j < 9)
		{
			std::cout << contact.getFirstName()[j];
		}
		std::cout << ".";
	}
	else
	{
		j = -1;
		while (++j < 10 - len)
			std::cout << " ";
		std::cout << contact.getFirstName();
	}
	std::cout << "|";
}

void	PhoneBook::printLastName(Contact contact) const
{
	int	len;
	int	j;

	len = contact.getLastName().length();
	if (len > 10)
	{
		j = -1;
		while (++j < 9)
		{
			std::cout << contact.getLastName()[j];
		}
		std::cout << ".";
	}
	else
	{
		j = -1;
		while (++j < 10 - len)
			std::cout << " ";
		std::cout << contact.getLastName();
	}
	std::cout << "|";

}

void	PhoneBook::printNickname(Contact contact) const
{
	int	len;
	int	j;

	len = contact.getNickname().length();
	if (len > 10)
	{
		j = -1;
		while (++j < 9)
		{
			std::cout << contact.getNickname()[j];
		}
		std::cout << ".";
	}
	else
	{
		j = -1;
		while (++j < 10 - len)
			std::cout << " ";
		std::cout << contact.getNickname();
	}
}

void	PhoneBook::printContact(Contact contact) const
{
	std::cout << "First name: " << contact.getFirstName() << "\n";
	std::cout << "Last name: " << contact.getLastName() << "\n";
	std::cout << "Nickname: " << contact.getNickname() << "\n";
	std::cout << "Phone number: " << contact.getPhoneNumber() << "\n";
	std::cout << "Darkest secret: " << contact.getSecret() << "\n";
}

void	PhoneBook::searchContact()
{
	std::string str;
	int		index;
	int		i;

	if (!contacts[0].getFirstName()[0]) {
		std::cout << "Empty contact" << "\n";
		return ;
	}
	i = -1;
	while (++i < 8)
	{
		if (!contacts[i].getFirstName()[0])
			break ;
		std::cout << "         " << i + 1 << "|";
		printFirstName(contacts[i]);
		printLastName(contacts[i]);
		printNickname(contacts[i]);
		std::cout << "\n";
	}
	while (!str[0]) {
		std::cout << "Enter contact index: ";
		if (!getline(std::cin, str))
			exit(0);
	}
	if (str.find_first_not_of("0123456789") != std::string::npos)
	{
		if (!std::cin.eof())
			std::cout << "invalid index number" << "\n";
		return ;
	}
	index = std::stoi(str);
	std::cout << index << "\n";
	if (index == 0 || index > 8 || !contacts[index -1].getFirstName()[0])
		std::cout << "Index out of range" << "\n";
	else {
		printContact(contacts[index - 1]);
	}
}
