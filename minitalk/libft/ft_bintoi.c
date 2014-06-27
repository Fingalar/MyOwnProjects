/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 18:09:59 by tmertz            #+#    #+#             */
/*   Updated: 2014/02/09 18:29:42 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_bintoi(char *str)
{
	int		i;
	int		number;
	int		len;

	number = 0;
	i = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == '1')
			number += ft_power(2, len - (i + 1));
		i++;
	}
	return (number);
}
