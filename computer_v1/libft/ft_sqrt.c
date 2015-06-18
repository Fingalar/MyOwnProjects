/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 16:35:49 by cfriot            #+#    #+#             */
/*   Updated: 2015/06/09 18:00:34 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_sqrt(double nb)
{
	double calc;
	double diff;

	if (nb < 0)
		nb = -nb;
	if (nb == 0.0 || nb == 1.0)
		return (nb);
	calc = nb;
	diff = 0;
	while (calc != diff)
	{
		diff = calc;
		calc = 0.5 * (calc + nb / calc);
	}
	return (calc);
}
