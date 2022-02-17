/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <slavoie@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:06:08 by slavoie           #+#    #+#             */
/*   Updated: 2021/06/09 15:43:57 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*rtn;

	rtn = NULL;
	while (1)
	{
		if (*s == (unsigned char)c)
			rtn = (char *)s;
		if (*s == 0)
			break ;
		s++;
	}
	return (rtn);
}
