/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:08:16 by slavoie           #+#    #+#             */
/*   Updated: 2022/05/05 21:08:19 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	get_top(t_dlist *stack)
{
	if (!stack)
		return (0);
	return (stack->index);
}

int	get_max(t_stacks *container, char stack)
{
	int	max;

	if (stack == 'a' && !container->a_head)
		return (0);
	if (stack == 'b' && !container->b_head)
		return (0);
	max = find_max(container, stack)->index;
	return (max);
}

int	get_min(t_stacks *container, char stack)
{
	int	min;

	if (stack == 'a' && !container->a_head)
		return (0);
	if (stack == 'b' && !container->b_head)
		return (0);
	min = find_min(container, stack)->index;
	return (min);
}

int	get_node(t_dlist *list, int index)
{
	int	node;

	while (list->position != index)
		list = list->next;
	node = list->index;
	return (node);
}

t_dlist	*i_can_get_node(t_stacks *container, int min)
{
	t_dlist		*node1;
	t_dlist		*node2;
	static int	count;

	count++;
	node1 = find_node(container, min, min + 3, 'b');
	node2 = find_node_bottom(container, min, min + 3, 'b');
	update_position(container);
	if ((!node1 || !node2) || count < 2)
		return (find_max(container, 'b'));
	if (node1->position < node2->position)
		return (node1);
	else
		return (node2);
}
