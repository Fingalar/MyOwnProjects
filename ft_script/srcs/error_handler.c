#include <error_handler.h>

int	throw_error(int errno)
{
	if (errno == BAD_ARG)
		bad_opt_error();
	if (errno == RIGHTS_FILE)
		rights_file_error();
	_exit(errno);
}

void	bad_opt_error()
{
	//
}

void	rights_file_error()
{

}

