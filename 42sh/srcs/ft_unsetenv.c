/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaublan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 11:18:18 by cmaublan          #+#    #+#             */
/*   Updated: 2014/03/27 21:36:42 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_env.h"
#include "../libft/libft.h"
#include <stdlib.h>

int			ft_unsetenv(t_sh *sh, t_cmd *cmd)
{
	if (cmd->args[1] && !cmd->args[2] && cmd->args[1][0] != '-')
		return (ft_unsetvar(sh, cmd->args[1]));
	return (1);
}

int			ft_unsetvar(t_sh *sh, char *name)
{
	int		i;

	i = 0;
	while (sh->env[i])
	{
		if (ft_strncmp(sh->env[i], name, ft_strlen(name)) == 0)
		{
			while (sh->env[i] && sh->env[i + 1])
			{
				free(sh->env[i]);
				sh->env[i] = ft_strdup(sh->env[i + 1]);
				i++;
			}
			sh->env[i] = NULL;
		}
		i++;
	}
	return (0);
}
