/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 18:50:33 by tmertz            #+#    #+#             */
/*   Updated: 2014/02/09 20:41:24 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_tree_add(t_tree *tree, t_node *node)
{
	t_node		*buff;

	buff = tree->root;
	if (buff == NULL)
		tree->root = node;
	else
	{
		while (node->parent == NULL)
		{
			if (buff->left == NULL)
				ft_tree_add_wich_way(buff, node, 1);
			else if (buff->left->priority > node->priority)
				buff = buff->left;
			else if (buff->right == NULL)
				ft_tree_add_wich_way(buff, node, 0);
			else
				buff = buff->right;
		}
	}
}

void		ft_tree_add_wich_way(t_node *buffer, t_node *node, int way)
{
	if (way == 1)
	{
		buffer->left = node;
		node->parent = buffer;
		buffer = node;
	}
	else
	{
		buffer->right = node;
		node->parent = buffer;
		buffer = node;
	}
}
