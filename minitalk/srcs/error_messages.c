/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 18:55:41 by tmertz            #+#    #+#             */
/*   Updated: 2014/02/09 18:56:35 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int				ft_check_arg(char **av)
{
	int		i;

	i = 0;
	while (av[1][i])
	{
		if (!ft_isalnum(av[1][i++]))
			return (0);
	}
	return (1);
}

int				ft_check_mess(char **av)
{
	int		i;

	i = 0;
	while (av[2][i])
	{
		if (!ft_isascii(av[2][i++]))
			return (0);
	}
	return (1);
}
