/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 15:17:47 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 05:10:34 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSHELL_H
# define SUBSHELL_H
# include "../libft/libft.h"
# include <sys/wait.h>
# include <unistd.h>
# include "structs.h"

int		ft_exec_subshell(t_node *node, t_sh *sh);

#endif
