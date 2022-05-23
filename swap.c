/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:16:49 by slavoie           #+#    #+#             */
/*   Updated: 2022/05/03 16:20:34 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	sa(t_stacks *container, int print)
{
	if (container->size_a > 0)
	{
		if (container->size_a == 2)
			put_move(container, "ra", print);
		else
		{
			container->temp = container->a_head->next->next;
			container->a_head->prev->next = container->a_head->next;
			container->a_head->next->prev = container->a_head->prev;
			container->a_head->next->next = container->a_head;
			container->a_head->prev = container->a_head->next;
			container->a_head->next = container->temp;
			container->temp->prev = container->a_head;
			container->a_head = container->a_head->prev;
			container->nb_move += 1;
			if (print == 1)
				ft_putstr_fd("sa\n", 1);
		}
	}
}

void	sb(t_stacks *container, int print)
{
	if (container->size_b > 0)
	{
		if (container->size_b == 2)
			rotate(container, 'b', print);
		else
		{
			container->temp = container->b_head->next->next;
			container->b_head->prev->next = container->b_head->next;
			container->b_head->next->prev = container->b_head->prev;
			container->b_head->next->next = container->b_head;
			container->b_head->prev = container->b_head->next;
			container->b_head->next = container->temp;
			container->temp->prev = container->b_head;
			container->b_head = container->b_head->prev;
			container->nb_move += 1;
			if (print == 1)
				ft_putstr_fd("sb\n", 1);
		}
	}
}

void	ss(t_stacks *container, int print)
{
	sa(container, 0);
	sb(container, 0);
	if (print == 1)
		ft_putstr_fd("ss\n", 1);
	container->nb_move -= 1;
}
