/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 13:29:01 by tmertz            #+#    #+#             */
/*   Updated: 2014/06/22 18:09:35 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipe.h"

static int	(*g_solve_tree[3])(t_node *, t_sh *) = {ft_check_cmd,
	ft_exec_subshell, ft_make_redir};

int			ft_pipe(t_node *node, t_sh *sh, int i)
{
	pid_t	process;
	int		pipe_fd[2];

	while (i > 0)
	{
		pipe(pipe_fd);
		process = fork();
		if (process)
		{
			close(pipe_fd[0]);
			dup2(pipe_fd[1], 1);
			exit(g_solve_tree[L_PRIORITY](node->left, sh));
		}
		node = node->right;
		i--;
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		wait(NULL);
	}
	exit(g_solve_tree[node->priority](node, sh));
	return (0);
}

int			ft_check_pipe(t_node *node, t_sh *sh)
{
	int		i;
	int		ret;
	t_node	*buffer;
	pid_t	process;

	i = 1;
	process = fork();
	buffer = node;
	if (process)
	{
		while (node->right && R_PRIORITY == 3)
		{
			i++;
			node = node->right;
		}
		exit(ft_pipe(buffer, sh, i));
	}
	else
		waitpid(process, &ret, 0);
	if (WIFEXITED(ret))
		return (WEXITSTATUS(ret));
	return (1);
}
