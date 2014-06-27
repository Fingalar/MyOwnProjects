/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-lacr <pde-lacr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 17:02:24 by pde-lacr          #+#    #+#             */
/*   Updated: 2014/03/27 02:56:26 by pde-lacr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CURSOR_H
# define CURSOR_H

# include <stdlib.h>
# include "../libft/libft.h"
# include <termios.h>
# include <termcap.h>
# include <term.h>

void		ft_beginend(char c, char *line, int *i);
int			ft_wordmove(char c, char *line, int *i);
char		*ft_handlekey(char *key, char *line, int *i, t_sh *sh);
void		ft_delchar(char *line, int *i);
char		*ft_insertchar(char c, char *line, int *i);

#endif
