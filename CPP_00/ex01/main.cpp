/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:09:10 by aaghla            #+#    #+#             */
/*   Updated: 2024/12/29 11:53:31 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phoneBook;
	std::string	line;

	while (1)
	{
		if (!std::cin.eof())
			std::cout << "CMD=> ";
		if (!std::getline(std::cin, line))
			return (0);
		line = strtrim(line);
		if (!line.compare("ADD"))
			phoneBook.addContact();
		else if (!line.compare("SEARCH"))
			phoneBook.searchContact();
		else if (!line.compare("EXIT"))
			break ;
	}
	return (0);
}