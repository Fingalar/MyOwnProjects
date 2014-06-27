/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 16:24:17 by tmertz            #+#    #+#             */
/*   Updated: 2014/05/27 15:20:07 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

t_elem		*ft_find_highest_priority(t_list *tokens, int priority)
{
	t_elem		*elem;

	elem = tokens->first;
	if (priority == 1)
		return (NULL);
	if (priority == 2)
		return (ft_find_farest_redirection(elem));
	else
	{
		while (elem != NULL && ((t_token *)elem->value)->type != priority)
			elem = elem->next;
		if (elem == NULL)
			return (ft_find_highest_priority(tokens, --priority));
	}
	return (elem);
}

void		ft_add_redirections_to_tree(t_tree *tree, t_list *tokens
									, t_node *node, t_elem *elem)
{
	t_list		*list_l;
	t_list		*list_r;

	ft_add_redirection_node(node, elem->next);
	ft_list_delone(tokens, elem->next);
	if (elem->previous)
	{
		list_l = ft_sh_split_list_l(elem->previous, tokens);
		ft_parser_make_tree(tree, list_l, node, 0);
	}
	if (elem->next)
	{
		list_r = ft_sh_split_list_r(elem->next, tokens);
		ft_parser_make_tree(tree, list_r, node, 0);
	}
}

void		ft_add_others_to_tree(t_tree *tree, t_list *tokens
									, t_node *node, int dir)
{
	t_elem		*elem;
	t_list		*list_r;
	t_list		*list_l;

	elem = ft_find_highest_priority(tokens, 5);
	if (node == NULL)
		node = ft_add_root(elem, tree);
	else
		node = ft_add_node(node, elem, dir);
	if (((t_token *)elem->value)->type == 2)
		ft_add_redirections_to_tree(tree, tokens, node, elem);
	else
	{
		if (elem->previous)
		{
			list_l = ft_sh_split_list_l(elem->previous, tokens);
			ft_parser_make_tree(tree, list_l, node, 0);
		}
		if (elem->next)
		{
			list_r = ft_sh_split_list_r(elem->next, tokens);
			ft_parser_make_tree(tree, list_r, node, 1);
		}
	}
}

void		ft_add_cmd_to_tree(t_tree *tree, t_list *tokens,
									t_node *node, int dir)
{
	if (tree->root == NULL)
	{
		if (((t_token*)tokens->first->value)->type == 0)
			ft_tree_add(tree, ft_tree_new((void *)ft_create_cmd(tokens), 0));
		else
			ft_tree_add(tree, ft_tree_new
					(ft_strdup(((t_token *)tokens->first->value)->lexen), 1));
	}
	else if (tokens->size == 1 && ((t_token*)tokens->first->value)->type == 1)
		ft_add_node(node, tokens->first, dir);
	else
		ft_add_cmd_node(node, ft_create_cmd(tokens), dir);
}

t_cmd		*ft_create_cmd(t_list *tokens)
{
	t_cmd	*cmd;
	t_elem	*cur;
	int		i;

	cur = tokens->first;
	cmd = ft_memalloc(sizeof(t_cmd));
	cmd->args = ft_memalloc(sizeof(char *) * (tokens->size + 1));
	cmd->cmd = ft_strdup(((t_token *)cur->value)->lexen);
	cmd->args[0] = ft_strdup(((t_token *)cur->value)->lexen);
	cur = cur->next;
	i = 1;
	while (cur != NULL)
	{
		cmd->args[i++] = ft_strdup(((t_token *)cur->value)->lexen);
		cur = cur->next;
	}
	return (cmd);
}
