/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:22:12 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 06:41:21 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void			ft_list_print(t_list *list, char *str)
{
	t_elem		*buffer;

	buffer = list->first;
	while (buffer != NULL)
	{
		if (buffer->size_value == sizeof(char))
			ft_putchar(*(char*)(buffer->value));
		else if (buffer->size_value == sizeof(int))
			ft_putnbr(*(int*)(buffer->value));
		else if (buffer->size_value == sizeof(char*))
			ft_putstr((char*)(buffer->value));
		if (buffer->next != NULL)
			ft_putstr(str);
		buffer = buffer->next;
	}
}
