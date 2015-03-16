#include "main.h"

int	main(int argc, char **argv)
{
	t_script	script;
	int		status;

	script.filename = NULL;
	status = parse_args(argv, &script);
	if (status != 0)
		throw_error(status);
	status = lauch_script();
	if (status != 0)
		throw_error(status);
}


