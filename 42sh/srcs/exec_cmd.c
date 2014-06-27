/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyguel <nyguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 16:10:00 by tmertz            #+#    #+#             */
/*   Updated: 2014/06/22 19:32:59 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/exec_cmd.h"
#include "../includes/ft_env.h"
#include "../includes/config.h"

int		ft_check_if_builltin(char *cmd)
{
	if (!ft_strcmp(cmd, "cd"))
		return (1);
	if (!ft_strcmp(cmd, "exit"))
		return (2);
	if (!ft_strcmp(cmd, "env"))
		return (3);
	if (!ft_strcmp(cmd, "setenv") || !ft_strcmp(cmd, "import"))
		return (4);
	if (!ft_strcmp(cmd, "unsetenv") || !ft_strcmp(cmd, "export"))
		return (5);
	if (!ft_strcmp(cmd, "echo"))
		return (6);
	if (!ft_strcmp(cmd, "read"))
		return (7);
	if (!ft_strcmp(cmd, "exec"))
		return (8);
	return (0);
}

int		ft_exec_builltin(t_cmd *cmd, t_sh *sh, int nbr)
{
	if (nbr == 8)
		return (ft_exec(cmd, sh));
	if (nbr == 7)
		return (ft_read(cmd, sh));
	if (nbr == 6)
		return (ft_echo(cmd));
	if (nbr == 2)
		return (ft_exit(cmd));
	if (nbr == 1)
		return (ft_change_directory(sh, cmd));
	if (nbr == 5)
		return (ft_unsetenv(sh, cmd));
	if (nbr == 4)
		return (ft_setenv(sh, cmd));
	if (nbr == 3)
		ft_env(sh, cmd);
	return (0);
}

char	*get_cmd(t_sh *sh, t_cmd *cmd)
{
	int		i;
	char	**pathes;

	i = -1;
	pathes = NULL;
	while (sh->env[++i] != NULL)
	{
		if (!ft_strncmp("PATH=", sh->env[i], 5))
			pathes = ft_strsplit(sh->env[i], ':');
	}
	if (pathes == NULL)
		pathes = ft_strsplit(sh->path, ':');
	i = -1;
	while (pathes[++i] != NULL)
	{
		if (access(ft_strjoin(ft_strjoin(pathes[i], "/"), cmd->cmd), X_OK) == 0)
			return (ft_strjoin(ft_strjoin(pathes[i], "/"), cmd->cmd));
	}
	return (NULL);
}

int		ft_check_cmd(t_node *node, t_sh *sh)
{
	char	*path;
	t_cmd	*cmd;
	int		nbr;

	cmd = (t_cmd *)node->value;
	if (ft_strchr(((t_cmd *)node->value)->cmd, '='))
		return (assign_variable(sh, node));
	if ((nbr = ft_check_if_builltin(cmd->cmd)) != 0)
		return (ft_exec_builltin(cmd, sh, nbr));
	if (ft_strchr(cmd->cmd, '/') != NULL)
	{
		if (access(cmd->cmd, X_OK) == 0)
			return (ft_exec_cmd(cmd, cmd->cmd, sh));
		else
			return (0);
	}
	else if ((path = get_cmd(sh, cmd)) == NULL)
		return (ft_cmd_not_found(cmd->cmd));
	else
	{
		if (access(path, X_OK) == 0)
			return (ft_exec_cmd(cmd, path, sh));
		else
			return (0);
	}
}

int		ft_exec_cmd(t_cmd *cmd, char *path, t_sh *sh)
{
	pid_t	process;
	int		ret;

	ret = 0;
	process = fork();
	if (process == 0)
	{
		execve(path, cmd->args, sh->env);
		exit(1);
	}
	else
		waitpid(process, &ret, 0);
	if (WIFEXITED(ret))
		return (WEXITSTATUS(ret));
	return (1);
}
