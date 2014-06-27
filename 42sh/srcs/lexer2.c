/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 18:39:42 by jburet            #+#    #+#             */
/*   Updated: 2014/03/27 19:00:56 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/lexer.h"
#include "../includes/lexing_tools.h"
#include "../includes/error_messages.h"

int			ft_isoperator(char c)
{
	if (c == '|' || c == '&')
		return (1);
	return (0);
}

int			ft_create_token(t_list *tokens, char *lex, int type)
{
	t_elem		*elem;
	t_token		*token;
	int			i;

	i = ft_strlen(lex);
	token = ft_init_token(lex, type);
	elem = ft_list_new(token, sizeof(t_token *));
	if (tokens->first == NULL)
		ft_list_add(tokens, elem);
	else
		ft_list_push(tokens, elem);
	return (i);
}

int			ft_check_redirection(t_list *tokens, char *line, int i)
{
	if (line[i] == line[i + 1])
		i += ft_create_token(tokens, ft_strsub(line, i, 2), 2);
	else if (line[i + 1] && ft_isredirection(line[i + 1]))
	{
		ft_parse_error(line[i + 1]);
		return (-1);
	}
	else
		i += ft_create_token(tokens, ft_strsub(line, i, 1), 2);
	return (i);
}

int			ft_check_operator(t_list *tokens, char *line, int i)
{
	if (line[i + 1] && line[i + 1] == line[i])
		i += ft_create_token(tokens, ft_strsub(line, i, 2), 4);
	else if (line[i + 1] && line[i + 1] != line[i])
		i += ft_create_token(tokens, ft_strsub(line, i, 1), 3);
	else
	{
		ft_parse_error(line[i + 1]);
		return (-1);
	}
	return (i);
}

t_token		*ft_init_token(char *lex, int type)
{
	t_token		*new;

	if (!(new = malloc(sizeof(t_token *))))
		return (NULL);
	new->lexen = ft_strdup(lex);
	new->type = type;
	return (new);
}
