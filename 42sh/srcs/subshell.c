/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 14:54:54 by tmertz            #+#    #+#             */
/*   Updated: 2014/05/27 15:08:01 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/subshell.h"

int		ft_exec_subshell(t_node *node, t_sh *sh)
{
	pid_t	process;
	char	**args;
	int		ret;
	char	*line;

	line = (char *)node->value;
	ret = 0;
	args = ft_memalloc(sizeof(char *) * 3);
	args[0] = ft_strdup("./42sh");
	args[1] = ft_strdup(line);
	process = fork();
	if (process == 0)
		execve(args[0], args, sh->env);
	else
	{
		wait(NULL);
		waitpid(process, 0, WIFEXITED(ret));
	}
	return (ret);
}
