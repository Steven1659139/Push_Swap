/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:09:35 by slavoie           #+#    #+#             */
/*   Updated: 2022/05/03 17:11:34 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	rotate(t_stacks *container, char stack, int print)
{
	if (stack == 'r')
	{
		if (container->a_head)
			container->a_head = container->a_head->next;
		if (container->b_head)
			container->b_head = container->b_head->next;
		container->nb_move += 1;
		if (print == 1)
			ft_putstr_fd("rr\n", 1);
	}
	else if (stack == 'a' && container->a_head)
	{
		container->a_head = container->a_head->next;
		container->nb_move += 1;
		if (print == 1)
			ft_putstr_fd("ra\n", 1);
	}
	else if (stack == 'b' && container->b_head)
	{
		container->b_head = container->b_head->next;
		container->nb_move += 1;
		if (print == 1)
			ft_putstr_fd("rb\n", 1);
	}
}
