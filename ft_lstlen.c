/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:08:30 by slavoie           #+#    #+#             */
/*   Updated: 2022/05/05 21:08:33 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

size_t	ft_lstlen(t_dlist **first)
{
	int		i;
	t_dlist	*lst;

	i = 0;
	if (!*first)
		return (0);
	lst = *first;
	while (lst->next != *first)
	{
		i++;
		lst = lst->next;
	}
	return (++i);
}
