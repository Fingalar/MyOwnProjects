/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 23:40:40 by tfrere            #+#    #+#             */
/*   Updated: 2014/02/09 21:31:56 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"


void	*ft_get_t_car(void)
{
	static t_car	*carac = NULL;

	if (carac == NULL)
	{
		carac = malloc(sizeof(t_car));
		carac->index = 0;
		carac->bin = malloc(sizeof(char) * 9);
	}
	return ((void *)carac);
}

void	*ft_get_t_id(void)
{
	static t_id	*pid = NULL;

	if (pid == NULL)
	{
		pid = (t_id *)malloc(sizeof(t_id));
		pid->index = 0;
		pid->bin = malloc(sizeof(char) * 33);
	}
	return ((void *)pid);
}
