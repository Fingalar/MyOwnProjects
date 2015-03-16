/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_unadd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:22:56 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/03 17:22:57 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void			ft_list_unadd(t_list *list)
{
	t_elem		*buffer;

	buffer = list->first->next;
	list->first = buffer;
	if (list->first != NULL)
		list->first->previous = NULL;
	list->size -= 1;
}
