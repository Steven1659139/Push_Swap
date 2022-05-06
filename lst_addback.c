/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_addback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:50:41 by slavoie           #+#    #+#             */
/*   Updated: 2022/05/04 15:50:44 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	lst_addback(t_dlist **alst, t_dlist *new)
{
	t_dlist	*last;
	t_dlist	*first;

	first = *alst;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	last = lstlast(alst, *alst);
	new -> prev = last;
	last -> next = new;
	new ->next = *alst;
	first->prev = new;
}
