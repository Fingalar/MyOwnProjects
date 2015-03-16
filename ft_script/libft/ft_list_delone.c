/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_delone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:21:29 by tmertz            #+#    #+#             */
/*   Updated: 2014/02/09 20:23:14 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		ft_list_del_mid(t_elem *buffer)
{
	t_elem		*buffer1;
	t_elem		*buffer2;

	buffer1 = buffer->previous;
	buffer2 = buffer->next;
	buffer1->next = buffer2;
	buffer1->next->previous = buffer1;
}

void			ft_list_delone(t_list *list, t_elem *this)
{
	t_elem		*buffer;

	buffer = this;
	if (buffer == list->first)
	{
		list->first = buffer->next;
		if (list->first != NULL)
			list->first->previous = NULL;
	}
	else if (buffer == list->last)
	{
		list->last = buffer->previous;
		if (list->last != NULL)
			list->last->next = NULL;
	}
	else
		ft_list_del_mid(buffer);
	list->size -= 1;
}
