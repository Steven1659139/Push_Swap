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

typedef struct s_intlist
{
	int			content;
	struct s_intlist	*next;
}					t_intlist;

#include "Libft/libft.h"

t_intlist	*lstnew_int(int content);
t_intlist	*lstlast(t_intlist *lst);
void	lst_addback(t_intlist **alst, t_intlist *new);


#endif
