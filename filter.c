/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:09:40 by slavoie           #+#    #+#             */
/*   Updated: 2022/05/05 21:11:05 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Push_swap.h"

void	put_move(t_stacks *container, char *move)
{
	if (*move == 's')
		filter_swap(container, *(++move));
	else if (*move == 'p')
		filter_push(container, *(++move));
	else if (ft_strlen(move) == 2)
		rotate(container, *(++move));
	else if (ft_strlen(move) == 3)
	{
		move++;
		reverse_rotate(container, *(++move));
	}
}

void	filter_push(t_stacks *container, char c)
{
	if (c == 'a')
		pa(container);
	else if (c == 'b')
		pb(container);
	else
		yo_its_wrong();
}

void	filter_swap(t_stacks *container, char c)
{
	if (c == 'a')
		sa(container);
	else if (c == 'b')
		sb(container);
	else if (c == 's')
		ss(container);
	else
		yo_its_wrong();
}

void	filter_rotate(t_stacks *container, char c)
{
	if (c == 'a')
		rotate(container, c);
	else if (c == 'b')
		rotate(container, c);
	else if (c == 'r')
		rotate(container, c);
	else
		yo_its_wrong();
}

void	filter_reverse_rotate(t_stacks *container, char c)
{
	if (c == 'a')
		reverse_rotate(container, c);
	else if (c == 'b')
		reverse_rotate(container, c);
	else if (c == 'r')
		reverse_rotate(container, c);
	else
		yo_its_wrong();
}
