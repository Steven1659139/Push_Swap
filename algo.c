/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:22:53 by slavoie           #+#    #+#             */
/*   Updated: 2022/05/05 21:22:56 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Push_swap.h"

void	algo(t_stacks *container)
{
	if (!check_sort(container, container->size_max))
	{
		if (container->size_max <= 5)
			sort5(container);
		else
			universal_sort(container);
	}
}

void	on_top_b(t_stacks *container, t_dlist *node)
{
	int	size;

	size = container->size_b;
	while (container->b_head != node)
	{
		update_position(container);
		replace(container);
		if (node->position > (size / 2))
			put_move(container, "rrb", 1);
		else
			put_move(container, "rb", 1);
	}
}

void	on_top(t_stacks *container, t_dlist *node, char stack)
{
	int	size;

	if (!node)
		return ;
	if (stack == 'a')
	{
		size = container->size_a;
		while (container->a_head != node)
		{
			update_position(container);
			if (node->position > (size / 2))
				put_move(container, "rra", 1);
			else
				put_move(container, "ra", 1);
		}
	}
	else
		on_top_b(container, node);
}

void	replace(t_stacks *container)
{
	t_dlist	*node;

	node = container->a_head;
	if (container->a_head)
	{
		if (container->a_head->index > container->a_head->next->index)
			put_move(container, "sa", 1);
	}
	if (container->b_head->index == get_max(container, 'b') - 1)
		put_move(container, "pa", 1);
}
