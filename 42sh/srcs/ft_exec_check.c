/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyguel <nyguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 20:17:50 by nyguel            #+#    #+#             */
/*   Updated: 2014/06/20 16:51:45 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtin_exec.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int	ft_check_fd(char *line, int *i, t_ex *ex)
{
	int		test;
	int		fd;

	test = 1;
	fd = ft_atoi(line);
	if (fd >= 3)
	{
		while (line[*i] && line[*i] >= '0' && line[*i] <= '9')
			*i = *i + 1;
		ex->id_fd = fd;
		test = 0;
	}
	return (test);
}

static int	ft_check_rights(char *line, int *i, t_ex *ex)
{
	int		rights;

	rights = 0;
	if (line[*i] && (line[*i] == '>' || line[*i] == '<'))
	{
		if (line[*i] == '>')
			rights = rights + 1;
		else if (line[*i] == '<')
			rights = rights + 2;
		*i = *i + 1;
	}
	if (line[*i] && (line[*i] == '>' || line[*i] == '<'))
	{
		if ((line[*i] == '>' && rights == 2)
			|| (line[*i] == '<' && rights == 1))
			rights = 3;
		else
			rights = 0;
		*i = *i + 1;
	}
	ex->rights = rights;
	return ((rights > 0) ? 0 : 2);
}

static int	ft_check_path(char *line, int *i, t_ex *ex)
{
	int		test;

	test = 0;
	if (line[*i])
	{
		free(ex->path);
		ex->path = ft_strdup(&line[*i]);
		if (access(ex->path, F_OK) != -1)
		{
			if (ex->rights == 1 && access(ex->path, W_OK) != -1)
				ex->r_fd = open(ex->path, O_WRONLY);
			else if (ex->rights == 2 && access(ex->path, R_OK) != -1)
				ex->r_fd = open(ex->path, O_RDONLY);
			else if (ex->rights == 3 && access(ex->path, R_OK | W_OK) != -1)
				ex->r_fd = open(ex->path, O_RDWR);
			else
				return (3);
			return (0);
		}
	}
	return (3);
}

int			ft_check_exec(char **args, t_ex *ex)
{
	int		i;
	int		test;

	i = 0;
	test = 1;
	if (args[1] && !args[2])
	{
		if ((test = ft_check_fd(args[1], &i, ex)) == 0)
		{
			if ((test = ft_check_rights(args[1], &i, ex)) == 0)
				test = ft_check_path(args[1], &i, ex);
		}
	}
	return (test);
}
