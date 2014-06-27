/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 14:25:02 by tmertz            #+#    #+#             */
/*   Updated: 2014/06/06 16:32:38 by cmaublan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/echo.h"

int			ft_echo(t_cmd *cmd)
{
	int		flag;
	int		i;
	int		j;

	flag = 0;
	i = 0;
	if (cmd->args[1] && cmd->args[1][0] == '-')
		i = (cmd->args[1][1] == 'n') ? ++flag : i;
	if (cmd->args[1])
	{
		while (cmd->args[++i] && (j = -1))
		{
			while (cmd->args[i] && cmd->args[i][++j])
			{
				if (cmd->args[i][j] == '\\')
					ft_check_next_letter(cmd->args, i, ++j);
				else
					ft_putchar(cmd->args[i][j]);
			}
			ft_putchar(' ');
		}
	}
	if (flag != 1)
		ft_putchar('\n');
	return (0);
}

void		ft_check_next_letter(char **args, int i, int j)
{
	if (args[i][j] == 'a')
		ft_putchar('\a');
	else if (args[i][j] == 'b')
		ft_putchar('\b');
	else if (args[i][j] == 'f')
		ft_putchar('\f');
	else if (args[i][j] == 'n')
		ft_putchar('\n');
	else if (args[i][j] == 'r')
		ft_putchar('\r');
	else if (args[i][j] == 't')
		ft_putchar('\t');
	else if (args[i][j] == 'v')
		ft_putchar('\v');
	else
	{
		ft_putchar('\\');
		ft_putchar(args[i][j]);
	}
}
