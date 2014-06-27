/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyguel <nyguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 04:59:20 by tmertz            #+#    #+#             */
/*   Updated: 2014/06/20 20:13:00 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "../libft/libft.h"
# include <sys/time.h>

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

#endif
