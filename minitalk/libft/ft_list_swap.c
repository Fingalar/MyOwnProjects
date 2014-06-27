/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:22:44 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/03 17:22:48 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void			ft_list_swap(t_elem *elem1, t_elem *elem2)
{
	void		*buffer_value;
	int			size_value;

	buffer_value = elem1->value;
	size_value = elem1->size_value;
	elem1->value = elem2->value;
	elem1->size_value = elem2->size_value;
	elem2->value = buffer_value;
	elem2->size_value = size_value;
}
