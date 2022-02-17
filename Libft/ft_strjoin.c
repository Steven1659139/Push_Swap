/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <slavoie@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:00:58 by slavoie           #+#    #+#             */
/*   Updated: 2021/06/01 14:58:14 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rtn;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	rtn = malloc(len);
	if (!rtn)
		return (NULL);
	ft_strlcpy(rtn, s1, len);
	ft_strlcat(rtn, s2, len);
	return (rtn);
}
