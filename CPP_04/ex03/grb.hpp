/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grb.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:20:03 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/20 20:42:59 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRB_HPP
#define GRB_HPP

#include "AMateria.hpp"

typedef struct s_grbMateria
{
	AMateria			*m;
	struct s_grbMateria	*next;
}	t_grbMateria;

t_grbMateria	*newMateria(AMateria *m);
void			storeMateria(t_grbMateria **head, t_grbMateria *m);
// void			storeMateria(AMateria *m, int flag);
void			clearMaterias(t_grbMateria *head);


#endif