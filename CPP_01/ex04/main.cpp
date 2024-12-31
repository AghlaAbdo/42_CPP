/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:47:11 by aaghla            #+#    #+#             */
/*   Updated: 2024/12/31 22:35:50 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string	replaceStringInLine(std::string line, std::string str, std::string newStr)
{
	size_t	pos;

	pos = line.find(str);
	while (pos != std::string::npos) {
		line.erase(pos, str.length());
		line.insert(pos, newStr);
		pos = line.find(str, pos);
	}
	return (line);
}

int	main(int ac, char **av)
{
	std::ifstream	inFile;
	std::ofstream	outFile;
	std::string		line;
	std::string		outFileName;

	if (ac != 4) {
		std::cout << "invalid number of arguments\n";
		return (1);
	}

	outFileName = av[1];
	outFileName.append(".replace");

	inFile.open(av[1]);
	if (inFile.fail()) {
		std::cout << "Can't open file\n";
		return (2);
	}

	outFile.open(outFileName);
	if (outFile.fail()) {
		std::cout << "Can't open file\n";
		inFile.close();
		return (3);
	}

	while (!inFile.eof()) {
		std::getline(inFile, line);
		line = replaceStringInLine(line, av[2], av[3]);
		outFile << line;
		if (!inFile.eof())
			outFile << "\n";
	}

	inFile.close();
	outFile.close();
	return (0);
}
