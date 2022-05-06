/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:20:59 by slavoie           #+#    #+#             */
/*   Updated: 2022/05/03 17:09:20 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	check_sort(t_stacks *cont, int nb)
{
	int	i;

	i = 1;
	cont->temp = cont->a_head;
	while (cont->temp->next != cont->a_head)
	{
		if ((cont->temp->content > cont->temp->next->content))
			return (0);
		cont->temp = cont->temp->next;
		i++;
	}
	if (i < nb)
		return (0);
	return (1);
}

void	sort3(t_stacks *cont)
{
	int	top;
	int	mid;
	int	bottom;

	while (!check_sort(cont, cont->size_a))
	{
		top = cont->a_head->content;
		mid = cont->a_head->next->content;
		bottom = cont->a_head->prev->content;
		if (((top > mid) && (top < bottom)) || ((top < mid) && (top < bottom)))
			put_move(cont, "sa");
		else if ((top < mid) && (top > bottom))
			put_move(cont, "rra");
		else if ((top > mid) && (top > bottom))
			put_move(cont, "ra");
	}
}

void	sort5(t_stacks *cont)
{
	t_dlist	*min;

	if (!check_sort(cont, cont->size_a))
	{
		while (cont->size_a > 3)
		{
			min = find_min(cont, 'a');
			on_top(cont, min, 'a');
			pb(cont);
		}
		sort3(cont);
		while (cont->size_a < cont->size_max)
			pa(cont);
	}
}

void	universal_sort(t_stacks *cont)
{
	int		chunk;
	int		min_chk;
	int		max_chk;
	t_dlist	*node;

	chunk = size_chunk(cont);
	min_chk = (cont->size_max / 2) - chunk;
	max_chk = (cont->size_max / 2) + chunk;
	while (cont->size_a > 0)
	{
		if (cont->a_head->index >= min_chk && cont->a_head->index <= max_chk)
			put_move(cont, "pb");
		if (!(check_chunk(max_chk, min_chk, cont)))
		{
			min_chk -= chunk;
			max_chk += chunk;
		}
		if (get_top(cont->b_head) < cont->size_max / 2)
			put_move(cont, "rb");
		node = find_node(cont, min_chk, max_chk, 'a');
		on_top(cont, node, 'a');
	}
	ah_shit_here_we_go_again(cont);
}

void	ah_shit_here_we_go_again(t_stacks *cont)
{
	int		min;
	t_dlist	*node;

	while (cont->size_b > 0)
	{
		min = get_min(cont, 'a');
		node = find_max(cont, 'b');
		on_top(cont, node, 'b');
		put_move(cont, "pa");
		if (cont->a_head)
		{
			if (cont->a_head->index > cont->a_head->next->index)
				put_move(cont, "sa");
		}
	}
}
