/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 17:29:04 by tmertz            #+#    #+#             */
/*   Updated: 2014/02/09 17:29:05 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str);

char	*ft_charjoin(char *s1, char c)
{
	char	*str;
	size_t	j;

	j = 0;
	if (s1 == NULL)
	{
		str = malloc(sizeof(char) * (2));
		str[0] = c;
		str[1] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	while (s1[j])
	{
		str[j] = s1[j];
		j++;
	}
	str[j++] = c;
	str[j] = '\0';
	return (str);
}
