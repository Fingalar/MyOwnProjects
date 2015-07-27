/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putllnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 18:42:41 by tmertz            #+#    #+#             */
/*   Updated: 2015/02/17 18:47:30 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putllnbr(unsigned long long int n)
{
	if (n < 10)
	{
		ft_putchar(n + '0');
	}
	else
	{
		ft_putllnbr(n / 10);
		ft_putllnbr(n % 10);
	}
}
