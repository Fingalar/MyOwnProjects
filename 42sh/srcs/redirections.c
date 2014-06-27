/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 14:31:52 by tmertz            #+#    #+#             */
/*   Updated: 2014/06/22 18:14:01 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/redirections.h"

static int	(*g_solve_tree[3])(t_node *, t_sh *) = {ft_check_cmd,
	ft_exec_subshell, ft_make_redir};

int		ft_wich_redir(t_node *node)
{
	int		fd;
	int		wronly_creat;

	wronly_creat = O_WRONLY | O_CREAT;
	if (!ft_strcmp((char *)node->value, ">"))
	{
		fd = open((char *)node->right->value, O_TRUNC | wronly_creat, 0777);
		dup2(fd, 1);
	}
	if (!ft_strcmp((char *)node->value, ">>"))
	{
		fd = open((char *)node->right->value, O_APPEND | wronly_creat, 0777);
		dup2(fd, 1);
	}
	if (!ft_strcmp((char *)node->value, "<"))
	{
		fd = open((char *)node->right->value, O_RDONLY);
		if (fd == -1)
			return (ft_nofile((char *)node->right->value));
		dup2(fd, 0);
	}
	return (fd);
}

int		ft_make_redir(t_node *node, t_sh *sh)
{
	int		fd;
	pid_t	process;
	int		ret;

	ret = 0;
	process = fork();
	if (process == 0)
	{
		fd = ft_wich_redir(node);
		if (fd == -1)
			exit(1);
		exit(g_solve_tree[L_PRIORITY](node->left, sh));
		close(fd);
	}
	else
	{
		wait(&process);
		waitpid(process, 0, WIFEXITED(ret));
	}
	return (ret);
}
