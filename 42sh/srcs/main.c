/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaublan <cmaublan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 19:34:49 by cmaublan          #+#    #+#             */
/*   Updated: 2014/06/13 17:03:34 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_env.h"
#include "../includes/grammar.h"
#include "../includes/parser.h"
#include "../includes/ft_hash.h"
#include "../includes/history.h"
#include "../includes/signals.h"
#include <term.h>
#include <cursor.h>

int			ft_display_prompt(t_sh *sh)
{
	char	*user;
	char	*pwd;
	char	*home;

	user = ft_get_var(sh, "USER");
	pwd = ft_get_var(sh, "PWD");
	home = ft_get_var(sh, "HOME");
	sh = (void *)sh;
	if (user)
	{
		ft_putstr(user);
		ft_putchar(':');
	}
	if (pwd)
	{
		if (home && !ft_strncmp(pwd, home, ft_strlen(home)))
			ft_putstr(ft_strjoin("~", pwd + ft_strlen(home)));
		else
			ft_putstr(pwd);
		ft_putchar(' ');
	}
	ft_putstr("$> ");
	return (0);
}

char		*ft_sendline(char *line, int *i, t_sh *sh)
{
	t_list	*list;
	t_tree	*tree;

	tree = NULL;
	line[ft_strlen(line)] = '\0';
	ft_putchar('\n');
	list = ft_lexer(line, sh);
	if (list != NULL && list->size != 0)
	{
		save_cmd(line, sh);
		if (ft_grammar(list))
		{
			tree = ft_parser(list);
			ft_unset_term();
			ft_exec_line(tree, sh);
			ft_set_term();
		}
	}
	*i = 0;
	line = ft_strnew(2);
	ft_display_prompt(sh);
	return (line);
}

char		*ft_read_char(t_sh *sh, char *line)
{
	static int	i = 0;
	char		read_char[5];

	read_char[0] = 0;
	read_char[1] = 0;
	read_char[2] = 0;
	read_char[3] = 0;
	read_char[4] = 0;
	read(0, read_char, 4);
	if (read_char[1])
		line = ft_handlekey(read_char, line, &i, sh);
	else if (read_char[0] == 10)
		line = ft_sendline(line, &i, sh);
	else if (read_char[0] == 127)
		ft_delchar(line, &i);
	else if (read_char[0] != 4 && read_char[0] != 9)
		line = ft_insertchar(read_char[0], line, &i);
	return (line);
}

int			ft_exec_args(char *line, t_sh *sh)
{
	t_list	*list;
	t_tree	*tree;

	list = ft_lexer(line, sh);
	if (list != NULL && list->size != 0)
	{
		if (ft_grammar(list))
		{
			tree = ft_parser(list);
			ft_exec_line(tree, sh);
			return (0);
		}
	}
	return (1);
}

int			main(int argc, char **argv, char **env)
{
	t_sh	*sh;
	char	*line;

	sh = NULL;
	line = ft_strnew(2);
	sh = ft_make_sh(sh, env);
	if (sh == NULL)
		return (ft_puterror_noenv());
	if (argc == 2)
		return (ft_exec_args(argv[1], sh));
	catch_signals();
	if (ft_set_term())
		return (-1);
	ft_display_prompt(sh);
	while (42)
		line = ft_read_char(sh, line);
	ft_unset_term();
	return (0);
}
