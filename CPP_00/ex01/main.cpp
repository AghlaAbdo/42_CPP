/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:09:10 by aaghla            #+#    #+#             */
/*   Updated: 2024/12/25 15:31:13 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

using std::cout;
using std::endl;
using std::string;
using std::getline;





int main(void)
{
	PhoneBook	phoneBook;
	string		line;
	int			i;

	while (1)
	{
		getline(std::cin, line);
		if (!line.compare("ADD"))
			phoneBook.addContact();
		else if (!line.compare("SEARCH"))
			phoneBook.searchContact();
		else if (!line.compare("EXIT"))
			break ;
		
		
	}
	return (0);
}