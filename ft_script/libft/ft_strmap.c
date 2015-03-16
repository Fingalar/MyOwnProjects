/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:30:33 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 06:30:45 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	int		i;

	i = 0;
	if (f != NULL && (fresh = (char *)malloc(sizeof(s) + 1)))
	{
		while (s[i] != '\0')
		{
			fresh[i] = f((char)s[i]);
			i++;
		}
		fresh[i] = '\0';
		return (fresh);
	}
	fresh = ft_strdup(s);
	return (fresh);
}
