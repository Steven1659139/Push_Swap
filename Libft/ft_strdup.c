/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <slavoie@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:49:41 by slavoie           #+#    #+#             */
/*   Updated: 2021/06/09 15:51:59 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*rtn;
	int		len;
	int		index;

	index = 0;
	len = ft_strlen(s1);
	rtn = malloc(len + 1);
	if (!rtn)
		return (0);
	while (len--)
		rtn[index++] = *s1++;
	rtn[index] = 0;
	return (rtn);
}
