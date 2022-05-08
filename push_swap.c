/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:25:04 by slavoie           #+#    #+#             */
/*   Updated: 2022/05/05 21:05:38 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks		*container;

	container = malloc(sizeof(t_stacks));
	if (!*argv)
		exit(0);
	argv++;
	if (argc > 1 && check_input(argv))
	{
		{
			if (argc == 2)
			{
				convert(container, *argv);
				//ft_lstprint(container->a_head);
				algo(container);
			}
			else
			{
				convert_sep(container, argv);
				//ft_lstprint(container->a_head);
				algo(container);
			}
			//ft_lstprint(container->a_head);
		}
	}
	ft_lstclear(&(container->a_head), &free);
	free(container);
}
