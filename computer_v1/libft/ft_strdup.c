/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:28:53 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 06:32:38 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	if (s == NULL)
	{
		return (NULL);
	}
	i = 0;
	if ((dup = malloc(sizeof(char*) * ft_strlen((char*)s) + 1)))
	{
		while (s[i] != '\0')
		{
			dup[i] = (char)s[i];
			i++;
		}
		dup[i] = '\0';
		return (dup);
	}
	return (NULL);
}
