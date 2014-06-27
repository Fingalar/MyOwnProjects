/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 20:49:38 by jburet            #+#    #+#             */
/*   Updated: 2014/06/22 17:47:50 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"
#include <stdio.h>

char		*get_hist(int dir, t_sh *sh)
{
	if (!sh->history)
		return (NULL);
	if (dir == KEY_UP)
	{
		if (sh->history->next)
		{
			sh->history = sh->history->next;
			return (sh->history->cmd);
		}
	}
	else if (dir == KEY_DOWN)
	{
		if (sh->history->prev)
		{
			sh->history = sh->history->prev;
			return (sh->history->cmd);
		}
	}
	return (NULL);
}

t_hist		*record_cmd_list(t_sh *sh, char *cmd)
{
	t_hist		*elem;

	elem = (t_hist *)ft_memalloc(sizeof(t_hist));
	if (!sh->history)
		sh->history = (t_hist *)ft_memalloc(sizeof(t_hist));
	while (sh->history->prev)
		sh->history = sh->history->prev;
	elem->cmd = ft_strdup(cmd);
	elem->next = sh->history;
	elem->prev = NULL;
	sh->history->prev = elem;
	sh->history = sh->history->prev;
	return (sh->history);
}

t_hist		*recup_hist(t_sh *sh)
{
	char	*line;
	int		fd;
	char	*path;

	path = ft_strjoin(ft_get_var(sh, "HOME"), "/");
	path = ft_strjoin(path, NAME_HIST);
	if ((fd = open(path, O_RDWR | O_CREAT | O_APPEND, 0755)) == -1)
		return (NULL);
	while (get_next_line(fd, &line) != 0)
		sh->history = record_cmd_list(sh, line);
	close(fd);
	free(path);
	return (sh->history);
}

void		save_cmd(char *cmd, t_sh *sh)
{
	char	*path;
	int		fd;

	if (!cmd[0])
		return ;
	sh->history = record_cmd_list(sh, cmd);
	path = ft_strjoin(ft_get_var(sh, "HOME"), "/");
	path = ft_strjoin(path, NAME_HIST);
	if ((fd = open(path, O_RDWR | O_CREAT | O_APPEND, 0755)) != -1)
		ft_putendl_fd(cmd, fd);
	else
		return ;
	free(path);
	close(fd);
}

int			move_history(char *read, t_sh *sh)
{
	if (read[0] && read[1] && read[2])
	{
		if (read[2] == 65 && sh->history->next)
			return (KEY_UP);
		if (read[2] == 66 && sh->history->prev)
			return (KEY_DOWN);
	}
	return (0);
}
