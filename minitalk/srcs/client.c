/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 17:39:39 by tmertz            #+#    #+#             */
/*   Updated: 2014/02/09 21:18:31 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static void		sigusr_one(int signum)
{
	signum += 0;
}

void			ft_final_signal(int server_pid)
{
	int		i;

	i = 0;
	while (i++ < 8)
	{
		kill((pid_t)server_pid, SIGUSR1);
		pause();
	}
	ft_putendl("Message Arrived");
}

void			ft_send_chars(int server_pid, char *str)
{
	int		i;
	int		j;
	char	*bin;

	i = 0;
	while (str[i])
	{
		j = -1;
		bin = ft_itobase((int)str[i++], 2, 8);
		while (bin[++j])
		{
			if (bin[j] == '1')
				kill((pid_t)server_pid, SIGUSR2);
			else
				kill((pid_t)server_pid, SIGUSR1);
			pause();
		}
	}
	ft_final_signal(server_pid);
}

void			ft_send_pid(pid_t pid, int server_pid)
{
	char	*bin;
	int		i;

	i = 0;
	bin = ft_itobase((int)pid, 2, 32);
	while (bin[i])
	{
		if (bin[i] == '1')
			kill((pid_t)server_pid, SIGUSR2);
		else
			kill((pid_t)server_pid, SIGUSR1);
		usleep(300);
		i++;
	}
}

int				main(int ac, char **av)
{
	pid_t	pid;
	int		server_pid;

	if (ac != 3)
		return (0);
	else if (!ft_check_arg(av))
		ft_putendl_fd("Please send a valid PID", 2);
	else if (!ft_check_mess(av))
		ft_putendl_fd("Please write a message with Ascii caracteres only", 2);
	else
	{
		pid = getpid();
		server_pid = ft_atoi(av[1]);
		signal(SIGUSR1, &sigusr_one);
		ft_send_pid(pid, server_pid);
		pause();
		ft_send_chars(server_pid, av[2]);
	}
	return (0);
}
