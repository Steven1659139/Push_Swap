/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <slavoie@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:05:38 by slavoie           #+#    #+#             */
/*   Updated: 2021/06/09 15:47:33 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	index;

	index = 0;
	while (*dst && index < dst_size)
	{
		index++;
		dst++;
	}
	while (*src && (index + 1) < dst_size)
	{
		*dst++ = *src++;
		index++;
	}
	if (index < dst_size)
		*dst = 0;
	while (*src++)
		index++;
	return (index);
}
