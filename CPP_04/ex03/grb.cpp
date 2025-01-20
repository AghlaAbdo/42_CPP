/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grb.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:21:25 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/20 20:43:06 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grb.hpp"

t_grbMateria	*newMateria(AMateria *m)
{
	t_grbMateria	*newlst;

	newlst = new(t_grbMateria);
	
	newlst->m = m;
	newlst->next = NULL;
	return (newlst);
}

void	storeMateria(t_grbMateria **head, t_grbMateria *m)
{
	t_grbMateria	*ptr;

	if (!*head) {
		*head = m;
		return ;
	}
	ptr = *head;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = m;
}

// void	storeMateria(AMateria *m, int flag)
// {
// 	static t_grbMateria	*buff;
// 	t_grbMateria	*curr;

// 	if (flag == STORE)
// 		addMateria(&buff, newMateria(m));
// 	else if (flag == DELETE)
// 	{
// 		while (buff)
// 		{
// 			curr = buff;
// 			buff = buff->next;
// 			delete curr->m;
// 			delete curr;
// 		}
// 	}
// }

void	clearMaterias(t_grbMateria *head)
{
	t_grbMateria	*curr;

	while (head)
	{
		curr = head;
		head = head->next;
		delete curr->m;
		delete curr;
	}
}
