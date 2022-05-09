/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <slavoie@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:43:05 by slavoie           #+#    #+#             */
/*   Updated: 2021/06/07 11:40:16 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_dlist *lst)
{
	int		size;
	t_dlist	*ref;

	if (!lst)
		return (0);
	ref = lst;
	size = 0;
	while (lst->next != ref)
	{
		lst = lst -> next;
		size++;
	}
	size++;
	return (size);
}
