/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyguel <nyguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 19:03:02 by nyguel            #+#    #+#             */
/*   Updated: 2014/06/20 16:52:10 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read.h"
#include <stdlib.h>
#include <fcntl.h>

int			ft_read_arr(char **args, t_read *opt, int *cnt)
{
	free(opt->var_line);
	opt->var_line = NULL;
	opt->var_arr = ft_strdup(args[*cnt + 1]);
	*cnt = *cnt + 1;
	return (0);
}

int			ft_read_fd(char **args, t_read *opt, int *cnt, t_sh *sh)
{
	int		fd;
	int		fd2;
	int		i;

	fd = ft_atoi(args[*cnt + 1]);
	fd2 = 0;
	i = 0;
	while (++i <= sh->fd[0][0])
	{
		if (sh->fd[0][i] == fd)
		{
			fd2 = sh->fd[1][i];
			break ;
		}
	}
	if (fd2 != 0 && fcntl(fd2, F_GETFL) != -1)
	{
		opt->u = fd2;
		*cnt = *cnt + 1;
		return (0);
	}
	return (-1);
}

int			ft_read_k(char **args, t_read *opt, int *cnt)
{
	int		k;

	k = ft_atoi(args[*cnt + 1]);
	if (k >= 0)
	{
		opt->k = k;
		*cnt = *cnt + 1;
		opt->d = -2;
		return (0);
	}
	return (2);
}

int			ft_read_d(char **args, t_read *opt, int *cnt)
{
	char	c;

	c = args[*cnt + 1][0];
	if (ft_isprint(c) == 1)
	{
		opt->d = c;
		*cnt = *cnt + 1;
		return (0);
	}
	return (2);
}

int			ft_read_t(char **args, t_read *opt, int *cnt)
{
	int		t;

	t = ft_atoi(args[*cnt + 1]);
	if (t >= 0)
	{
		opt->t = t;
		*cnt = *cnt + 1;
		return (0);
	}
	return (2);
	(void)opt;
}
