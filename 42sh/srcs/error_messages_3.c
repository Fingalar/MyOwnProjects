/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 03:37:01 by tmertz            #+#    #+#             */
/*   Updated: 2014/06/22 19:39:53 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/error_messages.h"

int		ft_puterror_nofile(char *arg)
{
	ft_putstr_fd(arg, 2);
	ft_putendl_fd(": No such file or directory.", 2);
	return (-1);
}

int		ft_puterror_nopermission(char *arg)
{
	ft_putstr_fd(arg, 2);
	ft_putendl_fd(": Permission denied.", 2);
	return (-1);
}

int		ft_puterror_notdir(char *arg)
{
	ft_putstr_fd(arg, 2);
	ft_putendl_fd(": Not a directory.", 2);
	return (-1);
}

int		ft_puterror_noenv(void)
{
	ft_putendl_fd("Warning : There is no env", 2);
	return (-1);
}

int		illegal_option(char flag)
{
	ft_putstr_fd("env: illegal option -- ", 2);
	ft_putchar_fd(flag, 2);
	ft_putchar('\n');
	ft_putendl_fd("Usage: env [-i] [name=value ...] [utility [argument ...]]"
					, 2);
	return (1);
}
