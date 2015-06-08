/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:24:41 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 06:39:12 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void		*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	size_t	n;

	if (b == NULL && len == 0)
	{
		return (b);
	}
	str = (char*)b;
	n = 0;
	while (n < len)
	{
		str[n] = (unsigned char)c;
		n++;
	}
	return (b);
}
