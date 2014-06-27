/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 17:38:54 by tmertz            #+#    #+#             */
/*   Updated: 2014/02/09 22:18:43 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int		V_BOOL = 0;

static void		ft_sigusr_one(int sigint)
{
	t_id	*client_pid;
	t_car	*car;

	if (V_BOOL == 0)
	{
		client_pid = (t_id *)ft_get_t_id();
		client_pid->bin[client_pid->index++] = '0';
	}
	else
	{
		car = (t_car *)ft_get_t_car();
		car->bin[car->index++] = '0';
	}
	sigint += 0;
}

static void		ft_sigusr_two(int sigint)
{
	t_id	*client_pid;
	t_car	*car;

	if (V_BOOL == 0)
	{
		client_pid = (t_id *)ft_get_t_id();
		client_pid->bin[client_pid->index++] = '1';
	}
	else
	{
		car = (t_car *)ft_get_t_car();
		car->bin[car->index++] = '1';
	}
	sigint += 0;
}

char			*ft_add_carac(t_car *carac, char *result, t_id *client_pid)
{
	carac->car = ft_bintoi(carac->bin);
	result = ft_charjoin(result, carac->car);
	ft_bzero(carac->bin, 8);
	carac->index = 0;
	usleep(300);
	if (carac->car == 0)
	{
		ft_putendl(result);
		result = NULL;
		V_BOOL = 0;
		kill((pid_t)client_pid->id, SIGUSR1);
		client_pid->index = 0;
		ft_bzero(client_pid->bin, 33);
	}
	return (result);
}

void			ft_handle_signals(t_car *carac)
{
	char	*result;
	t_id	*client_pid;

	client_pid = (t_id *)ft_get_t_id();
	result = NULL;
	while (1)
	{
		pause();
		if (ft_strlen(client_pid->bin) == 32 && V_BOOL == 0)
		{
			V_BOOL = 1;
			client_pid->id = ft_bintoi(client_pid->bin);
			usleep(300);
			kill((pid_t)client_pid->id, SIGUSR1);
		}
		if (ft_strlen(carac->bin) == 8)
			result = ft_add_carac(carac, result, client_pid);
		if (V_BOOL == 1)
			kill((pid_t)client_pid->id, SIGUSR1);
	}
}

int				main(void)
{
	pid_t		pid;
	int			n;
	t_car		*carac;

	n = 0;
	pid = getpid();
	ft_putnbr((int)pid);
	ft_putchar('\n');
	carac = (t_car *)ft_get_t_car();
	signal(SIGUSR2, &ft_sigusr_two);
	signal(SIGUSR1, &ft_sigusr_one);
	ft_handle_signals(carac);
	return (0);
}
