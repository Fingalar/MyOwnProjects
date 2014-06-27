/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 18:30:44 by jburet            #+#    #+#             */
/*   Updated: 2014/03/27 18:30:51 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/config.h"
#include "../includes/ft_env.h"

void		create_file_config(t_sh *sh)
{
	int		fd;
	char	*path;

	path = ft_strjoin(ft_get_var(sh, "HOME"), "/");
	path = ft_strjoin(path, NAME_CONFIG);
	if ((fd = open(path, O_RDWR | O_CREAT | O_APPEND, 0755)) == -1)
		return ;
	free(path);
	close(fd);
}

char		*get_part_alias(char *line)
{
	char	**split;

	split = ft_strsplit(line, ' ');
	if (!split[1])
	{
		free(split[0]);
		free(split);
		return (NULL);
	}
	split = ft_strsplit(split[1], '=');
	if (!split[1])
	{
		free(split[0]);
		free(split);
		return (NULL);
	}
	free(split[1]);
	return (split[0]);
}

char		*is_alias(char *cmd, char *line)
{
	char	**split;
	char	*ret;

	line = ft_strtrim(line);
	if (!ft_strncmp(line, "alias", ft_strlen("alias")))
	{
		split = ft_strsplit(line, '"');
		if (!split[1])
		{
			free(split);
			return (NULL);
		}
		ret = ft_strdup(split[1]);
		if (!ft_strcmp(get_part_alias(line), cmd))
		{
			free(split);
			return (ret);
		}
	}
	return (NULL);
}

char		*alias(t_sh *sh, char *line)
{
	int		fd;
	char	*path;
	char	*alias;
	char	*gnl;

	if (!line[0])
		return (line);
	path = ft_strjoin(ft_get_var(sh, "HOME"), "/");
	path = ft_strjoin(path, NAME_CONFIG);
	if ((fd = open(path, O_RDWR | O_CREAT | O_APPEND, 0755)) == -1)
		return (NULL);
	while (get_next_line(fd, &gnl) != 0)
	{
		if ((alias = is_alias(line, gnl)) != NULL)
		{
			free(line);
			free(path);
			free(gnl);
			return (alias);
		}
	}
	free(path);
	return (line);
}
