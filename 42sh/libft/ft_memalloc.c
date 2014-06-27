/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:23:19 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 06:40:59 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	char	*mem;
	size_t	i;

	if ((mem = (char*)malloc(sizeof(char) * size + 1)))
	{
		i = 0;
		while (i < size)
		{
			mem[i] = 0;
			i++;
		}
		return ((void*)mem);
	}
	return (NULL);
}
