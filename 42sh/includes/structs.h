/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 14:09:07 by tmertz            #+#    #+#             */
/*   Updated: 2015/02/19 15:49:09 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS
# define STRUCTS

# include "../libft/libft.h"
# include <sys/time.h>
# include <pthread.h>

# define DEBUG printf("%s(%d)\n", __FUNCTION__, __LINE__ )
# define SIZE_T 128
# define SIZE_S 4096
# define SIZE_HEADER 32

# define TINY 1
# define SMALL 2
# define LARGE 3

# define ALLOC 0
# define FREE 1
# define END 2

typedef struct		s_var
{
	void			*value;
	int				array;
	char			*name;
}					t_var;

typedef struct		s_hist
{
	char			*cmd;
	struct s_hist	*next;
	struct s_hist	*prev;
}					t_hist;

typedef struct		s_cmd
{
	char			*cmd;
	char			**args;
}					t_cmd;

typedef struct		s_sh
{
	t_list			**paths;
	t_hist			*history;
	char			**env;
	int				env_size;
	int				in;
	int				out;
	char			*pwd;
	char			*oldpwd;
	char			*home;
	int				**fd;
	t_list			*var;
	char			*path;
}					t_sh;

typedef struct		s_word
{
	int				k;
	char			quote;
	char			*result;
	char			*var;
	int				status;
}					t_word;

typedef struct		s_token
{
	char			*lexen;
	int				type;
}					t_token;

typedef struct		s_read
{
	char			*line;
	char			*var_line;
	char			*var_arr;
	int				s;
	int				e;
	int				a;
	int				u;
	int				k;
	char			d;
	int				t;
}					t_read;

typedef struct		s_ex
{
	int				id_fd;
	int				r_fd;
	int				rights;
	char			*path;
}					t_ex;

typedef struct		s_t
{
	struct timeval	t1;
	struct timeval	t2;
}					t_t;


typedef struct		s_header
{
	unsigned int	flag;
	void			*ptr;
	size_t			size;
	size_t			prev_size;
}					t_header;

typedef struct		s_maps
{
	void			*tiny_maps;
	void			*small_maps;
	void			*large_maps;
	size_t			total_size_t;
	size_t			total_size_s;
}					t_maps;

#endif
