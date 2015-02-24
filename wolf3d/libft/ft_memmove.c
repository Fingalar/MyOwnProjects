/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:24:31 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 06:43:04 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void		*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*buffer;
	char		*s1c;
	size_t		i;
	const char	*s2c;

	if (s1 == NULL || s2 == NULL || n == 0)
		return (s1);
	i = 0;
	s1c = s1;
	s2c = (char*)s2;
	buffer = (char*)malloc(sizeof(char*) * n);
	while (i < n)
	{
		buffer[i] = s2c[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		s1c[i] = buffer[i];
		i++;
	}
	return (s1);
}
