/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:09:18 by slavoie           #+#    #+#             */
/*   Updated: 2022/05/05 21:09:19 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	size_chunk(t_stacks *container)
{
	int	chunk_size;

	chunk_size = 0;
	if (container->size_max <= 100)
		chunk_size = 15;
	else if (container->size_max > 100 && container->size_max <= 1000)
		chunk_size = 33;
	else
		chunk_size = container->size_max * 0.03;
	return (chunk_size);
}

int	check_chunk(int max, int min, t_stacks *container)
{
	int	res;

	container->temp = container->a_head;
	res = 0;
	if (!container->temp)
		return (0);
	while (container->temp->next != container->a_head && !res)
	{
		if (container->temp->index <= max && container->temp->index >= min)
			res = 1;
		container->temp = container->temp->next;
	}
	return (res);
}
