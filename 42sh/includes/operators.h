/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 12:49:02 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 05:03:12 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATORS_H
# define OPERATORS_H
# include "structs.h"
# include "../libft/libft.h"
# include "redirections.h"
# include "subshell.h"
# include "parser.h"
# include "pipe.h"
# include "exec.h"

int		ft_exec_operators(t_node *node, t_sh *sh);
void	ft_operator_or(t_node *node, t_sh *sh);
void	ft_operator_and(t_node *node, t_sh *sh);

#endif
