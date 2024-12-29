/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:03:54 by aaghla            #+#    #+#             */
/*   Updated: 2024/12/29 11:03:55 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int		lastIndex;
	void	printFirstName(Contact contact) const;
	void	printLastName(Contact contact) const;
	void	printNickname(Contact contact) const;
	void	printContact(Contact contact) const;
public:
	PhoneBook();
	void	addContact();
	void	searchContact();
};

std::string  strtrim(std::string str); 

#endif