/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyguel <nyguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:19:50 by tmertz            #+#    #+#             */
/*   Updated: 2014/06/20 16:47:22 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char			*ft_trim_atoi(char *s)
{
	char	*dst;
	int		i;
	int		j;
	int		rep;

	i = 0;
	j = 0;
	rep = 0;
	if ((dst = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
	{
		while (s[i] != '\0')
		{
			if (!((s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\v'
					|| s[i] == '\f' || s[i] == '\r') && (rep == 0)))
				rep = 1;
			if (rep == 1)
			{
				dst[j] = s[i];
				j++;
			}
			i++;
		}
		return (dst);
	}
	return (NULL);
}

int				ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	int			num;

	if (str == NULL)
		return (0);
	num = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
		sign = (str[i++] == '-') ? -1 : 1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num * sign);
}
