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

void	ft_lstprint(t_dlist **first)
{
	t_dlist *ptr;

	ptr = *first;
	while(ptr->next != NULL)
	{	
		printf("%d -> ", ptr->content);
		ptr = ptr->next;
	}
	printf("%d -> \n", ptr->content);
	/*while(ptr->prev != *first)
	{
		
		printf("%d -> ", ptr->content);
		ptr = ptr->prev;
	}
	printf("%d -> ", ptr->content);
	ptr = ptr->prev;
	printf("%d -> ", ptr->content);*/
}

t_dlist	*convert(char *input)
{
	char **tab;
	t_dlist *int_list;
	long long inter;
	int i;

	i = 0;
	tab = ft_split(input, ' ');
	inter = ft_atoi(tab[i]);
	if (!int_checker(inter))
	{
		ft_putstr_fd(RED"Error\n", 2);
		return (0);
	}
	int_list = lstnew_dbl(inter);
	//i++;

	//printf("%d\n", (int)int_list->next->content);
	//printf("%d\n", (int)int_list->content);
	while (tab[++i] != NULL)
	{
		inter = ft_atoi(tab[i]);
		if (!int_checker(inter))
		{
			ft_putstr_fd(RED"Error\n", 2);
			return (0);
		}
		//printf("%d\n", inter);
		lst_addback(&int_list, lstnew_dbl(inter));
		//i++;
	}
	free(tab);
	//ft_lstprint(&int_list);
	//ra(&int_list);
	if (!twin_checker(&int_list))
	{
		ft_putstr_fd(RED"Error\n", 2);
		return (0);
	}
	ft_lstprint(&int_list);
	return (int_list);
}

t_dlist *convert_sep(char **input)
{
	int i;
	long long inter;


	t_dlist *int_list;

	i = 0;

	inter = ft_atoi(input[i]);
	if (!int_checker(inter))
	{
		ft_putstr_fd(RED"Error\n", 2);
		return (0);
	}
	int_list = lstnew_dbl(inter);


	while (input[++i] != NULL)
	{
		inter = ft_atoi(input[i]);
		//printf("inter = %lld", inter);
		if (!int_checker(inter))
		{
			ft_putstr_fd(RED"Error\n", 2);
			return (0);
		}
		lst_addback(&int_list, lstnew_dbl(inter));
		//printf("%s\n", input[i]);
	}
	if (!twin_checker(&int_list))
	{
		ft_putstr_fd(RED"Error\n", 2);
		return (0);
	}
	ft_lstprint(&int_list);
	return (int_list);


}


int main(int argc, char **argv)
{
	argv++;
	//printf("Output_check = %d\n", check_input(argv));
	if (argc > 1 && check_input(argv))
	{
		{
			if (argc == 2)
			{
				//printf("%s", "Arg == 2\n");
				convert(*argv);
			}
			else
			{
				//printf("%s", "Arg + 2\n");
				convert_sep(argv);
			}
		}
	}
	else
		ft_putstr_fd(RED"Error\n", 2);
}