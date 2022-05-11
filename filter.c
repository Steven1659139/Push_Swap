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

void	put_move(t_stacks *container, char *move, int print)
{
	if (*move != 's' && *move != 'r' && *move != 'p')
		yo_its_wrong("Error\n");
	else if (*move == 's' && ft_strlen(move) == 2)
		filter_swap(container, *(++move), print);
	else if (*move == 'p')
		filter_push(container, *(++move), print);
	else if (*move == 'r' && ft_strlen(move) == 2)
		filter_rotate(container, *(++move), print);
	else if (*move == 'r' && ft_strlen(move) == 3)
	{
		move++;
		filter_reverse_rotate(container, *(++move), print);
	}
	else
		yo_its_wrong("Error\n");
}

void	filter_push(t_stacks *container, char c, int print)
{
	if (c == 'a')
		pa(container, print);
	else if (c == 'b')
		pb(container, print);
	else
		yo_its_wrong("Erreur push.\n");
}

void	filter_swap(t_stacks *container, char c, int print)
{
	if (c == 'a')
		sa(container, print);
	else if (c == 'b')
		sb(container, print);
	else if (c == 's')
		ss(container, print);
	else
		yo_its_wrong("Erreur swap.\n");
}

void	filter_rotate(t_stacks *container, char c, int print)
{
	if (c == 'a')
		rotate(container, c, print);
	else if (c == 'b')
		rotate(container, c, print);
	else if (c == 'r')
		rotate(container, c, print);
	else
		yo_its_wrong("Erreur rotate.\n");
}

void	filter_reverse_rotate(t_stacks *container, char c, int print)
{
	if (c == 'a')
		reverse_rotate(container, c, print);
	else if (c == 'b')
		reverse_rotate(container, c, print);
	else if (c == 'r')
		reverse_rotate(container, c, print);
	else
		yo_its_wrong("Erreur reverse_rotate.\n");
}
