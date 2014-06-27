/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyguel <nyguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 14:07:08 by tmertz            #+#    #+#             */
/*   Updated: 2014/06/19 16:00:10 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/lexer.h"
#include "../includes/lexing_tools.h"
#include "../includes/error_messages.h"

t_list		*ft_lexer(char *line, t_sh *sh)
{
	int		i;
	t_list	*tokens;

	i = 0;
	tokens = NULL;
	tokens = ft_list_init(tokens);
	while (line[i] != '\0')
	{
		if (ft_iswhitespace(line[i]))
			i++;
		else if (ft_isseparator(line[i]))
			i += ft_create_token(tokens, ft_strsub(line, i, 1), 5);
		else if (ft_isparenthesis(line[i]))
			i = ft_add_subshell(tokens, line, i);
		else if (ft_isredirection(line[i]))
			i = ft_check_redirection(tokens, line, i);
		else if (ft_isoperator(line[i]))
			i = ft_check_operator(tokens, line, i);
		else
			i = ft_add_word(tokens, line, i, sh);
		if (i == -1)
			return (NULL);
	}
	return (tokens);
}

void		quoted_word(t_word *w, char *line, int *i, t_sh *sh)
{
	while (line[*i] != '\0' && w->status == 1)
	{
		if (line[*i] == '$' && w->quote == '"')
		{
			if (check_if_variable(&w, line, i, sh))
				w->result = ft_strjoin(w->result, w->var);
			else
			{
				ft_putstr_fd(w->var, 2);
				ft_putstr_fd(": Undefined Variable", 2);
			}
		}
		else if (line[*i] == '\\' && line[*i + 1] && line[*i + 1] == w->quote)
		{
			w->result[w->k++] = line[*i + 1];
			*i += 2;
		}
		else if (line[*i] == w->quote)
		{
			w->status = 0;
			*i += 1;
		}
		else
			w->result[w->k++] = line[(*i)++];
	}
}

void		simple_word(t_word *w, char *line, int *i, t_sh *sh)
{
	while (ft_isletter(line[*i]) && w->status == 0)
	{
		if (line[*i] == '$')
		{
			if (check_if_variable(&w, line, i, sh))
				w->result = ft_strjoin(w->result, w->var);
			else
			{
				ft_putstr_fd(w->var, 2);
				ft_putstr_fd(": Undefined Variable", 2);
			}
		}
		else if (line[*i] == '\\' && line[*i + 1])
		{
			w->result[w->k++] = line[*i + 1];
			*i += 2;
		}
		else if (line[*i] == '"' || line[*i] == '\'')
		{
			w->quote = line[(*i)++];
			w->status = 1;
		}
		else
			w->result[w->k++] = line[(*i)++];
	}
}

int			ft_add_word(t_list *tokens, char *line, int i, t_sh *sh)
{
	t_word	w;
	int		j;

	w.status = 0;
	w.k = 0;
	w.result = ft_memalloc(ft_strlen(line) - i + 1);
	if ((ft_strchr(line, '*') || ft_strchr(line, '?')) && (j = i))
	{
		while (line[j] && !(ft_iswhitespace(line[j])))
			j++;
		wild_card(ft_strsub(line, i, j - i), tokens);
		return (i + j);
	}
	while (line[i] != '\0' && !(ft_iswhitespace(line[i]) && w.status == 0)
		&& (ft_isletter(line[i]) || w.status == 1))
	{
		if (w.status == 1)
			quoted_word(&w, line, &i, sh);
		else if (w.status == 0)
			simple_word(&w, line, &i, sh);
	}
	if (w.status == 1)
		return (ft_unmatched_quote(w.quote));
	ft_create_token(tokens, w.result, 0);
	return (i);
}

int			ft_add_subshell(t_list *tokens, char *line, int i)
{
	int		j;
	int		flag;

	j = ++i;
	flag = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '(')
			flag++;
		else if (line[i] == ')' && flag != 0)
			flag--;
		else if (line[i] == ')' && flag == 0)
		{
			ft_create_token(tokens, ft_strsub(line, j, i - j), 1);
			i++;
			return (i);
		}
		i++;
	}
	if (line[i] == '\0')
	{
		ft_too_much_parenthesis();
		return (-1);
	}
	return (i);
}
