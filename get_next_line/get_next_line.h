/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <slavoie@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:13:13 by slavoie           #+#    #+#             */
/*   Updated: 2021/09/06 13:54:19 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define FD_SIZE 4096

# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);




#endif
