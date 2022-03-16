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
	if (!*first)
		return ;
	while(ptr->next != *first)
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

t_dlist	*convert(t_package_deal **container, char *input)
{
	char **tab;
	t_dlist *stack_a;
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
	//printf("inter = %lld\n", inter);
	stack_a = lstnew_dbl(inter);
	while (tab[++i] != NULL)
	{
		inter = ft_atoi(tab[i]);
		if (!int_checker(inter))
		{
			ft_putstr_fd(RED"Error\n", 2);
			return (0);
		}
		lstadd(&stack_a, lstnew_dbl(inter));
		//printf("inter = %lld\n", inter);
	}
	free(tab);
	if (!twin_checker(&stack_a))
	{
		ft_putstr_fd(RED"Error\n", 2);
		return (0);
	}
	//ra(&stack_a);
	ft_lstprint(&stack_a);
	return (stack_a);
}

t_dlist *convert_sep(t_package_deal **container, char **input)
{
	int i;
	long long inter;
	t_dlist *stack_a;

	i = 0;
	inter = ft_atoi(input[i]);
	if (!int_checker(inter))
	{
		ft_putstr_fd(RED"Error\n", 2);
		return (0);
	}
	stack_a = lstnew_dbl(inter);
	while (input[++i] != NULL)
	{
		inter = ft_atoi(input[i]);
		if (!int_checker(inter))
		{
			ft_putstr_fd(RED"Error\n", 2);
			return (0);
		}
		lstadd(&stack_a, lstnew_dbl(inter));
	}
	if (!twin_checker(&stack_a))
	{
		ft_putstr_fd(RED"Error\n", 2);
		return (0);
	}
	ft_lstprint(&stack_a);
	return (stack_a);
}

/*void	init_package(t_package_deal **container)
{
	(*container)->size_a = 0;
	(*container)->size_b = 0;
}*/

int main(int argc, char **argv)
{
	t_package_deal		*container;

	//init_package(&container);

	
	argv++;
	//printf("Output_check = %d\n", check_input(argv));
	if (argc > 1 && check_input(argv))
	{
		{
			if (argc == 2)
			{
				//printf("%s", "Arg == 2\n");
				convert(&container, *argv);
			}
			else
			{
				//printf("%s", "Arg + 2\n");
				convert_sep(&container, argv);
			}
		}
	}
	else
		ft_putstr_fd(RED"Error\n", 2);
}