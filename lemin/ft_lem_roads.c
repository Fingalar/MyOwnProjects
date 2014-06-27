/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_roads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 16:28:23 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/21 17:31:11 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lemin.h"
#include <stdlib.h>

void		ft_multi_pathfinding(t_map *map)
{
	t_list		*road;
	t_elem		*elem;
	int			i;

	map->roads = ft_list_init(map->roads);
	while ((road = ft_dijkstra(map, 0)) != NULL)
	{
		ft_list_push(map->roads, ft_list_new(road, sizeof(t_list *)));
		ft_del_road(road, map);
		road = NULL;
	}
	i = 0;
	elem = map->roads->first;
	map->size_roads = ft_memalloc(sizeof(map->roads->size));
	while (elem != NULL)
	{
		map->size_roads[i] = ((t_list *)elem->value)->size;
		i++;
		elem = elem->next;
	}
}

t_list		*ft_dijkstra(t_map *map, int weight)
{
	t_elem		*elem;
	t_list		*list;

	list = ft_get_less_weights(map->rooms, weight);
	elem = list->first;
	if (elem == NULL)
		return (NULL);
	while (elem != NULL)
	{
		if (ft_extend_dijkstra(map, elem, weight))
			return (ft_make_road(map, map->end, map->start));
		elem = elem->next;
	}
	return (ft_dijkstra(map, weight + 1));
}

int			ft_extend_dijkstra(t_map *map, t_elem *elem, int weight)
{
	int		i;
	int		*adjs;

	i = 0;
	adjs = ft_how_many_adj(map, elem);
	while (++i <= adjs[0])
	{
		if (((t_room *)ft_get_n_elem(map->rooms, adjs[i])->value)->visited != 1)
		{
			((t_room *)ft_get_n_elem(map->rooms , adjs[i])->value)->prev
				= (t_room *)elem->value;
			((t_room *)ft_get_n_elem(map->rooms, adjs[i])->value)->weight
				= weight + 1;
			if (map->end == adjs[i])
				return (1);
		}
	}
	return (0);
}

t_list		*ft_get_less_weights(t_list *rooms, int weight)
{
	t_elem		*elem;
	t_elem		*new_elem;
	t_list		*list;

	list = NULL;
	list = ft_list_init(list);
	elem = rooms->first;
	while (elem != NULL)
	{
		if (((t_room *)elem->value)->weight == weight)
		{
			((t_room *)elem->value)->visited = 1;
			new_elem = ft_memcpy_room(new_elem, elem);
			ft_list_add(list, new_elem);
		}
		elem = elem->next;
	}
	return (list);
}

void		ft_del_road(t_list *road, t_map *map)
{
	t_elem	*elem;
	int		i;
	int		j;

	elem = road->first->next;
	if (elem == road->last)
	{
		map->adj_matrix[map->start][map->end] = 0;
		map->adj_matrix[map->end][map->start] = 0;
	}
	else
	{
		while (ft_get_room((t_room *)elem->value, map->rooms) != map->end)
		{
			i = ft_get_room((t_room *)elem->value, map->rooms);
			j = -1;
			while (++j < map->rooms->size)
			{
				map->adj_matrix[i][j] = 0;
				map->adj_matrix[j][i] = 0;
			}
			elem = elem->next;
		}
	}
	ft_reinitialize_rooms(map);
}
