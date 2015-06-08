/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:24:13 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 06:39:52 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*s1c;
	size_t		i;
	const char	*s2c;

	if (s1 == NULL || s2 == NULL || n == 0)
	{
		return (s1);
	}
	i = 0;
	s1c = s1;
	s2c = s2;
	while (i < n)
	{
		s1c[i] = s2c[i];
		i++;
	}
	return (s1);
}
