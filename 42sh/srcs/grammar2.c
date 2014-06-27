/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 18:36:06 by jburet            #+#    #+#             */
/*   Updated: 2014/05/26 18:38:18 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grammar.h"
#include "../includes/parser.h"

int			ft_grammar_identifier(t_elem *cur, int *status)
{
	if (!EX_P || TYPE_P != 1)
		*status = 1;
	return (0);
}

int			ft_grammar_subshells(t_elem *cur, int *status)
{
	if ((EX_P && TYPE_P == 0) || (EX_N && TYPE_N == 0))
		return (ft_badly_placed_parenthesis());
	if (EX_P && EX_N && (TYPE_P == 1 || TYPE_N == 1))
		return (ft_too_much_parenthesis());
	else
		*status = 1;
	return (0);
}

int			ft_grammar_redirections(t_elem *cur, int *redir_i, int *redir_o)
{
	if (!EX_N || TYPE_N != 0)
		return (ft_missing_name_redirect());
	if (ft_isin(((t_token *)cur->value)->lexen))
		(*redir_i)++;
	if (ft_isout(((t_token *)cur->value)->lexen))
		(*redir_o)++;
	return (0);
}

int			ft_grammar_pipes(t_elem *cur, int *status
								, int *redir_i, int *redir_o)
{
	if (*status == 0)
		return (ft_invalid_null_cmd());
	if (*redir_o >= 1)
		return (ft_anbiguous_redirect_out());
	if (*redir_i > 1)
		return (ft_anbiguous_redirect_in());
	ft_check_right_side(cur, status, redir_i, redir_o);
	if (*status == 0)
		return (ft_invalid_null_cmd());
	if (*redir_o > 1)
		return (ft_anbiguous_redirect_out());
	if (*redir_i >= 1)
		return (ft_anbiguous_redirect_in());
	*redir_o = 0;
	*redir_i = 0;
	return (0);
}

void		ft_check_right_side(t_elem *cur, int *status
									, int *redir_i, int *redir_o)
{
	t_elem	*buffer;

	buffer = cur;
	*status = 0;
	*redir_o = 0;
	*redir_i = 0;
	cur = cur->next;
	while (cur != NULL && TYPE != 4 && TYPE != 3)
	{
		if (EX_P && (((TYPE == 0 && TYPE_P != 2) || TYPE == 1)))
			*status = 1;
		if (ft_isin(((t_token *)cur->value)->lexen))
			(*redir_i)++;
		if (ft_isout(((t_token *)cur->value)->lexen))
			(*redir_o)++;
		cur = cur->next;
	}
	cur = buffer;
}
