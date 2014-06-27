/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 00:41:41 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 21:23:45 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAMMAR_H
# define GRAMMAR_H
# define TYPE ((t_token *)cur->value)->type
# define TYPE_P ((t_token *)cur->previous->value)->type
# define TYPE_N ((t_token *)cur->next->value)->type
# define EX_N cur->next
# define EX_P cur->previous
# include "../libft/libft.h"
# include "lexer.h"
# include "error_messages.h"

int			ft_grammar_separators(t_elem *cur,
				int *status, int *redir_i, int *redir_o);
int			ft_grammar_operators(t_elem *cur, int *status, int *redir_i,
									int *redir_o);
void		ft_check_right_side(t_elem *cur, int *status, int *redir_i,
									int *redir_o);
int			ft_grammar_redirections(t_elem *cur, int *redir_i, int *redir_o);
int			ft_grammar_subshells(t_elem *cur,
									int *status);
int			ft_grammar_identifier(t_elem *cur, int *status);
int			ft_grammar_pipes(t_elem *cur, int *status, int *redir_i,
									int *redir_o);
int			ft_grammar(t_list *tokens);
int			ft_isin(char *lexen);
int			ft_isout(char *lexen);

#endif
