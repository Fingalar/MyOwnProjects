/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:24:59 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/03 17:25:01 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int			ft_power(int number, int power)
{
	int					j;
	unsigned int		result;

	result = 1;
	while (j < power)
	{
		result = result * number;
		j++;
	}
	return (result);
}
