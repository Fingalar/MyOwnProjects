#include <parse_args.h>

int	parse_long_opt(char *opt, t_script *script)
{
	if (!ft_strcmp(opt, "force"))
		script->options.force = 1;
	else if (!ft_strcmp(opt, "help"))
		script->options.help = 1;
	else if (!ft_strcmp(opt, "append"))
		script->options.append = 1;
	else if (!ft_strcmp(opt, "command"))
		script->options.command = 1;
	else if	(!ft_strcmp(opt, "return"))
		script->options.ret = 1;
	else if (!ft_strcmp(opt, "flush"))
		script->options.flush = 1;
	else if (!ft_strcmp(opt, "quiet"))
		script->options.quiet = 1;
	else if (!ft_strcmp(opt, "timing"))
		script->options.timing = 1;
	else if (!ft_strcmp(opt, "version"))
		script->options.version = 1;
	else
		return (-1);
	return (0);
}
