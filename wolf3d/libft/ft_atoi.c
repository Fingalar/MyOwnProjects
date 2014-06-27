/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:19:50 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/03 20:22:38 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char*		ft_trim_atoi(char *s)
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

int			ft_atoi(const char *str)
{
	int		i;
	int		neg;
	char	*strc;

	neg = 0;
	i = 0;
	strc = ft_trim_atoi((char*)str);
	if (strc[0] == '-')
	{
		neg = 1;
		strc++;
	}
	else if (strc[0] == '+')
		strc++;
	while (*strc != '\0' && (*strc >= '0' && *strc <= '9'))
	{
		i = (i * 10) + (*strc - '0');
		strc++;
	}
	if (neg == 1)
	{
		i = i * (-1);
	}
	return (i);
}
