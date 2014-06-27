/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyguel <nyguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 14:26:53 by tmertz            #+#    #+#             */
/*   Updated: 2014/06/22 19:32:57 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_CMD_H
# define EXEC_CMD_H
# include "structs.h"
# include "echo.h"
# include "parser.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include "ft_hash.h"
# include "builtins.h"
# include "cd.h"
# include "read.h"
# include "builtin_exec.h"
# include "add_var.h"

int		ft_check_cmd(t_node *node, t_sh *sh);
int		ft_exec_cmd(t_cmd *cmd, char *path, t_sh *sh);
int		ft_check_if_builltin(char *cmd);
int		ft_exec_builltin(t_cmd *cmd, t_sh *sh, int nbr);
char	*get_cmd(t_sh *sh, t_cmd *cmd);

#endif
