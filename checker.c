/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:11:32 by slavoie           #+#    #+#             */
/*   Updated: 2022/05/05 21:14:51 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "Push_swap.h"

void	ft_print_list(t_stacks *stack)
{
	int i;
	t_dlist *stack_a;
	t_dlist *stack_b;

	i = 0;

	stack_a = stack->a_head;
	stack_b = stack->b_head;

	printf("A	|	B\n-----------------\n");
	while (i < stack->size_max)
	{
		if (stack_a && i < stack->size_a)
		{
			printf("%d	|	", stack_a->content);
			stack_a = stack_a->next;
		}
		else
			printf("	|	");
		if (stack_b && i < stack->size_b)
		{
			printf("%d\n", stack_b->content);
			stack_b = stack_b->next;
		}
		else
			printf("\n");
		i++;
	}
	printf("Nombre de coup: %d\n", stack->nb_move);
}


char	*read_move(int fd)
{
	char	*line;
	char	*move;

	line = get_next_line(fd);
	if (!line)
		return (0);
	move = ft_substr(line, 0, ft_strlen(line) - 1);
	free(line);
	return (move);
}

void	check_move(t_stacks *container, char **argv, int argc)
{
	char	*move;

	if (argc == 1)
		exit(0);
	if (argc > 1 && check_input(++argv))
	{
		{
			if (argc == 2)
				convert(container, *argv);
			else
				convert_sep(container, argv);

			ft_print_list(container);
			while (1)
			{
				move = read_move(0);
				if (!move)
					break ;
				put_move(container, move, 0);
				free(move);
				ft_print_list(container);
			}
			free(move);
		}
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*container;

	container = malloc(sizeof(t_stacks));
	check_move(container, argv, argc);
	if (check_sort(container, container->size_max))
		ft_putstr_fd(GREEN"OK\n", 1);
	else
		ft_putstr_fd(RED"KO\n", 1);
}
