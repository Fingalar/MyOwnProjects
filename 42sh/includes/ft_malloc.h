/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 13:48:23 by tmertz            #+#    #+#             */
/*   Updated: 2015/02/17 15:59:18 by tmertz           ###   ########.fr       */
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
void	*m_alloc(void * ptr, size_t size, unsigned char type);
void	*malloc(size_t size);
void	*map_init(unsigned char type);
void	add_freed_zone(t_header *header, size_t size);
void	*large_malloc(size_t size);

#endif
