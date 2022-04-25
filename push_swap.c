/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:25:04 by slavoie           #+#    #+#             */
/*   Updated: 2022/04/20 15:08:33 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_lstprint(t_dlist *first)
{
	t_dlist *ptr;

	ptr = first;
	if (!first)
		return ;
	while(ptr->next != first)
	{	
		printf("%d -> ", ptr->content);
		ptr = ptr->next;
	}
	printf("%d -> \n", ptr->content);
	ptr = first;
	while(ptr->next != first)
	{	
		printf("%d -> ", ptr->index);
		ptr = ptr->next;
	}
	printf("%d\n", ptr->index);
}

void	convert(t_package_deal *container, char *argv)
{
	char **tab;
	t_dlist *stack_a;
	long long inter;
	int i;

	i = 0;
	tab = ft_split(argv, ' ');

	while (tab[i])
	{
		//printf("tab = %s\n", tab[i]);
		inter = ft_atoi(tab[i]);
		
		if (!int_checker(inter))
			yo_its_wrong("Les nombres doivent pouvoir être contenu dans un int.");
		lstadd(&stack_a, lstnew_dbl(inter));
		container->size_a += 1;
		i++;
	}
	free(tab);
	
	if (!twin_checker(&stack_a))
		yo_its_wrong("Il ne peut pas y avoir de doublon.");
	
	container->stack_a_head = stack_a;
	container->size_max = container->size_a;

	set_index(container);
	update_position(container);

	sort500(container);
}

void	convert_sep(t_package_deal *container, char **argv)
{
	int i;
	long long inter;
	t_dlist *stack_a;

	i = 0;
	inter = 0;
	while (argv[i] != NULL)
	{
		inter = ft_atoi(argv[i]);
		if (!int_checker(inter))
			yo_its_wrong("Les nombres doivent pouvoir être contenu dans un int.");
		lstadd(&stack_a, lstnew_dbl(inter));
		i++;
		container->size_a += 1;
	}
	if (!twin_checker(&stack_a))
		yo_its_wrong("Il ne peut pas y avoir de doublon.");
	container->stack_a_head = stack_a;
	container->size_max = container->size_a;

	set_index(container);
	update_position(container);
	
}

int main(int argc, char **argv)
{
	t_package_deal		*container;

	container = malloc(sizeof(t_package_deal));
	argv++;
	if (argc > 1 && check_input(argv))
	{
		{
			if (argc == 2)
			{
				convert(container, *argv);
				algo(container);
			}
			else
			{
				convert_sep(container, argv);
				algo(container);
			}
		}
	}
	else
		ft_putstr_fd(RED"Error\n", 2);

	ft_lstprint(container->stack_a_head);
}
