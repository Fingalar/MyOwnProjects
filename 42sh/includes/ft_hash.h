/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaublan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 18:13:42 by cmaublan          #+#    #+#             */
/*   Updated: 2014/03/27 05:18:02 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASH_H
# define FT_HASH_H
# define SIZE_TABLE 32768
# include "../libft/libft.h"
# include "structs.h"

void			ft_hash(t_sh *sh, char *path, char *cmd);
void			record_paths(char *path, char *cmd, t_list **hash);
unsigned long	get_hash(char *str);
t_list			*record_path(char *path, t_list *hash);
char			*get_path_cmd(t_sh *sh, char *cmd);
int				del_path_cmd(t_sh *sh, char *cmd);
int				add_path_cmd(t_sh *sh, char *cmd);

#endif
