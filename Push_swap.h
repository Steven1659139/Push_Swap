/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:55:22 by slavoie           #+#    #+#             */
/*   Updated: 2022/02/16 17:56:20 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* 
- len
- position, set_first set_last
*/
#include "Libft/libft.h"
#include <stdio.h>

typedef struct s_dlist
{
	int			content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef struct s_stacks
{
	t_dlist	*a;
	t_dlist	*b;
	int		min_value;
	int		max_value;
}				t_stack;

typedef struct s_package_deal
{
	t_dlist	*stack_a_head;
	t_dlist *stack_b_head;
	t_dlist	*temp;
	int		size_a;
	int		size_b;
}				t_package_deal;



// Parsing
int	int_checker(long long nb);
int twin_checker(t_dlist **lst);
int	check_input(char **input);

t_dlist	*lstnew_dbl(int content);
t_dlist	*lstlast(t_dlist **first, t_dlist *lst);
void	lst_addback(t_dlist **alst, t_dlist *new);
void    lstadd(t_dlist **first, t_dlist *new);
size_t  ft_lstlen(t_dlist **first);
int ft_countword(char **tab);
//move

void    rotate(t_package_deal *container, char stack);
void    pb(t_package_deal *container, char stack);

#endif
