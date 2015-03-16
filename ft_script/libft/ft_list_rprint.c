/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_rprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:22:33 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/03 17:22:34 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void			ft_list_rprint(t_list *list, char *str)
{
	t_elem		*buffer;

	buffer = list->last;
	while (buffer != NULL)
	{
		if (buffer->size_value == sizeof(char))
			ft_putchar(*(char*)(buffer->value));
		else if (buffer->size_value == sizeof(int))
			ft_putnbr(*(int*)(buffer->value));
		else if (buffer->size_value == sizeof(char*))
			ft_putstr((char*)(buffer->value));
		if (buffer->previous != NULL)
			ft_putstr(str);
		buffer = buffer->previous;
	}
}
