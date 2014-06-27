/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 08:17:12 by hvillain          #+#    #+#             */
/*   Updated: 2014/05/26 20:41:32 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grammar.h"
#include "../includes/parser.h"

int			ft_grammar_operators(t_elem *cur, int *status, int *redir_i
									, int *redir_o)
{
	if (ft_strcmp(((t_token *)cur->value)->lexen, "&&")
			|| (EX_P && cur->previous != NULL && TYPE_P != 3 && TYPE_P != 4))
	{
		if (*status == 0)
			return (ft_invalid_null_cmd());
		if (*redir_o > 1)
			return (ft_anbiguous_redirect_out());
		if (*redir_i > 1)
			return (ft_anbiguous_redirect_in());
		ft_check_right_side(cur, status, redir_i, redir_o);
		if (*status == 0)
			return (ft_invalid_null_cmd());
		if (*redir_o > 1)
			return (ft_anbiguous_redirect_out());
		if (*redir_i > 1)
			return (ft_anbiguous_redirect_in());
	}
	return (0);
}

int			ft_grammar_separators(t_elem *cur, int *status,
					int *redir_i, int *redir_o)
{
	if (*status == 0 || cur->next == NULL)
		return (ft_parse_error(';'));
	if (*redir_o > 1)
		return (ft_anbiguous_redirect_out());
	if (*redir_i > 1)
		return (ft_anbiguous_redirect_in());
	*status = 0;
	*redir_o = 0;
	*redir_i = 0;
	return (0);
}

int			check_grammar(t_elem *cur, int *status, int *redir_i, int *redir_o)
{
	int		good;

	good = 0;
	if (TYPE == 0)
		good = ft_grammar_identifier(cur, status);
	else if (TYPE == 1)
		good = ft_grammar_subshells(cur, status);
	else if (TYPE == 2)
		good = ft_grammar_redirections(cur, redir_i, redir_o);
	else if (TYPE == 3)
		good = ft_grammar_pipes(cur, status, redir_i, redir_o);
	else if (TYPE == 4)
		good = ft_grammar_operators(cur, status, redir_i, redir_o);
	else if (TYPE == 5)
		good = ft_grammar_separators(cur, status, redir_i, redir_o);
	return (good);
}

int			ft_grammar(t_list *tokens)
{
	t_elem		*cur;
	int			good;
	int			status;
	int			redir_o;
	int			redir_i;

	status = 0;
	redir_o = 0;
	redir_i = 0;
	good = 0;
	cur = tokens->first;
	while (cur != NULL)
	{
		good = check_grammar(cur, &status, &redir_i, &redir_o);
		if (good == -1)
			return (0);
		cur = cur->next;
	}
	return (1);
}
