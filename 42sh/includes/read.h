/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyguel <nyguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:57:39 by nyguel            #+#    #+#             */
/*   Updated: 2014/06/13 17:51:40 by nyguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H
# include "../libft/libft.h"
# include "structs.h"

int		ft_read(t_cmd *cmd, t_sh *sh);
int		ft_check_args(char **args, t_read *opt, t_sh *sh);
int		ft_read_line(t_read *opt);

int		ft_read_arr(char **args, t_read *opt, int *cnt);
int		ft_read_fd(char **args, t_read *opt, int *cnt, t_sh *sh);
int		ft_read_k(char **args, t_read *opt, int *cnt);
int		ft_read_d(char **args, t_read *opt, int *cnt);
int		ft_read_t(char **args, t_read *opt, int *cnt);

#endif
