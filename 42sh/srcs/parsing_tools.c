/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 19:33:01 by tmertz            #+#    #+#             */
/*   Updated: 2014/05/27 15:16:01 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing_tools.h"

t_node		*ft_add_root(t_elem *elem, t_tree *tree)
{
	char	*value;

	value = ft_strdup(((t_token *)elem->value)->lexen);
	tree->root = ft_tree_new(value, ((t_token *)elem->value)->type);
	return (tree->root);
}

t_node		*ft_add_node(t_node *node, t_elem *elem, int dir)
{
	t_node		*new_node;
	char		*value;

	value = ft_strdup(((t_token *)elem->value)->lexen);
	new_node = ft_tree_new(value, ((t_token *)elem->value)->type);
	if (dir == 1)
	{
		node->right = new_node;
		new_node->parent = node;
	}
	else
	{
		node->left = new_node;
		new_node->parent = node;
	}
	return (new_node);
}

t_node		*ft_add_redirection_node(t_node *node, t_elem *elem)
{
	t_node		*new_node;
	char		*value;

	value = ft_strdup(((t_token *)elem->value)->lexen);
	new_node = ft_tree_new(value, 2);
	node->right = new_node;
	new_node->parent = node;
	return (new_node);
}

t_node		*ft_add_cmd_node(t_node *node, t_cmd *cmd, int dir)
{
	t_node		*new_node;

	new_node = ft_tree_new(cmd, 0);
	if (dir == 1)
	{
		node->right = new_node;
		new_node->parent = node;
	}
	else
	{
		node->left = new_node;
		new_node->parent = node;
	}
	return (new_node);
}

t_list		*ft_sh_split_list_r(t_elem *elem, t_list *list)
{
	t_list		*new_list;
	int			j;

	j = 0;
	new_list = NULL;
	new_list = ft_list_init(new_list);
	(elem->previous)->next = NULL;
	elem->previous = NULL;
	new_list->first = elem;
	new_list->last = list->last;
	while (elem != NULL)
	{
		j++;
		elem = elem->next;
	}
	new_list->size = j;
	return (new_list);
}
