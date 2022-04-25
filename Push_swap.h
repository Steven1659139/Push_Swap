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
	int			index;
	int			position;
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
	int		pos1;
	int		pos2;
	int		size_a;
	int		size_b;
	int		size_max;
	t_dlist	*min_a;
	t_dlist	*max_a;
	t_dlist *min_b;
	t_dlist	*max_b;
	int		find_pos;
	int		chunk_size;
	int		max_chunk;
	int		min_chunk;
	int		nb_move;

}				t_package_deal;



// Parsing
int	int_checker(long long nb);
int twin_checker(t_dlist **lst);
int	check_input(char **input);
void	ft_lstprint(t_dlist *first);

t_dlist	*lstnew_dbl(int content);
t_dlist	*lstlast(t_dlist **first, t_dlist *lst);
void	lst_addback(t_dlist **alst, t_dlist *new);
void    lstadd(t_dlist **first, t_dlist *new);
size_t  ft_lstlen(t_dlist **first);
int ft_countword(char **tab);
//move

void    rotate(t_package_deal *container, char stack);
void    pb(t_package_deal *container);
void    pa(t_package_deal *container);
void    sa(t_package_deal *container);
void    sb(t_package_deal *container);
void    ss(t_package_deal *container);
void    reverse_rotate(t_package_deal *container, char stack);

//sort

int 	check_sort(t_package_deal *container, int nb);
void    set_index(t_package_deal *container);
t_dlist *find_min(t_package_deal *list, char stack);
t_dlist *find_max(t_package_deal *list, char stack);
t_dlist *find_node(t_package_deal *list, int min, int max, char stack);
t_dlist *find_node_bottom(t_package_deal *list, int min, int max, char stack);
void    find_pos(t_package_deal *container, t_dlist *node, char stack);
int 	min_or_max(t_package_deal *container, t_dlist *node, char stack);
void    on_top(t_package_deal *container, t_dlist *node, char stack);
void    sort3(t_package_deal *container);
void    sort5(t_package_deal *container);
void    sort100(t_package_deal *container);
void    sort500(t_package_deal *container);

void    update_stack_B(t_package_deal *container);
void    update_stack_A(t_package_deal *container);
void    update_position(t_package_deal *container);

int		size_chunk(t_package_deal *container);
int 	move_chunk(t_package_deal *container, int count, int flag);
void    chunker(t_package_deal *container);

void    filter_swap(t_package_deal *container, char c);
void	filter_push(t_package_deal *container, char c);

void 	put_move(t_package_deal *container, char *move);
int		do_move(t_package_deal *container, char *str, int nb, int prev);

void algo(t_package_deal *container);



#endif
