/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:19:22 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/05 01:15:11 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_elem			*ft_list_new(void *value, int size_value)
{
	t_elem		*new;

	new = (t_elem*)ft_memalloc(sizeof(t_elem));
	new->value = ft_memalloc(ft_strlen((char*)value) * size_value);
	new->value = ft_memcpy(new->value, value, ft_strlen((char*)value));
	new->size_value = size_value;
	new->selected = 0;
	new->cursed = 0;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}
