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
	struct s_list_dbl	*next;
	struct s_list_dbl	*prev;
}					t_list_dbl;

#include "Libft/libft.h"

t_list_dbl	*lstnew_dbl(int content);
t_list_dbl	*lstlast(t_list_dbl *lst);
void	lst_addback(t_list_dbl **alst, t_list_dbl *new);


#endif
