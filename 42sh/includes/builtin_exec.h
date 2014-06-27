/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exec.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyguel <nyguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 18:49:52 by nyguel            #+#    #+#             */
/*   Updated: 2014/06/06 21:08:13 by nyguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_EXEC_H
# define BUILTIN_EXEC_H
# include "structs.h"
# include "../libft/libft.h"

int		ft_exec(t_cmd *cmd, t_sh *sh);
int		ft_check_exec(char **args, t_ex *ex);
int		ft_add_fd(t_ex *ex, t_sh *sh);

#endif