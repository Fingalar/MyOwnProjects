/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:34:45 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/11 15:51:42 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int				get_next_line(int const fd, char **line)
{
	static char	*mem = NULL;
	char		*buffer;
	int			status_read;

	status_read = BUFF_SIZE;
	if (status_read < 1)
		return (-1);
	while (!(end_of_line(mem)) && status_read == BUFF_SIZE)
	{
		buffer = (char*)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
		if ((status_read = read(fd, buffer, BUFF_SIZE)) == -1)
			return (-1);
		buffer[status_read] = '\0';
		mem = ft_strjoin_for_gnl(mem, buffer);
		free(buffer);
	}
	*line = ft_strdup(mem);
	mem = ft_strsub_for_gnl(mem, ft_strlen(*line) + 1);
	if (status_read != BUFF_SIZE && ft_strlen(*line) == 0
		&& ft_strlen(mem) == 0)
		return (0);
	return (1);
}

int				end_of_line(char *str)
{
	int			i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			return (1);
		}
		i++;
	}
	return (0);
}

char*		ft_strjoin_for_gnl(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	if (s1 == NULL && s2 == NULL
		&& (join = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		join[0] = '\0';
	else if (s1 == NULL || s2 == NULL)
		join = (s1 == NULL ? ft_strdup(s2) : ft_strdup(s1));
	else if ((join = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
	{
		i = 0;
		j = 0;
		while (s1[i] != '\0')
		{
			join[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			join[i++] = s2[j++];
		}
		join[i] = '\0';
	}
	free(s1);
	return (join);
}

char*		ft_strsub_for_gnl(char *s, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	if ((sub = (char*)malloc(sizeof(char) * ft_strlen(s) - len + 1))
		&& s != NULL)
	{
		i = 0;
		j = 0;
		while (i < len)
			i++;
		while (s[i] != '\0')
			sub[j++] = s[i++];
		sub[j] = '\0';
		free(s);
		return (sub);
	}
	return (NULL);
}
