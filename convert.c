/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:11:20 by slavoie           #+#    #+#             */
/*   Updated: 2022/05/05 21:11:22 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	table_flip(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	convert(t_stacks *container, char *argv)
{
	char		**tab;
	t_dlist		*stack_a;
	long long	inter;
	int			i;

	i = 0;
	tab = ft_split(argv, ' ');
	if (!tab)
		exit(0);
	while (tab[i])
	{
		inter = ft_atoi(tab[i]);
		if (!int_checker(inter))
			yo_its_wrong("Les nombres doivent tenir dans un int.\n");
		lstadd(&stack_a, lstnew_dbl(inter));
		container->size_a += 1;
		i++;
	}
	table_flip(tab);
	if (!twin_checker(&stack_a))
		yo_its_wrong("Il ne peut pas y avoir de doublon.\n");
	container->a_head = stack_a;
	container->size_max = container->size_a;
	set_index(container);
}

void	convert_sep(t_stacks *container, char **argv)
{
	int			i;
	long long	inter;
	t_dlist		*stack_a;

	i = 0;
	inter = 0;
	while (argv[i] != NULL)
	{
		inter = ft_atoi(argv[i]);
		if (!int_checker(inter))
			yo_its_wrong("Les nombres doivent tenir dans un int.\n");
		if (ft_strchr(argv[i], ' '))
			yo_its_wrong("Que des espaces");
		lstadd(&stack_a, lstnew_dbl(inter));
		i++;
		container->size_a += 1;
	}
	if (!twin_checker(&stack_a))
		yo_its_wrong("Il ne peut pas y avoir de doublon.\n");
	container->a_head = stack_a;
	container->size_max = container->size_a;
	set_index(container);
	update_position(container);
}
