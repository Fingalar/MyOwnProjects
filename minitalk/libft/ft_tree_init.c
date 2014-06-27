/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 18:14:37 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/18 18:30:11 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_tree		*ft_tree_init(t_tree *tree)
{
	tree = malloc(sizeof(t_tree *));
	tree->root = NULL;
	tree->nb_nodes = 0;
	return (tree);
}
