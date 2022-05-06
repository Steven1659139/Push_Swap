/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:08:50 by slavoie           #+#    #+#             */
/*   Updated: 2022/05/05 21:08:52 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	lstadd(t_dlist **first, t_dlist *new)
{
	static int	index;
	t_dlist		*elem1;
	t_dlist		*last;

	index++;
	if (!*first || index == 1)
	{
		*first = new;
		return ;
	}
	elem1 = *first;
	last = elem1->prev;
	new->prev = last;
	new->next = *first;
	last->next = new;
	elem1->prev = new;
}
