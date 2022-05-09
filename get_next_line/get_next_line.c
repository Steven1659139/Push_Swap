/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <slavoie@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:46:39 by slavoie           #+#    #+#             */
/*   Updated: 2022/05/09 16:10:32 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

static void	ft_read(int fd, char *buf, char **statique)
{
	int nb_bytes;
	char	*tmp;
	if(!*statique || !ft_strchr(*statique, '\n'))
	{	
		nb_bytes = read(fd, buf, BUFFER_SIZE);
		while (nb_bytes > 0)
		{
			buf[nb_bytes] = 0;
			if (!*statique)
				*statique = ft_substr(buf, 0, nb_bytes);
			else
			{
				tmp = *statique;
				*statique = ft_strjoin(*statique, buf);
				free(tmp);
			}
			if (ft_strchr(buf, '\n'))
				break ;
			nb_bytes = read(fd, buf, BUFFER_SIZE);
		}
	}
}

static char	*ft_retline(char **statique)
{
	int	len;
	int	until_n;
	char	*ret;
	char 	*tmp;

	if (!*statique)
	{
		return (NULL);
	}
	len = ft_strlen(*statique);
	if (!ft_strchr(*statique, '\n'))
	{
		if (len == 0)
			return (NULL);
		ret = ft_substr(*statique, 0, len);
		free(*statique);
		*statique = 0;
		return (ret);
	}
	until_n = ft_strlen(ft_strchr(*statique, '\n'));
	ret = ft_substr(*statique, 0, len - until_n + 1);
	tmp = *statique;
	*statique = ft_substr(ft_strchr(*statique, '\n'), 1, until_n);
	free(tmp);
	return (ret);
}

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	static char	*statique;

	if (BUFFER_SIZE < 1 || fd == -1 || read(fd,buf,0) == -1)
	{
		return(0);
	}
	ft_read(fd, buf, &statique);
	return (ft_retline(&statique));	
}

/*int main()
{
    ssize_t fd;
    char    *test;
        fd = open("text.txt", O_RDONLY);
    do
    {
        test = get_next_line(fd);
        puts("-------------main----------");
        printf("|%s|\n", test);
        if (test)
            free(test);
    } while (test != NULL);
    if (test)
        free(test);
    close(fd);
    return (0);
}*/ 

