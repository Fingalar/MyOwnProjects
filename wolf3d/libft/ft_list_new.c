/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:19:22 by tmertz            #+#    #+#             */
/*   Updated: 2014/06/13 18:35:01 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_elem			*ft_list_new(void *value, int size_value)
{
	t_elem		*new;

	new = (t_elem*)malloc(sizeof(t_elem) * 2);
	new->value = value;
	new->size_value = size_value;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}
