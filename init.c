/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:49:32 by slavoie           #+#    #+#             */
/*   Updated: 2022/05/04 15:50:11 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	set_index(t_stacks *container)
{
	t_dlist	*ptr_ref;
	t_dlist	*ptr_check;
	int		min;
	int		i;

	i = 0;
	ptr_ref = container->a_head;
	while (i < container->size_a)
	{
		ptr_check = ptr_ref->next;
		min = ptr_ref->content;
		container->temp = ptr_ref;
		while (ptr_check != ptr_ref)
		{
			if ((ptr_check->content < min) && !(ptr_check->index))
			{
				min = ptr_check->content;
				container->temp = ptr_check;
			}
			ptr_check = ptr_check->next;
		}
		if (!(container->temp->index))
			container->temp->index = ++i;
		ptr_ref = ptr_ref->next;
	}
}
