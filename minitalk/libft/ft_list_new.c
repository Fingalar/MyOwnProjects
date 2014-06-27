/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:19:22 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/22 22:24:37 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_elem			*ft_list_new(void *value, int size_value, int priority)
{
	t_elem		*new;

	new = (t_elem*)malloc(sizeof(t_elem) * 2);
	new->value = malloc(sizeof(char) * ft_strlen((char*)value) * size_value);
	new->value = ft_memcpy(new->value, value, ft_strlen((char*)value));
	new->size_value = size_value;
	new->priority = priority;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}
