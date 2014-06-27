/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 14:38:52 by tmertz            #+#    #+#             */
/*   Updated: 2014/05/24 18:21:47 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/exec.h"
#include <stdio.h>

static int		(*g_solve_tree[6])(t_node *, t_sh *) = {ft_check_cmd,
	ft_exec_subshell, ft_make_redir, ft_check_pipe, ft_exec_operators,
	ft_resolve_line};

void	ft_exec_line(t_tree *tree, t_sh *sh)
{
	pid_t	process;

	if (sh == NULL)
		return ;
	if (ft_simple_line(tree, sh))
		return ;
	else
	{
		process = fork();
		if (process == 0)
		{
			ft_resolve_line(tree->root, sh);
			exit(0);
		}
		else
			wait(NULL);
	}
}

int		ft_simple_line(t_tree *tree, t_sh *sh)
{
	if (tree->root->left == NULL && tree->root->right == NULL)
	{
		if (tree->root->priority <= 1)
			g_solve_tree[tree->root->priority](tree->root, sh);
		return (1);
	}
	else
		return (0);
}

int		ft_resolve_line(t_node *node, t_sh *sh)
{
	if (node->priority == 5)
	{
		g_solve_tree[L_PRIORITY](node->left, sh);
		g_solve_tree[R_PRIORITY](node->right, sh);
	}
	else
		g_solve_tree[node->priority](node, sh);
	return (0);
}
