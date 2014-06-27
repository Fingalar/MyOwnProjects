/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaublan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 11:19:35 by cmaublan          #+#    #+#             */
/*   Updated: 2014/05/12 15:04:39 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_env.h"
#include "../libft/libft.h"
#include <stdlib.h>

int			ft_setenv(t_sh *sh, t_cmd *cmd)
{
	if (cmd)
	{
		if (!cmd->args[1])
			ft_printenv(sh);
		else if (cmd->args[1] && cmd->args[2] && cmd->args[1][0] != '-')
			return (ft_setvar(sh, cmd->args[1], cmd->args[2]));
		else if (cmd->args[1] && !cmd->args[2] && cmd->args[1][0] != '-')
			return (ft_setvar(sh, cmd->args[1], NULL));
		else
			return (-1);
	}
	return (-1);
}

int			ft_setvar(t_sh *sh, char *name, char *value)
{
	int		i;

	i = 0;
	if (ft_get_var(sh, name) != NULL)
	{
		while (sh->env[i] != NULL)
		{
			if (ft_strncmp(sh->env[i], name, ft_strlen(name)) == 0)
			{
				ft_strdel(&sh->env[i]);
				sh->env[i] = ft_strjoin(name, "=");
				sh->env[i] = ft_strjoin(sh->env[i], value);
				return (0);
			}
			i++;
		}
	}
	else
	{
		if (!ft_add_var(sh, name, value))
			return (0);
	}
	return (-1);
}

int			ft_add_var(t_sh *sh, char *name, char *value)
{
	int		i;
	char	**new_env;

	i = 0;
	sh->env_size += 1;
	new_env = (char**)ft_memalloc(sizeof(char*) * sh->env_size);
	if (!new_env)
		return (-1);
	while (sh->env[i] != NULL)
	{
		new_env[i] = ft_strdup(sh->env[i]);
		free(sh->env[i]);
		i++;
	}
	free(sh->env);
	new_env[i] = ft_strjoin(name, "=");
	new_env[i] = ft_strjoin(new_env[i], value);
	sh->env = new_env;
	return (0);
}
