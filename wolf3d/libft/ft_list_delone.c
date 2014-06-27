/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_delone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:21:29 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/07 20:56:07 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_list_delone(t_list *list, t_elem *this)
{
	t_elem	*buffer;
	t_elem	*buffer2;

	buffer = list->first;
	while (buffer != NULL && buffer != this)
		buffer = buffer->next;
	if (this == list->first)
	{
		buffer = this->next;
		list->first = buffer;
		list->last->next = buffer;
		buffer->previous = list->last;
		list->size -= 1;
		free(this);
	}
	else
	{
		buffer = buffer->previous;
		buffer2 = this->next;
		buffer->next = buffer2;
		buffer->next->previous = buffer;
		list->size -= 1;
		free(this);
	}
}
