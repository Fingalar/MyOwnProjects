#ifndef STRUCTS_H
# define STRUCTS_H

# define BAD_ARG 1
# define RIGHTS_FILE 2

typedef struct		s_options
{
	unsigned char	append;
	unsigned char	command;
	unsigned char	ret;
	unsigned char	flush;
	unsigned char	force;
	unsigned char	quiet;
	unsigned char	timing;
	unsigned char	help;
	unsigned char	version;		
}			t_options;

typedef struct		s_script
{
	int		fd_typefile;
	char		*filename;
	t_options	options;
}			t_script;

#endif
