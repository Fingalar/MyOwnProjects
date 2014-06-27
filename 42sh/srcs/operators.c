/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 15:56:38 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/26 19:05:11 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operators.h"

static int	(*g_solve_tree[5])(t_node *, t_sh *) = {ft_check_cmd,
	ft_exec_subshell, ft_make_redir, ft_check_pipe, ft_exec_operators};

int		ft_exec_operators(t_node *node, t_sh *sh)
{
	if (!ft_strcmp(node->value, "||"))
		ft_operator_or(node, sh);
	if (!ft_strcmp(node->value, "&&"))
		ft_operator_and(node, sh);
	return (0);
}

void	ft_operator_or(t_node *node, t_sh *sh)
{
	int		ret;

	ret = g_solve_tree[L_PRIORITY](node->left, sh);
	if (ret == 0)
		return ;
	if (ret != 0)
		g_solve_tree[R_PRIORITY](node->right, sh);
}

void	ft_operator_and(t_node *node, t_sh *sh)
{
	int		ret;

	ret = g_solve_tree[L_PRIORITY](node->left, sh);
	if (ret != 0)
		return ;
	if (ret == 0)
		g_solve_tree[R_PRIORITY](node->right, sh);
}
