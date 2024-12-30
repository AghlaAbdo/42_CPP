/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:05:26 by aaghla            #+#    #+#             */
/*   Updated: 2024/12/30 18:12:02 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";

	std::string		*stringPTR = &str;
	std::string&	stringREF = str;
	
	std::cout << &str << "\n" << stringPTR << "\n" << &stringREF << "\n";
	std::cout << str << "\n" << *stringPTR << "\n" << stringREF << "\n";
}