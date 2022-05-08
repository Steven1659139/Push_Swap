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

	if (argc > 1 && check_input(++argv))
	{
		{
			if (argc == 2)
				convert(container, *argv);
			else
				convert_sep(container, argv);
			while (1)
			{
				move = read_move(0);
				if (!move)
					break ;
				put_move(container, move);
				free(move);
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
