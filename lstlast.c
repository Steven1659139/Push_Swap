/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:50:29 by slavoie           #+#    #+#             */
/*   Updated: 2022/05/04 15:50:33 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

/* modifier nom et replacer dans la libft */

t_dlist	*lstlast(t_dlist **first, t_dlist *lst)
{
	if (!lst)
		return (0);
	if (lst -> next == *first)
		return (lst);
	while (lst -> next != *first)
		lst = lst -> next;
	return (lst);
}
