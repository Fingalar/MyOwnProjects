/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 14:48:27 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 05:04:32 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# define L_PRIORITY node->left->priority
# define R_PRIORITY node->right->priority
# include "structs.h"
# include "operators.h"
# include "subshell.h"
# include "exec_cmd.h"
# include "pipe.h"
# include "redirections.h"
# include "../libft/libft.h"

void	ft_exec_line(t_tree *tree, t_sh *sh);
int		ft_simple_line(t_tree *tree, t_sh *sh);
int		ft_resolve_line(t_node *node, t_sh *sh);

#endif
