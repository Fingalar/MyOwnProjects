/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:34:13 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 05:28:52 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strtrim_end(char *trim)
{
	int		i;

	i = ft_strlen(trim) - 1;
	while (trim[i] == ' ' || trim[i] == '\t' || trim[i] == '\n')
	{
		trim[i] = '\0';
		i--;
	}
	return (trim);
}

char		*ft_strtrim(char const *s)
{
	char	*trim;
	int		i;
	int		j;
	int		stop;

	if ((trim = (char*)malloc(sizeof(s))) && s != NULL)
	{
		i = 0;
		j = 0;
		stop = 0;
		while (s[i] != '\0')
		{
			if ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && stop == 0)
				i++;
			else
			{
				trim[j++] = s[i++];
				stop = 1;
			}
		}
		trim[j] = '\0';
		return (ft_strtrim_end(trim));
	}
	return (NULL);
}
