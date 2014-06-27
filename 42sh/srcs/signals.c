/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 22:07:40 by tmertz            #+#    #+#             */
/*   Updated: 2014/06/22 17:52:08 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/signals.h"

void	handle_ctrl_c(void)
{
	ft_putchar('\n');
	ft_display_prompt(get_sh());
}

void	ft_handle_signals(int signum)
{
	if (signum == 11)
		handle_segfault();
	if (signum == SIGINT)
		handle_ctrl_c();
}

void	handle_segfault(void)
{
	ft_putendl_fd("SEGFAULLLLLLLLLLT !!!!!", 2);
	exit(1);
}

void	catch_signals(void)
{
	signal(SIGSEGV, &ft_handle_signals);
	signal(SIGINT, &ft_handle_signals);
	signal(SIGHUP, &ft_handle_signals);
	signal(SIGTSTP, &ft_handle_signals);
}
