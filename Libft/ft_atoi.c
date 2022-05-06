/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <slavoie@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:07:32 by slavoie           #+#    #+#             */
/*   Updated: 2021/06/07 16:46:01 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	long long	n;
	int			negation;

	n = 0;
	negation = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (n >= 1)
			return (0);
		if (*str == '-')
			negation++;
		n++;
		str++;
	}
	n = 0;
	if (*str == '+' && negation > 0)
		return (n);
	while (*str >= '0' && *str <= '9')
		n = n * 10 + *str++ - '0';
	if (negation)
		n *= -1;
	return (n);
}
