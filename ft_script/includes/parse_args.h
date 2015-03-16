#ifndef PARSE_ARGS_H
# define PARSE_ARGS_H

# include "../libft/libft.h"
# include <structs.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

int	parse_args(char **argv, t_script *script);
int	add_opt(char *arg, t_script *script);
int	isoption(char opt);
void	set_opt_flag(char opt, t_script *script);

#endif
