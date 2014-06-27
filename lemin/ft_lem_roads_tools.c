/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_roads_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 06:37:09 by tmertz            #+#    #+#             */
/*   Updated: 2014/02/23 06:57:02 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lemin.h"

void		ft_reinitialize_rooms(t_map *map)
{
	t_elem		*elem;
	int			i;

	i = 0;
	elem = map->rooms->first;
	while (elem != NULL)
	{
		((t_room *)elem->value)->visited = 0;
		if (i == map->start)
			((t_room *)elem->value)->weight = 0;
		else
			((t_room *)elem->value)->weight = -1;
		i++;
		elem = elem->next;
	}
}

int			*ft_how_many_adj(t_map *map, t_elem *elem)
{
	int			i;
	int			j;
	int			*result;
	int			index;
	t_room		*room;

	i = 0;
	j = 1;
	room = elem->value;
	index = ft_get_index(room->name, map->rooms);
	result = ft_memalloc(sizeof(map->rooms->size) + 1);
	while (i < map->rooms->size)
	{
		if (map->adj_matrix[index][i] == 1)
		{
			result[0]++;
			result[j++] = i;
		}
		i++;
	}
	return (result);
}
