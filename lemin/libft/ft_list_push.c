/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:22:21 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/03 17:22:24 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void			ft_list_push(t_list *list, t_elem *new)
{
	t_elem		*buffer;

	if (new)
	{
		buffer = list->last;
		list->last = new;
		new->previous = buffer;
		new->next = NULL;
		if (new->previous != NULL)
			new->previous->next = new;
		list->size += 1;
	}
	if (new->previous == NULL)
		list->first = new;
}
