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

t_dlist	*convert(t_package_deal *container, char *argv)
{
	char **tab;
	t_dlist *stack_a;
	long long inter;
	int i;

	i = 0;
	tab = ft_split(argv, ' ');
	//inter = ft_atoi(tab[i]);
	/*if (!int_checker(inter))
	{
		ft_putstr_fd(RED"Error\n", 2);
		return (0);
	}*/
	
	//stack_a = lstnew_dbl(inter);
	while (tab[i])
	{
		//printf("tab = %s\n", tab[i]);
		inter = ft_atoi(tab[i]);
		
		if (!int_checker(inter))
		{
			ft_putstr_fd(RED"Error\n", 2);
			return (0);
		}
		lstadd(&stack_a, lstnew_dbl(inter));
		container->size_a += 1;
		printf("size A = %d\n", container->size_a);
		//printf("inter = %lld\n", inter);
		i++;
	}
	free(tab);
	
	if (!twin_checker(&stack_a))
	{
		ft_putstr_fd(RED"Error\n", 2);
		return (0);
	}
	
	container->stack_a_head = stack_a;
	container->size_max = container->size_a;
	set_index(container);

	t_dlist *min;
	t_dlist *max;

	min = find_min(container, 'A');
	printf("pos_min = %d\n", container->find_pos);
	max = find_max(container, 'A');
	printf("pos_max = %d\n", container->find_pos);
	printf("max = %d\n", max->content);
	printf("min = %d\n", min->content);
	//ft_lstprint(container->stack_a_head);

	//sort3(container);
	sort5(container);

	printf("Nombre d'action = %d\n", container->nb_move);

	// printf("Stack A\n");
	
	// printf("Stack B\n");

	printf("Stack A\n");
	//ft_lstprint(container->stack_a_head);
	printf("Stack B\n");
	//ft_lstprint(container->stack_b_head);


	// pb(container);
	// printf("pb\n");
	// printf("Stack A\n");
	
	// printf("Stack B\n");
	// ft_lstprint(container->stack_b_head);

	// pb(container);
	// printf("pb\n");


	// rotate(container, 'A');
	// printf("ra\n");
	// printf("Stack A\n");
	// ft_lstprint(container->stack_a_head);
	// printf("Stack B\n");
	// ft_lstprint(container->stack_b_head);

	// rotate(container, 'B');
	// printf("rb\n");
	// printf("Stack A\n");
	// ft_lstprint(container->stack_a_head);
	// printf("Stack B\n");
	// ft_lstprint(container->stack_b_head);

	// rotate(container, 'C');
	// printf("rr\n");
	// printf("Stack A\n");
	// ft_lstprint(container->stack_a_head);
	// printf("Stack B\n");
	// ft_lstprint(container->stack_b_head);

	// sa(container);
	// printf("sa\n");
	// printf("Stack A\n");
	// ft_lstprint(container->stack_a_head);
	// printf("Stack B\n");
	// ft_lstprint(container->stack_b_head);

	// sb(container);
	// printf("sb\n");
	// printf("Stack A\n");
	// ft_lstprint(container->stack_a_head);
	// printf("Stack B\n");
	// ft_lstprint(container->stack_b_head);

	// ss(container);
	// printf("ss\n");
	// printf("Stack A\n");
	// ft_lstprint(container->stack_a_head);
	// printf("Stack B\n");
	// ft_lstprint(container->stack_b_head);

	// reverse_rotate(container, 'A');
	// printf("rra\n");
	// printf("Stack A\n");
	// ft_lstprint(container->stack_a_head);
	// printf("Stack B\n");
	// ft_lstprint(container->stack_b_head);

	// reverse_rotate(container, 'B');
	// printf("rrb\n");
	// printf("Stack A\n");
	// ft_lstprint(container->stack_a_head);
	// printf("Stack B\n");
	// ft_lstprint(container->stack_b_head);

	// reverse_rotate(container, 'C');
	// printf("rrr\n");
	// printf("Stack A\n");
	// ft_lstprint(container->stack_a_head);
	// printf("Stack B\n");
	// ft_lstprint(container->stack_b_head);

	return (stack_a);
}

t_dlist *convert_sep(t_package_deal *container, char **argv)
{
	int i;
	long long inter;
	t_dlist *stack_a;

	i = 0;
	inter = 0;
	//inter = ft_atoi(argv[i]);
	if (!int_checker(inter))
	{
		ft_putstr_fd(RED"Error\n", 2);
		return (0);
	}
	//stack_a = lstnew_dbl(inter);
	while (argv[i] != NULL)
	{
		inter = ft_atoi(argv[i]);
		
		if (!int_checker(inter))
		{
			ft_putstr_fd(RED"Error\n", 2);
			return (0);
		}
		lstadd(&stack_a, lstnew_dbl(inter));
		i++;
	}
	if (!twin_checker(&stack_a))
	{
		ft_putstr_fd(RED"Error\n", 2);
		return (0);
	}
	container->stack_a_head = stack_a;
	ft_lstprint(container->stack_a_head);
	return (stack_a);
}

void	init_package(t_package_deal *container)
{
	container->size_a = 0;
	container->size_b = 0;
	container->stack_a_head = NULL;
	container->stack_b_head = NULL;
}

int main(int argc, char **argv)
{
	t_package_deal		*container;

	container = malloc(sizeof(t_package_deal));
	//init_package(container);

	
	argv++;
	//container.size_a = 0;
	//printf("Output_check = %d\n", check_input(argv));
	if (argc > 1 && check_input(argv))
	{
		{
			if (argc == 2)
			{
				//printf("%s", "Arg == 2\n");
				convert(container, *argv);
			}
			else
			{
				//printf("%s", "Arg + 2\n");
				convert_sep(container, argv);
			}
		}
	}
	else
		ft_putstr_fd(RED"Error\n", 2);
}