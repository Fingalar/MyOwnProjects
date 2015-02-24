/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 03:21:01 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/01 18:12:34 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"
#include "../includes/lexer.h"
#include "libft.h"

void	ft_print_tree(t_node *node, int i)
{
	int		c;

	c = 0;
	if (node != NULL)
	{
		while (c < i)
		{
			ft_putstr(" : ");
			c++;
		}
		if (node->priority != 0)
			ft_putendl((char *)node->value);
		else
			ft_putendl(((t_cmd *)node->value)->cmd);
		ft_print_tree(node->left, i + 1);
		ft_print_tree(node->right, i + 1);
	}
}
