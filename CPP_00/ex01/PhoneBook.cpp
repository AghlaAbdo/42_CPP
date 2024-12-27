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

void	PhoneBook::printFirstName(Contact contact)
{
	int	len;
	int	j;

	len = contact.getFirstName().length();
	if (len > 10)
	{
		j = -1;
		while (++j < 9)
		{
			cout << contact.getFirstName()[j];
		}
		cout << ".";
	}
	else
	{
		j = -1;
		while (++j < 10 - len)
			cout << " ";
		cout << contact.getFirstName();
	}
	cout << "|";
}

void	PhoneBook::printLastName(Contact contact)
{
	int	len;
	int	j;

	len = contact.getLastName().length();
	if (len > 10)
	{
		j = -1;
		while (++j < 9)
		{
			cout << contact.getLastName()[j];
		}
		cout << ".";
	}
	else
	{
		j = -1;
		while (++j < 10 - len)
			cout << " ";
		cout << contact.getLastName();
	}
	cout << "|";

}

void	PhoneBook::printNickname(Contact contact)
{
	int	len;
	int	j;

	len = contact.getNickname().length();
	if (len > 10)
	{
		j = -1;
		while (++j < 9)
		{
			cout << contact.getNickname()[j];
		}
		cout << ".";
	}
	else
	{
		j = -1;
		while (++j < 10 - len)
			cout << " ";
		cout << contact.getNickname();
	}
}

void	PhoneBook::printContact(Contact contact)
{
	cout << "First name: " << contact.getFirstName() << endl;
	cout << "Last name: " << contact.getLastName() << endl;
	cout << "Nickname: " << contact.getNickname() << endl;
	cout << "Phone number: " << contact.getPhoneNumber() << endl;
	cout << "Darkest secret: " << contact.getSecret() << endl;
}

void	PhoneBook::searchContact()
{
	string str;
	int		index;
	int		i;

	if (!contacts[0].getFirstName()[0]) {
		cout << "Empty contact" << endl;
		return ;
	}
	i = -1;
	while (++i < 8)
	{
		if (!contacts[i].getFirstName()[0])
			break ;
		cout << "         " << i + 1 << "|";
		printFirstName(contacts[i]);
		printLastName(contacts[i]);
		printNickname(contacts[i]);
		cout << endl;
	}
	while (!str[0]) {
		cout << "Enter contact index: ";
		getline(std::cin, str);
	}
	if (str.find_first_not_of("0123456789") != -1)
	{
		cout << "invalid index number" << endl;
		return ;
	}
	index = std::stoi(str);
	cout << index << endl;
	if (index == 0 || index > 8 || !contacts[index -1].getFirstName()[0])
		cout << "Index out of range" << endl;
	else {
		printContact(contacts[index - 1]);
	}
}
