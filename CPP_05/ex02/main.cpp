/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:55:59 by aaghla            #+#    #+#             */
/*   Updated: 2025/02/02 13:38:50 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Aform.hpp"

int	main(void)
{
	try {
        std::cout << "\nCreating Form with valid grades..." << std::endl;
        Form form("Form1", 50, 100);
        std::cout << form << std::endl;

        std::cout << "\nCreating Bureaucrat with grade 40..." << std::endl;
        Bureaucrat bur("Alice", 40);
        std::cout << bur << std::endl;

        std::cout << "Trying to sign the form with Alice..." << std::endl;
        form.beSigned(bur);
        std::cout << "After signing:\n" << form << std::endl;

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "\nCreating Form with invalid sign grade (0, should throw)..." << std::endl;
        Form invalidForm("InvalidForm", 0, 100);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "\nCreating Form with invalid exec grade (151, should throw)..." << std::endl;
        Form invalidForm("InvalidForm", 50, 151);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "\nCreating Form with valid grades..." << std::endl;
        Form form("Form2", 20, 30);
        std::cout << form << std::endl;

        std::cout << "\nCreating Bureaucrat with grade 50 (too low to sign)..." << std::endl;
        Bureaucrat bur("Bob", 50);
        std::cout << bur << std::endl;

        std::cout << "Trying to sign the form with Bob (should throw)..." << std::endl;
        form.beSigned(bur);

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

	
	return (0);
}
