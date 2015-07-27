/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 13:48:23 by tmertz            #+#    #+#             */
/*   Updated: 2015/02/28 16:14:44 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>
# include "tools.h"
# include "../libft/libft.h"
# include "structs.h"
# include "ft_free.h"

void	init_sizes(void);
void	*do_malloc(void *ptr, size_t size, unsigned char type,
		size_t check_size);
void	*malloc(size_t size);
void	*map_init(unsigned char type);
void	add_freed_zone(t_header *header, size_t size);
void	*large_malloc(size_t size);
void	*end_flag(size_t *check_size, void *ptr, t_header *header,
					unsigned char type);
void	*data_overflow(void);
void	*free_flag(t_header *header, size_t size);
void	set_large_headers(t_header *header, t_header *end_header,
		size_t size_map);
int		set_size_large_maps(size_t size);

#endif
