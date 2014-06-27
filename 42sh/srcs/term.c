/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-lacr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 22:53:41 by pde-lacr          #+#    #+#             */
/*   Updated: 2014/05/23 17:32:46 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <termios.h>
#include <termcap.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <term.h>

int					tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int					ft_set_term(void)
{
	char			buffer[2048];
	struct termios	term;

	if (tgetent(buffer, getenv("TERM")) < 1)
		return (-1);
	tcgetattr(0, &term);
	term.c_lflag ^= ICANON;
	term.c_lflag ^= ECHO;
	tcsetattr(0, 0, &term);
	tputs(tgetstr("im", NULL), 1, tputs_putchar);
	return (0);
}

int					ft_unset_term(void)
{
	char			buffer[2048];
	struct termios	term;

	if (tgetent(buffer, getenv("TERM")) < 1)
		return (-1);
	tcgetattr(0, &term);
	term.c_lflag ^= ICANON;
	term.c_lflag ^= ECHO;
	tcsetattr(0, 0, &term);
	tputs(tgetstr("ei", NULL), 1, tputs_putchar);
	return (0);
}
