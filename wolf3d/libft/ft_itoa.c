/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:21:13 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 06:42:36 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

int			size_int(int n)
{
	int		size;

	size = 0;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char		*ft_itoa_no_exeption(int n, char *str, int size)
{
	size = (n > 0 ? size - 1 : size);
	str[size + 1] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
		while (n > 0 && size > 0)
		{
			str[size] = n % 10 + '0';
			n = n / 10;
			size--;
		}
	}
	else
	{
		while (n > 0 || size > 0)
		{
			str[size] = n % 10 + '0';
			n = n / 10;
			size--;
		}
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = size_int(n);
	if ((str = (char *)malloc(size + 2)) || n == 0)
	{
		if (n == 0)
		{
			str[0] = '0';
			str[1] = '\0';
			return (str);
		}
		if (n == -2147483648)
		{
			return (ft_strdup("-2147483648"));
		}
		return (ft_itoa_no_exeption(n, str, size));
	}
	return (NULL);
}
