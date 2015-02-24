/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:30:42 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 06:30:55 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fresh;

	if (f != NULL && (fresh = (char *)malloc(sizeof(s) + 1)))
	{
		i = 0;
		while (s[i] != '\0')
		{
			fresh[i] = f(i, (char)s[i]);
			i++;
		}
		fresh[i] = '\0';
		return (fresh);
	}
	else
	{
		fresh = ft_strdup(s);
		return (fresh);
	}
}
