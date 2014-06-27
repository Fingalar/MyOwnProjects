/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:57:39 by tmertz            #+#    #+#             */
/*   Updated: 2014/06/20 16:40:19 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H
# include "../libft/libft.h"
# include "structs.h"
# include <unistd.h>
# include <sys/stat.h>
# include "parser.h"

int		ft_change_directory(t_sh *sh, t_cmd *cmd);
int		ft_update_env(t_sh *sh, char *path);
int		ft_special_cd(t_sh *sh, char *spec);
int		ft_getenv_id(char **environ, char *str, int size);
int		check_if_nullvar2(t_sh *sh, int i, int j);
int		check_if_nullvar1(t_sh *sh, int i, int k);

#endif
