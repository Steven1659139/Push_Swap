/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <slavoie@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:48:19 by slavoie           #+#    #+#             */
/*   Updated: 2021/06/07 16:49:13 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_dlist **lst, void (*del) (void *))
{
	t_dlist	*elem;
	int		i;

	i = ft_lstsize(*lst);
	while (i != 0)
	{
		elem = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = elem;
		i--;
	}
}
