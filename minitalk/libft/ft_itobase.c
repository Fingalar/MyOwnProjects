/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 17:27:56 by tmertz            #+#    #+#             */
/*   Updated: 2014/02/09 17:28:09 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itobase(int number, int base, int size)
{
	char	*bin;
	int		i;

	i = 0;
	bin = ft_memalloc(sizeof(char) * size + 1);
	while (i < size)
		bin[i++] = '0';
	while (number != 0)
	{
		if (number % base < 10)
			bin[--i] = number % base + '0';
		else
			bin[--i] = number % base + 'A';
		number /= base;
	}
	return (bin);
}
