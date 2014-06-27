/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 06:32:29 by tmertz            #+#    #+#             */
/*   Updated: 2014/02/23 07:01:05 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lemin.h"

int			ft_get_index(char *str, t_list *rooms)
{
	int		i;
	t_elem	*elem;
	t_room	*room;

	i = 0;
	elem = rooms->first;
	while (elem != NULL)
	{
		room = (t_room *)elem->value;
		if (!ft_strcmp(room->name, str))
			return (i);
		i++;
		elem = elem->next;
	}
	return (-1);
}

int			ft_get_room(t_room *room, t_list *list)
{
	t_elem		*elem;
	int			i;

	i = 0;
	elem = list->first;
	while (elem != NULL)
	{
		if (elem->value == room)
			return (i);
		i++;
		elem = elem->next;
	}
	return (-1);
}

t_elem		*ft_memcpy_room(t_elem *new_elem, t_elem *elem)
{
	new_elem = ft_list_new(elem->value, sizeof(t_room *));
	return (new_elem);
}

t_elem		*ft_get_n_elem(t_list *list, int i)
{
	t_elem		*elem;

	elem = list->first;
	while (i-- > 0)
		elem = elem->next;
	return (elem);
}
