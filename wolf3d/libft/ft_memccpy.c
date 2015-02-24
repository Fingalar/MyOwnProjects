/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:23:36 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 06:40:44 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*s1c;
	size_t		i;
	const char	*s2c;

	if (s1 == NULL || s2 == NULL || n == 0)
		return (NULL);
	s1c = s1;
	s2c = s2;
	i = 0;
	while (i < n)
	{
		s1c[i] = s2c[i];
		if (s1c[i] == (unsigned char)c)
		{
			return (s1 + i + 1);
		}
		i++;
	}
	return (NULL);
}
