/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 19:17:07 by tmertz            #+#    #+#             */
/*   Updated: 2014/02/13 16:36:20 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tablen(void **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
