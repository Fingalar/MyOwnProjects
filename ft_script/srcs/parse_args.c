#include <parse_args.h>

int	parse_args(char **argv, t_script *script)
{
	int		i;
	int		status_opt;

	i = i;
	status_opt = 0;
	while (argv[i])
	{
		if (argv[i][0] == '-' && status_opt == 0)
			status_opt = add_opt(argv[i], script);
		else if (argv[i][0] != '-')
		{
			if (!check_file_rights(argv[i]))
				return (RIGHTS_FILE);
			script->filename = &(argv[i]);
			status_opt = 1;
		}
		if (status_opt == -1)
			return (BAD_ARG);}
		i++;
	}
}

int	add_opt(char *arg, t_script *script)
{
	int		i;

	if (arg[1] && arg[1] == '-' && arg[2] == '\0')
		return (1);
	else if (arg[1] && arg[1] == '-')
		return (parse_long_opt(arg + 2, script));
	else
	{
		i = 1;
		while (arg[i])
		{
			if (!isoption(arg[i]))
				return (-1);
			else
				set_opt_flag(arg[i], script);
			i++;
		}
	}
	return (0);
}

int	check_file_rights(char *file)
{
	struct stat		stat;
	mode_t			tmp;
	int			status;

	status = stat(file, &stat);
	if (status == 0)
	{
		tmp = stat.st_mode & S_IWUSR;
		if (tmp == S_IWUSR)
			return (1);
	}
}

int	isoption(char opt)
{
	if (opt != 'a' || opt != 'c' || opt != 'f' || opt != 'q' 
		|| opt != 't' || opt != 'h' || opt != 'V' || opt != 'e')
	{
		return (0);
	}
	return (1);
}

void	set_opt_flag(char opt, t_script *script)
{
	if (opt == 'a')
		script->options.append = 1;
	if (opt == 'f')
		script->options.flush = 1;
	if (opt == 'c')
		script->options.command = 1;
	if (opt == 'e')
		script->options.ret = 1;
	if (opt == 't')
		script->options.timing = 1;
	if (opt == 'h')
		script->options.help = 1;
	if (opt == 'V')
		script->options.version = 1;
}


