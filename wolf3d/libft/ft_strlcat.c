/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:30:06 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/03 20:22:50 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	origin;
	size_t	c;

	i = j = c = 0;
	origin = n;
	while (src[i] != '\0')
		i++;
	while (dest[j] != '\0')
		j++;
	while (dest[c] != '\0' && n != 0)
	{
		c++;
		n--;
	}
	if (n == 0)
		return (origin + i);
	c = -1;
	while (src[++c] && n-- > 1)
		dest[c + j] = src[c];
	dest[c + j] = '\0';
	return (i + j);
}
