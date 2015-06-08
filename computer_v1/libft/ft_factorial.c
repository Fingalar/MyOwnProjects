/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:20:04 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 05:26:19 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long			ft_factorial(int number)
{
	long		result;
	int			neg;

	if (number > 0)
		neg = 0;
	else
	{
		number = number * (-1);
		neg = 1;
	}
	result = 1;
	while (number > 0)
	{
		result = result * number;
	}
	if (neg == 1)
		result = result * (-1);
	return (result);
}
