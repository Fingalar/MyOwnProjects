/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:21:03 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/03 17:21:05 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isprint(int c)
{
	if (c != 0)
	{
		if (c < 32 || c > 126)
		{
			return (0);
		}
		return (1);
	}
	return (0);
}
