#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

# include <unistd.h>
# include <structs.h>

int	throw_error(int errno);
void	bad_opt_error();
void	rights_file_error();

#endif
