/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 17:13:29 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/21 17:30:47 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/libft.h"
#include <stdlib.h>

int			main(void)
{
	t_map		*map;

	map = NULL;
	map = ft_lemin_parser(map);
	if (map != NULL)
	{
		ft_display_instructions(map);
		ft_multi_pathfinding(map);
		if (map->roads->first == NULL)
		{
			ft_putendl_fd("Error, no path to finish Lem-in", 2);
			return (0);
		}
		ft_init_ants(map);
		ft_exec_lemin(map);
	}
	return (0);
}

void		ft_display_instructions(t_map *map)
{
	t_elem		*elem;

	elem = map->lines->first;
	while (elem != NULL)
	{
		ft_putendl(elem->value);
		elem = elem->next;
	}
	ft_putchar('\n');
}

void		ft_define_way(t_map *map, int index, int i)
{
	t_elem		*elem;

	map->ants[i]->way = ft_list_init(map->ants[i]->way);
	elem = map->roads->first;
	while (index-- > 0)
		elem = elem->next;
	elem = ((t_list *)elem->value)->first;
	while (elem != NULL)
	{
		ft_list_push(map->ants[i]->way
					, ft_list_new(elem->value, sizeof(t_room *)));
		elem = elem->next;
	}
	map->ants[i]->room = map->ants[i]->way->first;
}

void		ft_exec_lemin(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->nb_ants)
	{
		if (map->ants[i]->room->next != NULL
			&& ((t_room *)map->ants[i]->room->next->value)->occupied != 1)
		{
			((t_room *)map->ants[i]->room->value)->occupied = 0;
			map->ants[i]->room = map->ants[i]->room->next;
			map->ants[i]->position =
				((t_room *)map->ants[i]->room->value)->name;
			if (((t_room *)map->ants[i]->room->value)->end == 0)
				((t_room *)map->ants[i]->room->value)->occupied = 1;
			ft_write_move(map, i);
		}
		i++;
	}
	ft_putchar('\n');
	if (!ft_strcmp(((t_room *)map->ants[map->nb_ants - 1]->room->value)->name
			, ((t_room *)ft_get_n_elem(map->rooms, map->end)->value)->name))
		return ;
	return (ft_exec_lemin(map));
}

void		ft_write_move(t_map *map, int i)
{
	int		flag;

	flag = 0;
	ft_putstr("L");
	ft_putnbr(map->ants[i]->id);
	ft_putstr("-");
	ft_putstr(((t_room *)map->ants[i]->room->value)->name);
	while (i < map->nb_ants)
	{
		if (map->ants[i]->room->next != NULL
			&& ((t_room *)map->ants[i]->room->next->value)->occupied != 1)
			flag = 1;
		i++;
	}
	if (flag == 1)
		ft_putstr(" ");
}
