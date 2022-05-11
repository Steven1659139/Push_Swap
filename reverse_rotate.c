/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:11:43 by slavoie           #+#    #+#             */
/*   Updated: 2022/05/03 17:13:13 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	reverse_rotate(t_stacks *container, char stack, int print)
{
	if (stack == 'r')
	{
		if (container->a_head)
			container->a_head = container->a_head->prev;
		if (container->b_head)
			container->b_head = container->b_head->prev;
		container->nb_move += 1;
		if (print == 1)
			ft_putstr_fd("rrr\n", 1);
	}
	else if (stack == 'a' && container->a_head)
	{
		container->a_head = container->a_head->prev;
		container->nb_move += 1;
		if (print == 1)
			ft_putstr_fd("rra\n", 1);
	}
	else if (stack == 'b' && container->b_head)
	{
		container->b_head = container->b_head->prev;
		container->nb_move += 1;
		if (print == 1)
			ft_putstr_fd("rrb\n", 1);
	}
}
