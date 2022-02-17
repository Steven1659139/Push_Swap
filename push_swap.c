/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:25:04 by slavoie           #+#    #+#             */
/*   Updated: 2022/02/14 14:02:53 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"
#include <stdio.h>

void	ft_lstprint(t_intlist **first)
{
	t_intlist *ptr;

	ptr = *first;
	while(ptr->next != NULL)
	{	
		printf("%d\n", ptr->content);
		ptr = ptr->next;
	}
	printf("%d\n", ptr->content);
}

t_intlist	*convert(char *input)
{
	char **tab;
	t_intlist *int_list;
	int inter;
	int i;

	i = 0;
	tab = ft_split(input, ' ');
	inter = ft_atoi(tab[i]);
	int_list = lstnew_int(inter);

	//printf("%d\n", (int)int_list->next->content);
	printf("%d\n", (int)int_list->content);
	while (tab[++i] != NULL)
	{
		inter = ft_atoi(tab[i]);
		printf("%d\n", inter);
		lst_addback(&int_list, lstnew_int(inter));
	}
	ft_lstprint(&int_list);
	return (int_list);
}

t_intlist *convert_sep(char **input)
{
	int i;
	int inter;


	t_intlist *int_list;

	i = 0;

	inter = ft_atoi(input[i]);
	int_list = lstnew_int(inter);

	while (input[++i] != NULL)
	{
		inter = ft_atoi(input[i]);
		lst_addback(&int_list, lstnew_int(inter));
		//printf("%s\n", input[i]);
	}
	ft_lstprint(&int_list);
	return (int_list);


}

int	check_input(char *input)
{
	int i;

	i = 0;
	while (i < ft_strlen(input))
	{
		if (ft_isalpha(input[i++]))
			return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		argv++;
		if (argc == 2 && (check_input(*argv)))
		{
			//ft_putstr_fd(GREEN"Input OK",1);
			convert(*argv);
		}
		else
			convert_sep(argv);
	}
	else
		ft_putstr_fd(RED"Error\n", 2);
}
