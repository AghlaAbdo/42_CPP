/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:02:52 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/17 21:35:34 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class	Brain {
private:
	std::string	ideas[100];
	
public:
	Brain(void);
	Brain(const Brain &copy);
	~Brain(void);
	Brain	&operator=(const Brain &copy);
	void	setBrainIdea(int index, std::string idea);
	std::string	getIdea(int index);
};

#endif