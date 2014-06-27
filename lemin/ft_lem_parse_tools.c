/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_parse_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 06:30:05 by tmertz            #+#    #+#             */
/*   Updated: 2014/02/23 07:00:21 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/libft.h"
#include <stdlib.h>

void		ft_add_to_matrix(t_map *map, char **split)
{
	int		i;
	int		j;

	i = ft_get_index(split[0], map->rooms);
	j = ft_get_index(split[1], map->rooms);
	map->adj_matrix[i][j] = 1;
	map->adj_matrix[j][i] = 1;
}

int			ft_command_check_and_add(t_map *map, char *line)
{
	if (!ft_strcmp(line, "##start"))
	{
		if (map->start == -1)
			map->start = map->rooms->size;
		else
			return (0);
	}
	else if (!ft_strcmp(line, "##end"))
	{
		if (map->end == -1)
			map->end = map->rooms->size;
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int			ft_iscommand(char *str)
{
	char	**split;

	split = ft_strsplit(str, ' ');
	if (ft_tablen((void **)split) != 1)
	{
		free(split);
		return (0);
	}
	if (ft_strlen(str) >= 2 && str[0] == '#' && str[1] == '#')
	{
		free(split);
		return (1);
	}
	free(split);
	return (0);
}

int			ft_iscomment(char *str)
{
	if (ft_strlen(str) > 1 && str[0] == '#' && str[1] != '#')
		return (1);
	return (0);
}

int			ft_isliaison(char *str)
{
	char	**split;

	split = ft_strsplit(str, '-');
	if (ft_tablen((void **)split) == 2)
	{
		free(split);
		return (1);
	}
	free(split);
	return (0);
}
