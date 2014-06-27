/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 14:56:44 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 05:09:53 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H
# include "structs.h"
# include <fcntl.h>
# include <unistd.h>
# include "exec.h"
# include "exec_cmd.h"
# include "subshell.h"
# include "../libft/libft.h"

int		ft_make_redir(t_node *node, t_sh *sh);
void	reinit_in_out(t_sh *sh);

#endif
