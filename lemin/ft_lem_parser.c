/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 17:14:20 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/21 17:03:51 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/libft.h"
#include <stdlib.h>

t_map		*ft_lemin_parser(t_map *map)
{
	int		error;

	error = 0;
	map = ft_init_map(map);
	error = ft_read_instructions(map);
	if (error < 0 || map->adj_matrix == NULL)
	{
		ft_putendl_fd("ERROR", 2);
		return (NULL);
	}
	return (map);
}

int			ft_read_instructions(t_map *map)
{
	char	*line;

	while (get_next_line(0, &line) && line != NULL)
	{
		ft_strtrim(line);
		ft_list_push(map->lines, ft_list_new(line, ft_strlen(line)));
		if (ft_isnumber(line) && ft_atoi(line) != 0)
		{
			map->nb_ants = ft_atoi(line);
			break ;
		}
		else if (ft_iscomment(line))
			continue ;
		else
			return (-1);
	}
	return (ft_add_rooms(map));
}

int			ft_add_rooms(t_map *map)
{
	char	*line;

	while (get_next_line(0, &line) && !ft_isliaison(line) && line[0] != '\0')
	{
		ft_strtrim(line);
		ft_list_push(map->lines, ft_list_new(line, ft_strlen(line)));
		if (ft_iscomment(line))
			continue ;
		else if (ft_iscommand(line))
		{
			if (!ft_command_check_and_add(map, line))
				return (-2);
			else
				continue ;
		}
		else
		{
			if (!ft_init_room(map, line))
				return (-3);
		}
	}
	if (line[0] == '\0')
		return (-4);
	return (ft_add_links(map, line));
}

int			ft_add_links(t_map *map, char *line)
{
	char	**split;

	ft_init_matrix(map);
	if (map->start == -1 || map->end == -1 || !ft_links_handle_fl(map, line))
		return (-6);
	while (get_next_line(0, &line) && line[0] != '\0')
	{
		ft_strtrim(line);
		ft_list_push(map->lines, ft_list_new(line, ft_strlen(line)));
		if (ft_iscomment(line))
			continue ;
		if (!ft_isliaison(line))
			return (0);
		else
		{
			split = ft_strsplit(line, '-');
			if (ft_get_index(split[0], map->rooms) == -1
				|| ft_get_index(split[1], map->rooms) == -1)
				return (0);
			else
				ft_add_to_matrix(map, split);
		}
	}
	return (1);
}

int			ft_links_handle_fl(t_map *map, char *line)
{
	char	**split;

	ft_strtrim(line);
	ft_list_push(map->lines, ft_list_new(line, ft_strlen(line)));
	if (ft_iscomment(line))
		return (1);
	split = ft_strsplit(line, '-');
	if (ft_get_index(split[0], map->rooms) == -1
		|| ft_get_index(split[1], map->rooms) == -1)
		return (0);
	else
		ft_add_to_matrix(map, split);
	return (1);
}
