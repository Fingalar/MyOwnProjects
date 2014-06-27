/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 18:43:22 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/04 20:09:33 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_node		*ft_tree_new(void *value, int priority)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->value = value;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	node->priority = priority;
	return (node);
}
