/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:24:02 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/03 17:24:06 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*s1c;
	const char	*s2c;

	if (s1 != NULL && s2 != NULL && n != 0)
	{
		i = 0;
		s1c = s1;
		s2c = s2;
		while (i < n)
		{
			if (s1c[i] != s2c[i])
			{
				return (s1c[i] - s2c[i]);
			}
			i++;
		}
		return (0);
	}
	return (1);
}
