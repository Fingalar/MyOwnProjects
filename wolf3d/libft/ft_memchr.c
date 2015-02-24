/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:23:50 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 06:40:27 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*sc;

	if (s != NULL && n != 0)
	{
		sc = (char*)s;
		i = 0;
		while (i < n)
		{
			if (sc[i] == (char)c)
			{
				return ((void*)(s + i));
			}
			i++;
		}
	}
	return (NULL);
}
