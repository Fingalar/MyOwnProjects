/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_rchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 23:25:31 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/13 22:36:21 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub_rchr(char const *s, char c)
{
	char			*new_s;
	int				i;

	i = ft_strlen(s);
	if ((new_s = ft_memalloc(sizeof(char) * ft_strlen(s) + 1)) && s != NULL)
	{
		while (i >= 0)
		{
			if (s[i] == c)
			{
				i--;
				while (i >= 0)
				{
					new_s[i] = s[i];
					i--;
				}
			}
			else
				i--;
		}
		return (new_s);
	}
	return (NULL);
}
