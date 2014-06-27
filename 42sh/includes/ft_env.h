/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyguel <nyguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:24:00 by tmertz            #+#    #+#             */
/*   Updated: 2014/06/22 19:28:45 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENV_H
# define FT_ENV_H
# include "../libft/libft.h"
# include "structs.h"

char			*ft_getenv(t_sh *sh, const char *name);
t_sh			*ft_make_sh(t_sh *sh, char **environ);
char			*ft_get_var(t_sh *sh, char *name);
void			ft_set_paths(t_sh *sh);
void			ft_printenv(t_sh *sh);
int				ft_setenv(t_sh *sh, t_cmd *cmd);
int				ft_setvar(t_sh *sh, char *name, char *value);
int				ft_add_var(t_sh *sh, char *name, char *value);
int				ft_unsetenv(t_sh *sh, t_cmd *cmd);
int				ft_unsetvar(t_sh *sh, char *name);
int				ft_env(t_sh *sh, t_cmd *cmd);
int				ft_export(t_sh *sh, char *name);
void			ft_cpy_pwd(t_sh *sh);
void			ft_set_loc(t_sh *sh);

#endif
