/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 04:50:50 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 05:15:38 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H
# define NAME_CONFIG ".42shrc"
# include "structs.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

void		create_file_config(t_sh *sh);
char		*alias(t_sh *sh, char *line);

#endif
