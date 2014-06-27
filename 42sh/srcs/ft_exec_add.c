/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyguel <nyguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 18:45:45 by nyguel            #+#    #+#             */
/*   Updated: 2014/06/07 18:11:45 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtin_exec.h"
#include <stdlib.h>

static int	**ft_int_arr_add(int **fd, t_ex *ex)
{
	int		**ret;
	int		i;

	ret = (int **)malloc(sizeof(int *) * 2);
	ret[0] = (int *)malloc(sizeof(int) * fd[0][0] + 2);
	ret[1] = (int *)malloc(sizeof(int) * fd[0][0] + 2);
	ret[0][0] = fd[0][0] + 1;
	ret[1][0] = fd[1][0] + 1;
	i = 0;
	while (++i < fd[0][0] + 1)
	{
		ret[0][i] = fd[0][i];
		ret[1][i] = fd[1][i];
	}
	ret[0][i] = ex->id_fd;
	ret[1][i] = ex->r_fd;
	free(fd[0]);
	free(fd[1]);
	free(fd);
	return (ret);
}

int			ft_add_fd(t_ex *ex, t_sh *sh)
{
	int		i;
	int		test;

	i = 0;
	test = 0;
	while (++i <= sh->fd[0][0])
	{
		if (sh->fd[0][i] == ex->id_fd)
		{
			test = 1;
			sh->fd[1][i] = ex->r_fd;
		}
	}
	if (test == 0)
		sh->fd = ft_int_arr_add(sh->fd, ex);
	return (0);
}
