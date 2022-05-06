/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:09:03 by slavoie           #+#    #+#             */
/*   Updated: 2022/05/05 21:09:05 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "Push_swap.h"
# include "./get_next_line/get_next_line.h"

void	check_move(t_stacks *container, char **argv, int argc);
char	*read_move(int fd);

#endif
