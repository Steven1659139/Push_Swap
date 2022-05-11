/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:46:22 by slavoie           #+#    #+#             */
/*   Updated: 2022/05/03 17:47:00 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	pb(t_stacks *container, int print)
{
	if (container->size_a > 0)
	{
		if (!container->b_head)
			first_call_b(container);
		else
		{
			container->temp = container->a_head->next;
			container->a_head->prev->next = container->a_head->next;
			container->a_head->next->prev = container->a_head->prev;
			container->a_head->next = container->b_head;
			container->a_head->prev = container->b_head->prev;
			container->b_head->prev->next = container->a_head;
			container->b_head->prev = container->a_head;
			container->b_head = container->a_head;
			container->a_head = container->temp;
		}
		update_stack_b(container);
		if (print == 1)
			ft_putstr_fd("pb\n", 1);
	}
}

void	pa(t_stacks *container, int print)
{
	if (container->size_b > 0)
	{
		if (!container->a_head)
			first_call_a(container);
		else
		{
			container->temp = container->b_head->next;
			container->b_head->prev->next = container->b_head->next;
			container->b_head->next->prev = container->b_head->prev;
			container->b_head->next = container->a_head;
			container->b_head->prev = container->a_head->prev;
			container->a_head->prev->next = container->b_head;
			container->a_head->prev = container->b_head;
			container->a_head = container->b_head;
			container->b_head = container->temp;
			container->temp = container->b_head->next;
		}
		update_stack_a(container);
		if (print == 1)
			ft_putstr_fd("pa\n", 1);
	}
}

void	first_call_a(t_stacks *container)
{
	container->temp = container->b_head->next;
	container->a_head = container->b_head;
	container->b_head->next->prev = container->b_head->prev;
	container->b_head->prev->next = container->b_head->next;
	container->a_head->next = container->a_head;
	container->a_head->prev = container->a_head;
	container->b_head = container->temp;
}

void	first_call_b(t_stacks *container)
{
	container->temp = container->a_head->next;
	container->b_head = container->a_head;
	container->a_head->next->prev = container->a_head->prev;
	container->a_head->prev->next = container->a_head->next;
	container->b_head->next = container->b_head;
	container->b_head->prev = container->b_head;
	container->a_head = container->temp;
}
