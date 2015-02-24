/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:29:56 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 06:32:11 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;

	if (s1 == NULL && s2 == NULL
		&& (join = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		join[0] = '\0';
	else if (s1 == NULL || s2 == NULL)
		join = (s1 == NULL ? ft_strdup(s2) : ft_strdup(s1));
	else if ((join = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
	{
		i = 0;
		j = 0;
		while (s1[i] != '\0')
		{
			join[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			join[i++] = s2[j++];
		}
		join[i] = '\0';
	}
	return (join);
}
