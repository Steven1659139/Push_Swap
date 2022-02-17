/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <slavoie@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:12:49 by slavoie           #+#    #+#             */
/*   Updated: 2021/06/09 15:46:41 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	index;

	index = 0;
	if (!(dst || src))
		return (0);
	while (src[index] && (index + 1) < dst_size)
	{	
		dst[index] = src[index];
		index++;
	}
	if (dst_size != 0)
		dst[index] = 0;
	while (src[index])
		index++;
	return (index);
}
