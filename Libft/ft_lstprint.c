/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:10:56 by slavoie           #+#    #+#             */
/*   Updated: 2022/05/03 16:11:14 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_dlist *first)
{
	t_dlist	*ptr;

	ptr = first;
	if (!first)
		return ;
	while (ptr->next != first)
	{	
		printf("%d -> ", ptr->content);
		ptr = ptr->next;
	}
	printf("%d -> \n", ptr->content);
}
