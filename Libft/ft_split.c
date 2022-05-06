/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:14:03 by slavoie           #+#    #+#             */
/*   Updated: 2022/03/21 00:27:35 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* compte le nombre de mot de la chaine 

    args:
            str: la chaine 
            sep: le séparateur entre les mots

    return: 
            nb_word = nombre de mots 
*/
int	count_word(const char *str, char sep)
{
	int	nb_word;

	nb_word = 0;
	while (*str)
	{
		if (*str == sep)
			nb_word += 1;
		str++;
	}
	nb_word += 1;
	return (nb_word);
}
/*
    sépare un mot du reste la chaine 

    args:
            str: la chaine à séparer
            sep: le caractère de séparation
    return:
            ptr: le mot séparer

*/

char	*init_str(const char *str, char sep)
{
	int		i;
	char	*ptr;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	ptr = (char *) malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, str, i + 1);
	return (ptr);
}

/*
    sépare chaque mot en les plaçant dans un tableau 
	en se basant sur le caractère séparateur

    args:  
            str: la chaine à séparer en mot
            sep: le caractère séparateur

    return:
            tab =. un tableau contenant tous les mots de la chaine en argument 

*/
char	**ft_split(const char *str, char sep)
{
	int		i;
	char	**tab;
	int		word;

	word = count_word(str, sep);
	tab = (char **)malloc(sizeof(char *) * (word + 1));
	if (!tab || !str)
		return (NULL);
	i = 0;
	while (i < word)
	{
		while (*str == sep)
			str++;
		tab[i] = init_str(str, sep);
		if (!tab[i])
		{
			while (i < 0)
				free(tab[i--]);
			free(tab);
			return (NULL);
		}
		str += ft_strlen(tab[i++]);
	}
	tab[i] = 0;
	return (tab);
}
