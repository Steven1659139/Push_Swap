/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <slavoie@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:18:35 by slavoie           #+#    #+#             */
/*   Updated: 2021/06/09 14:29:14 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{	
	char	*ptr_need;
	char	*ptr_hays;
	size_t	len_need;

	len_need = ft_strlen(need);
	if (!*need)
		return ((char *)hay);
	if (!ft_strlen(hay) || len < len_need)
		return (NULL);
	len -= --len_need;
	while (len-- && *hay)
	{
		ptr_need = (char *) need;
		ptr_hays = (char *) hay;
		while (*ptr_hays && *ptr_need == *ptr_hays)
		{
			ptr_need++;
			ptr_hays++;
		}
		if (*ptr_need == 0)
			return ((char *) hay);
		hay++;
	}
	return (NULL);
}
