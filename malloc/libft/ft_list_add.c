/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:21:21 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/15 01:30:36 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void			ft_list_add(t_list *list, t_elem *new)
{
	t_elem		*buffer;

	if (list->first == NULL)
	{
		list->first = new;
		list->last = new;
		list->size = 1;
		new->previous = NULL;
	}
	else
	{
		buffer = list->first;
		list->first = new;
		new->next = buffer;
		new->previous = NULL;
		if (new->next != NULL)
			new->next->previous = new;
		list->size += 1;
	}
}
