/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyguel <nyguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 20:16:48 by nyguel            #+#    #+#             */
/*   Updated: 2014/06/13 20:25:38 by nyguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtin_exec.h"
#include <stdlib.h>
#define ERR "exec usage: exec <fd>[\\>\\<]et/ou[\\<\\>]<file>"

#include <stdio.h>

static t_ex	*ft_init_ex(void)
{
	t_ex	*ex;

	ex = (t_ex *)malloc(sizeof(t_ex));
	ex->id_fd = -1;
	ex->r_fd = -1;
	ex->rights = 0;
	ex->path = (char *)malloc(sizeof(char));
	ex->path[0] = '\0';
	return (ex);
}

static void	ft_free_ex(t_ex *ex)
{
	free(ex->path);
	free(ex);
}

static void	ft_ex_error(int test)
{
	if (test == 1)
		ft_putendl_fd("exec: wrong fd", 2);
	if (test == 2)
		ft_putendl_fd("exec: wrong rights", 2);
	if (test == 3)
		ft_putendl_fd("exec: wrong path", 2);
	if (test != 0)
		ft_putendl_fd(ERR, 2);
}

int			ft_exec(t_cmd *cmd, t_sh *sh)
{
	t_ex	*ex;
	int		test;

	test = 0;
	ex = ft_init_ex();
	if ((test = ft_check_exec(cmd->args, ex)) == 0)
		test = ft_add_fd(ex, sh);
	ft_free_ex(ex);
	ft_ex_error(test);
	return (test);
}
