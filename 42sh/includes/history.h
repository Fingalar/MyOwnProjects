/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 20:51:20 by jburet            #+#    #+#             */
/*   Updated: 2014/03/27 15:00:21 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H
# include "structs.h"
# include "ft_env.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# define NAME_HIST 		".42sh_history"
# define KEY_UP			1
# define KEY_DOWN		2

void		save_cmd(char *cmd, t_sh *sh);
t_hist		*recup_hist(t_sh *sh);
char		*get_hist(int dir, t_sh *sh);
int			move_history(char *read, t_sh *sh);

#endif
