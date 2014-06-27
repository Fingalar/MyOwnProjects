/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 16:25:09 by tmertz            #+#    #+#             */
/*   Updated: 2014/06/12 18:46:27 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexing_tools.h"

int		ft_isseparator(char c)
{
	if (c == ';')
		return (1);
	return (0);
}

int		ft_isredirection(char c)
{
	if (c == '>' || c == '<')
		return (1);
	return (0);
}

int		ft_iswhitespace(char c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	return (0);
}

int		ft_isparenthesis(char c)
{
	if (c == '(' || c == ')')
		return (1);
	return (0);
}

int		ft_isletter(char c)
{
	if (c == '\0' || ft_iswhitespace(c)
		|| ft_isoperator(c) || ft_isseparator(c)
			|| ft_isredirection(c) || ft_isparenthesis(c))
		return (0);
	return (1);
}
