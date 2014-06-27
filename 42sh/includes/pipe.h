/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 13:27:35 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 05:03:02 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H
# include "structs.h"
# include "../libft/libft.h"
# include <unistd.h>
# include "parser.h"
# include <sys/wait.h>
# include "exec.h"
# include "exec_cmd.h"
# include "subshell.h"
# include "redirections.h"

int		ft_check_pipe(t_node *node, t_sh *sh);
int		ft_pipe(t_node *node, t_sh *sh, int i);

#endif
