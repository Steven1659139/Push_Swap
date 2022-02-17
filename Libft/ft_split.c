/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <slavoie@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 11:37:31 by slavoie           #+#    #+#             */
/*   Updated: 2021/06/09 15:53:34 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, char sep)
{
	int	nb_word;
	int	pass;

	nb_word = 0;
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str == sep)
			pass = 0;
		else if (pass == 0)
		{
			pass = 1;
			nb_word++;
		}
		str++;
	}
	return (nb_word);
}

static int	freee(char **str, int size)
{
	while (size--)
		free(str[size]);
	return (-1);
}

static void	write_word(char *dst, const char *src, char sep)
{
	int	index;

	index = 0;
	while (!(src[index] == sep || src[index] == '\0'))
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
}

static int	assign_word(char **tab, const char *str, char sep)
{
	int		index;
	int		len_w;
	int		word;

	word = 0;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == sep || str[index] == '\0')
			index++;
		else
		{
			len_w = 0;
			while (!(str[index + len_w] == sep || str[index + len_w] == '\0'))
				len_w++;
			tab[word] = (char *)malloc(sizeof(char) * (len_w + 1));
			if (!tab[word])
				return (freee(tab, word - 1));
			write_word(tab[word], str + index, sep);
			index += len_w;
			word++;
		}
	}
	return (0);
}

char	**ft_split(const char *str, char sep)
{
	char	**tab;
	int		words;

	words = ft_count_words(str, sep);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	tab[words] = 0;
	if (assign_word(tab, str, sep) == -1)
		return (NULL);
	return (tab);
}
