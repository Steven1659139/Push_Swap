/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:09:29 by slavoie           #+#    #+#             */
/*   Updated: 2022/05/05 21:09:30 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

t_dlist	*find_min(t_stacks *container, char stack)
{
	t_dlist	*end;
	t_dlist	*ref;
	t_dlist	*min;

	if (stack == 'a' && container->a_head)
	{
		end = container->a_head;
		ref = container->a_head->next;
		min = container->a_head;
	}
	else if (stack == 'b' && container->b_head)
	{
		end = container->b_head;
		ref = container->b_head->next;
		min = container->b_head;
	}
	else
		return (NULL);
	while (ref != end)
	{
		if (min->index > ref->index)
			min = ref;
		ref = ref->next;
	}
	return (min);
}

t_dlist	*find_max(t_stacks *container, char stack)
{
	t_dlist	*end;
	t_dlist	*ref;
	t_dlist	*max;

	if (stack == 'a' && container->a_head)
	{
		end = container->a_head;
		ref = container->a_head->next;
		max = container->a_head;
	}
	else if (stack == 'b' && container->b_head)
	{
		end = container->b_head;
		ref = container->b_head->next;
		max = container->b_head;
	}
	else
		return (NULL);
	while (ref != end)
	{
		if (max->index < ref->index)
			max = ref;
		ref = ref->next;
	}
	return (max);
}

t_dlist	*find_node(t_stacks *container, int min, int max, char stack)
{
	t_dlist	*end;
	t_dlist	*node;

	if (stack == 'a')
	{
		end = container->a_head;
		node = container->a_head;
	}
	else
	{
		end = container->b_head;
		node = container->b_head;
	}
	if (!node)
		return (NULL);
	while (node->next != end)
	{
		if (node->index >= min && node->index <= max)
			return (node);
		node = node->next;
	}
	if (node->index >= min && node->index <= max)
		return (node);
	return (NULL);
}

t_dlist	*find_node_bottom(t_stacks *container, int min, int max, char stack)
{
	int		i;
	t_dlist	*end;
	t_dlist	*node;

	i = 1;
	if (stack == 'a')
	{
		end = container->a_head;
		node = container->a_head;
	}
	else
	{
		end = container->b_head;
		node = container->b_head;
	}
	while (node->prev != end)
	{
		if (node->index >= min && node->index <= max)
			return (node);
		node = node->prev;
	}
	return (NULL);
}
