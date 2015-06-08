/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_unpush.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:23:06 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/03 17:23:10 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void			ft_list_unpush(t_list *list)
{
	t_elem		*buffer;

	buffer = list->last->previous;
	list->last = buffer;
	if (list->last != NULL)
		list->last->next = NULL;
	list->size -= 1;
}
