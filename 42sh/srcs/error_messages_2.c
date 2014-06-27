/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 19:32:08 by tmertz            #+#    #+#             */
/*   Updated: 2014/06/02 16:07:45 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/error_messages.h"

int		ft_unmatched_quote(char c)
{
	ft_putstr_fd("Unmatched ", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd(".", 2);
	return (-1);
}

int		ft_anbiguous_redirect_out(void)
{
	ft_putendl_fd("Ambiguous output redirect", 2);
	return (-1);
}

int		ft_anbiguous_redirect_in(void)
{
	ft_putendl_fd("Ambiguous input redirect", 2);
	return (-1);
}

int		ft_cmd_not_found(char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(": Command not found.", 2);
	return (0);
}

int		ft_nofile(char *file)
{
	ft_putstr_fd(file, 2);
	ft_putendl_fd(": No such file or directory.", 2);
	return (-1);
}
