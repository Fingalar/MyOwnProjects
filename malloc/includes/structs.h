/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 14:09:07 by tmertz            #+#    #+#             */
/*   Updated: 2015/03/02 17:02:59 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>
# include <sys/time.h>
# include <sys/resource.h>

# define SIZE_TINY 128
# define SIZE_SMALL 4096
# define SIZE_HEADER 32

# define TINY 1
# define SMALL 2
# define LARGE 3

# define ALLOC 0
# define FREE 1
# define END 2

typedef struct				s_header
{
	unsigned int			flag;
	void					*ptr;
	size_t					size;
	size_t					prev_size;
}							t_header;

typedef struct				s_maps
{
	void					*tiny_maps;
	void					*small_maps;
	void					*large_maps;
	size_t					total_size_t;
	size_t					total_size_s;
	struct rlimit			limits;
	long long int			size_allocs;
}							t_maps;

#endif
