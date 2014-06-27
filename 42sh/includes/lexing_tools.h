/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_tools.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 16:25:47 by tmertz            #+#    #+#             */
/*   Updated: 2014/02/25 16:36:06 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXING_TOOLS_H
# define LEXING_TOOLS_H

int		ft_isoperator(char c);
int		ft_isseparator(char c);
int		ft_isredirection(char c);
int		ft_iswhitespace(char c);
int		ft_isparenthesis(char c);
int		ft_isletter(char c);

#endif
