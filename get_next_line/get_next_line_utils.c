/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <slavoie@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:18:09 by slavoie           #+#    #+#             */
/*   Updated: 2021/09/01 17:36:11 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

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

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		if (*s == 0)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

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
