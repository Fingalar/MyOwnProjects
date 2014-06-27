/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyguel <nyguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 19:02:16 by nyguel            #+#    #+#             */
/*   Updated: 2014/06/06 20:53:43 by nyguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read.h"

static int	ft_set_opt(char **args, t_read *opt, int *cnt, t_sh *sh)
{
	int		test;

	test = 0;
	if (args[*cnt][1] == 's')
		opt->s = 1;
	else if (args[*cnt][1] == 'e')
		opt->e = 1;
	else if (args[*cnt][1] == 'a' && ft_strcmp(opt->var_line, "REPLY") == 0
		&& opt->var_arr == NULL && args[*cnt + 1] && args[*cnt + 1][0] != '-')
		test = ft_read_arr(args, opt, cnt);
	else if (args[*cnt][1] == 'u' && args[*cnt + 1] && args[*cnt + 1][0] != '-')
		test = ft_read_fd(args, opt, cnt, sh);
	else if (args[*cnt][1] == 'k' && args[*cnt + 1] && args[*cnt + 1][0] != '-')
		test = ft_read_k(args, opt, cnt);
	else if (args[*cnt][1] == 'd' && args[*cnt + 1] && args[*cnt + 1][0] != '-')
		test = ft_read_d(args, opt, cnt);
	else if (args[*cnt][1] == 't' && args[*cnt + 1] && args[*cnt + 1][0] != '-')
		test = ft_read_t(args, opt, cnt);
	else
		test = 2;
	return (test);
}

static int	ft_set_name(char *name, t_read *opt)
{
	opt->var_line = ft_strdup(name);
	return (0);
}

int			ft_check_args(char **args, t_read *opt, t_sh *sh)
{
	int		i;
	int		test;

	test = 0;
	i = -1;
	while (args[++i] && test == 0)
	{
		if (args[i][0] == '-' && args[i][1] != '\0' && !args[i][2])
			test = ft_set_opt(args, opt, &i, sh);
		else if (opt->var_arr == NULL && ft_strcmp(opt->var_line, "REPLY") == 0)
			test = ft_set_name(args[i], opt);
		else
			test = 2;
	}
	return (test);
}
