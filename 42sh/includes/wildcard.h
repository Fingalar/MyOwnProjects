/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:03:43 by jburet            #+#    #+#             */
/*   Updated: 2014/03/27 23:05:07 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_H
# define WILDCARD_H
# include "../Libft/libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "lexer.h"
# include "match.h"

int		is_point(char *prev);
int		end_point(char *prev);
int		card2(char *s, char *prev, int type, t_list *tokens);
void	card(char *s, char *p, int type, t_list *tokens);
void	wild_card(char *line, t_list *tokens);

#endif
