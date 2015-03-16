/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:32:05 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 06:28:14 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

int			ft_str_fill_split(char const *s, char **split, int number, char c)
{
	int		i;

	i = 0;
	split[number] = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	while (s[i] != (char)c && s[i] != '\0')
	{
		split[number][i] = s[i];
		i++;
	}
	split[number][i] = '\0';
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		i;
	int		number;

	if ((split = (char**)malloc(sizeof(char *) * ft_strlen(s) + 1)) && s
			!= NULL)
	{
		i = 0;
		number = 0;
		while (s[i] != '\0' && i != (int)ft_strlen(s))
		{
			if (s[i] != (char)c)
			{
				i += ft_str_fill_split(s + i, split, number, c);
				number++;
			}
			else
			{
				i++;
			}
		}
		split[number] = '\0';
		return (split);
	}
	return (NULL);
}
