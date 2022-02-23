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

typedef struct s_dlist
{
	int			content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

#include "Libft/libft.h"
#include <stdio.h>

t_dlist	*lstnew_dbl(int content);
t_dlist	*lstlast(t_dlist **first, t_dlist *lst);
void	lst_addback(t_dlist **alst, t_dlist *new);


#endif
