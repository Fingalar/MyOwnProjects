/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 16:43:44 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/21 13:50:56 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

extern pthread_mutex_t		g_mem_mutex;
extern t_maps				g_maps;

void				*map_init(unsigned char type)
{
	unsigned int	max_size;
	void			*ptr;
	t_header		*header;

	max_size = 0;
	if (type == TINY)
		max_size = g_maps.total_size_t;
	else if (type == SMALL)
		max_size = g_maps.total_size_s;
	g_maps.size_allocs += max_size;
	if (g_maps.size_allocs > (long long)g_maps.limits.rlim_cur)
		return (data_overflow());
	ptr = mmap(0, max_size, PROT_WRITE | PROT_READ, MAP_ANON
			| MAP_PRIVATE, 0, 0);
	header = ptr;
	header->size = max_size - SIZE_HEADER - SIZE_HEADER;
	header->flag = FREE;
	header->prev_size = 0;
	header->ptr = ptr + SIZE_HEADER;
	header = ptr + max_size - SIZE_HEADER;
	header->flag = END;
	header->ptr = NULL;
	return (ptr);
}

void				*end_flag(size_t *check_size, void *ptr, t_header *header,
					unsigned char type)
{
	if (header->ptr == NULL)
	{
		ptr = map_init(type);
		header->ptr = ptr;
	}
	ptr = header->ptr;
	*check_size = 0;
	return (ptr);
}

void				*free_flag(t_header *header, size_t size)
{
	header->flag = ALLOC;
	if ((header->size - size) > SIZE_HEADER)
		add_freed_zone(header, size);
	return (header->ptr);
}

void				init_sizes(void)
{
	g_maps.total_size_t = getpagesize() * 10;
	g_maps.total_size_s = getpagesize() * 20;
	getrlimit(RLIMIT_DATA, &g_maps.limits);
}

void				*data_overflow(void)
{
	ft_putendl_fd("Error, too much memory allocated for a process", 2);
	return (NULL);
}
