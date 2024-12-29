/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:03:52 by aaghla            #+#    #+#             */
/*   Updated: 2024/12/29 11:03:53 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
private:
	std::string  firstName;
	std::string  lastName;
	std::string  nickName;
	std::string  phoneNumber;
	std::string  darkestSecret;
public:
	void		fillContact();
	void		search();
	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickname();
	std::string	getPhoneNumber();
	std::string	getSecret();
};

#endif