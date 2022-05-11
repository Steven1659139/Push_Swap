/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:48:52 by slavoie           #+#    #+#             */
/*   Updated: 2022/05/04 15:48:55 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	int_checker(long long nb)
{
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	return (1);
}

int	twin_checker(t_dlist **lst)
{
	t_dlist	*ptr_ref;
	t_dlist	*ptr_check;

	ptr_ref = *lst;
	while (ptr_ref->next != *lst)
	{
		ptr_check = ptr_ref->next;
		while (ptr_check != *lst)
		{
			if (ptr_ref->content == ptr_check->content)
				return (0);
			ptr_check = ptr_check->next;
		}
		ptr_ref = ptr_ref->next;
	}
	return (1);
}

int	check_input(char **input)
{
	int	j;
	int	nb;

	nb = 0;
	j = 0;
	while (input[j] != NULL)
		check_char(input, j++);
	return (1);
}

void	check_char(char **input, int j)
{
	int	i;
	int	neg;
	int	nb_word;

	i = 0;
	neg = 0;
	nb_word = count_word(*input, ' ');
	if (nb_word < 1)
		exit(0);
	while (i < (int)ft_strlen(input[j]))
	{
		if ((!ft_isdigit(input[j][i]) \
				&& !(' ' == input[j][i]) && !(input[j][i] == '-') \
				&& !(input[j][i] == '\t')))
			yo_its_wrong("Les entrées doivent être des chiffres.\n");
		if (input[j][i] == '-')
			neg++;
		if (nb_word < neg || (!ft_isdigit(input[j][i + 1]) \
		&& input[j][i] == '-'))
			yo_its_wrong("Trop de '-'\n");
		i++;
	}
}
