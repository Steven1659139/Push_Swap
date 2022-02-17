/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <slavoie@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:53:15 by slavoie           #+#    #+#             */
/*   Updated: 2021/05/27 14:51:33 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*rtn;
	unsigned int	index;

	index = 0;
	rtn = (char *)malloc (sizeof (char) * (len + 1));
	if (!(s && rtn))
		return (NULL);
	while (index < len && start < ft_strlen(s))
		rtn[index++] = s[start++];
	rtn[index] = 0;
	return (rtn);
}
