/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 14:58:20 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 05:04:09 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECHO_H
# define ECHO_H
# include "../libft/libft.h"
# include "structs.h"

int		ft_echo(t_cmd *cmd);
void	ft_check_next_letter(char **args, int i, int j);

#endif
