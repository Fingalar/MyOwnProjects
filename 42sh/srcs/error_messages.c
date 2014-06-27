/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 19:14:38 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 21:30:58 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/error_messages.h"

int		ft_parse_error(char c)
{
	ft_putstr_fd("Parse error near ", 2);
	if (c == '\0')
		ft_putendl_fd("\n", 2);
	else
	{
		ft_putchar_fd(c, 2);
		ft_putchar_fd('\n', 2);
	}
	return (-1);
}

int		ft_too_much_parenthesis(void)
{
	ft_putendl_fd("Too many ('s.", 2);
	return (-1);
}

int		ft_badly_placed_parenthesis(void)
{
	ft_putendl_fd("Badly placed ( )'s.", 2);
	return (-1);
}

int		ft_invalid_null_cmd(void)
{
	ft_putendl_fd("Invalid null command.", 2);
	return (-1);
}

int		ft_missing_name_redirect(void)
{
	ft_putendl_fd("Missing name for redirect.", 2);
	return (-1);
}
