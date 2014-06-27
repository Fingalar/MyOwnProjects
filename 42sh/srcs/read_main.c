/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyguel <nyguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 18:59:21 by nyguel            #+#    #+#             */
/*   Updated: 2014/06/13 20:39:02 by nyguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read.h"
#include "../includes/add_var.h"
#include <stdlib.h>
#define ERR "read: usage -[se], -u <fd>, -k <nb>, -d <nb>, -t <nb>, -a <name>"

static t_read	*ft_init_opt(void)
{
	t_read	*opt;

	opt = (t_read *)malloc(sizeof(t_read));
	opt->var_line = ft_strdup("REPLY");
	opt->var_arr = NULL;
	opt->s = 0;
	opt->e = 0;
	opt->a = 0;
	opt->u = 0;
	opt->k = -1;
	opt->d = '\n';
	opt->t = 3600;
	return (opt);
}

static void		ft_free_opt(t_read *opt)
{
	if (opt->var_line != NULL)
		free(opt->var_line);
	if (opt->var_arr != NULL)
		free(opt->var_arr);
	free(opt);
}

static void		ft_error(int i)
{
	if (i == 2)
		ft_putendl_fd("read: invalid opt", 2);
	else if (i > 128)
		ft_putendl_fd("read: timout", 2);
	else if (i != 0)
		ft_putendl_fd("read: invalid fd with -u", 2);
	ft_putendl_fd(ERR, 2);
}

static void		ft_treat_read(t_read *opt, t_sh *sh)
{
	if (opt->var_arr == NULL)
		add_var_to_env(sh, opt->var_line, ft_strdup(opt->line), 0);
	else
		add_var_to_env(sh, opt->var_line, ft_strsplit(opt->line, ' '), 1);
}

int				ft_read(t_cmd *cmd, t_sh *sh)
{
	int		test;
	t_read	*opt;

	opt = ft_init_opt();
	test = ft_check_args(&cmd->args[1], opt, sh);
	if (test == 0)
		test = ft_read_line(opt);
	if (test != 0)
		ft_error(test);
	else
		ft_treat_read(opt, sh);
	ft_free_opt(opt);
	return (test);
}
