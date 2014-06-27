/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 18:38:02 by jburet            #+#    #+#             */
/*   Updated: 2014/05/26 17:49:51 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grammar.h"
#include "../includes/parser.h"

int			ft_isin(char *lexen)
{
	if (!ft_strcmp(lexen, "<") || !ft_strcmp(lexen, "<<"))
		return (1);
	return (0);
}

int			ft_isout(char *lexen)
{
	if (!ft_strcmp(lexen, ">") || !ft_strcmp(lexen, ">>"))
		return (1);
	return (0);
}
