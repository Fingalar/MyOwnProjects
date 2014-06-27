/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_inits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 06:25:29 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/21 17:31:31 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lemin.h"
#include <stdlib.h>

t_map		*ft_init_map(t_map *map)
{
	map = ft_memalloc(sizeof(t_map));
	map->rooms = ft_list_init(map->rooms);
	map->lines = ft_list_init(map->lines);
	map->start = -1;
	map->end = -1;
	map->nb_ants = 0;
	map->adj_matrix = NULL;
	map->roads = NULL;
	return (map);
}

void		ft_init_matrix(t_map *map)
{
	int		i;

	i = 0;
	map->adj_matrix = ft_memalloc(sizeof(int *) * map->rooms->size);
	while (i < map->rooms->size)
		map->adj_matrix[i++] = ft_memalloc(sizeof(int) * map->rooms->size);
}

int			ft_init_room(t_map *map, char *line)
{
	t_room		*room;
	char		**split;

	split = ft_strsplit(line, ' ');
	if ((map->rooms->first != NULL && ft_get_index(split[0], map->rooms) != -1)
		|| ft_tablen((void **)split) != 3 || !ft_isnumber(split[1])
			|| !ft_isnumber(split[2]) || split[0][0] == 'L')
		return (0);
	room = malloc(sizeof(t_room));
	room->name = ft_strdup(split[0]);
	room->weight = -1;
	if (map->start == map->rooms->size)
		room->weight = 0;
	if (map->end == map->rooms->size)
		room->end = 1;
	room->visited = 0;
	room->occupied = 0;
	room->index = map->rooms->size;
	room->prev = NULL;
	room->coord_x = ft_atoi(split[1]);
	room->coord_y = ft_atoi(split[2]);
	ft_list_push(map->rooms, ft_list_new(room, sizeof(t_room *)));
	return (1);
}

t_list		*ft_make_road(t_map *map, int end, int start)
{
	t_list		*list;
	t_room		*room;

	list = NULL;
	list = ft_list_init(list);
	room = ft_get_n_elem(map->rooms, end)->value;
	while (ft_get_index(room->name, map->rooms) != start)
	{
		ft_list_add(list, ft_list_new(room, sizeof(t_room *)));
		room = room->prev;
	}
	ft_list_add(list, ft_list_new(room, sizeof(t_room *)));
	return (list);
}

void		ft_init_ants(t_map *map)
{
	int			i;
	int			j;
	int			k;
	int			nb_roads;

	i = j = 0;
	nb_roads = map->roads->size;
	k = map->roads->size - 1;
	map->ants = ft_memalloc(sizeof(t_ant *) * map->nb_ants + 1);
	while (i < map->nb_ants)
	{
		map->ants[i] = ft_memalloc(sizeof(t_ant));
		map->ants[i]->id = i + 1;
		map->ants[i]->position = ft_strdup(
			((t_room *)ft_get_n_elem(map->rooms, map->start)->value)->name);
		map->ants[i]->id_pos = map->start;
		ft_define_way(map, j, i);
		if (map->nb_ants - (i + 1) <= map->size_roads[k] && k != 0)
			nb_roads = k--;
		else
			j++;
		if (j == nb_roads)
			j = 0;
		i++;
	}
}
