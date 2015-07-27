/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 15:41:03 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/29 13:43:37 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"
#include <limits.h>

pthread_mutex_t		g_mem_mutex;
t_maps				g_maps;

void				*malloc(size_t size)
{
	void		*ptr;

	if (g_maps.tiny_maps == NULL && g_maps.small_maps == NULL
			&& g_maps.limits.rlim_cur == 0)
		init_sizes();
	if (size > g_maps.limits.rlim_cur)
		return (too_large_malloc());
	pthread_mutex_lock(&g_mem_mutex);
	if (size <= SIZE_TINY)
	{
		if (g_maps.tiny_maps == NULL)
			g_maps.tiny_maps = map_init(TINY);
		ptr = do_malloc(g_maps.tiny_maps, size, TINY, 0);
	}
	else if (size <= SIZE_SMALL)
	{
		if (g_maps.small_maps == NULL)
			g_maps.small_maps = map_init(SMALL);
		ptr = do_malloc(g_maps.small_maps, size, SMALL, 0);
	}
	else
		ptr = large_malloc(size);
	pthread_mutex_unlock(&g_mem_mutex);
	return (ptr);
}

void				*do_malloc(void *ptr, size_t size, unsigned char type,
		size_t check_size)
{
	t_header				*header;

	check_size = 0;
	while (42)
	{
		if (ptr == NULL)
			return (NULL);
		header = (t_header *)ptr;
		if ((type == TINY && check_size >= g_maps.total_size_t)
				|| (type == SMALL && check_size >= g_maps.total_size_s))
			return (memory_corruption());
		if (FREE == header->flag && header->size >= size)
			return (free_flag(header, size));
		else if (END == header->flag)
			ptr = end_flag(&check_size, ptr, header, type);
		else
		{
			ptr = (ptr + header->size + SIZE_HEADER);
			check_size += header->size;
		}
	}
	return (NULL);
}

void				add_freed_zone(t_header *header, size_t size)
{
	t_header		*tmp_header;
	t_header		*next_header;

	tmp_header = (void *)header + SIZE_HEADER + size;
	tmp_header->flag = 1;
	tmp_header->size = header->size - (size + SIZE_HEADER);
	header->size = size;
	tmp_header->prev_size = size;
	tmp_header->ptr = (void *)tmp_header + SIZE_HEADER;
	next_header = (void *)tmp_header + SIZE_HEADER + tmp_header->size;
	next_header->prev_size = tmp_header->size;
}

void				*large_malloc(size_t size)
{
	t_header		*header;
	t_header		*end_header;
	size_t			size_map;

	size_map = set_size_large_maps(size);
	if (size_map == 0)
		return (data_overflow());
	header = g_maps.large_maps;
	while (header != NULL)
	{
		end_header = (void *)header + header->size + SIZE_HEADER;
		header = end_header->ptr;
	}
	header = mmap(0, size_map, PROT_WRITE
		| PROT_READ, MAP_ANON | MAP_PRIVATE, 0, 0);
	if (g_maps.large_maps == NULL)
		g_maps.large_maps = header;
	else
		end_header->ptr = header;
	header->size = size_map - SIZE_HEADER * 2;
	header->prev_size = 0;
	header->ptr = (void *)header + SIZE_HEADER;
	end_header = (void *)header + size_map - SIZE_HEADER;
	end_header->flag = END;
	return (header->ptr);
}

int					set_size_large_maps(size_t size)
{
	long long int		size_map;

	size_map = 0;
	while ((size_t)size_map < size + SIZE_HEADER * 2)
	{
		g_maps.size_allocs += getpagesize() * 1000;
		size_map += getpagesize() * 1000;
	}
	size_map -= (getpagesize() * 1000);
	g_maps.size_allocs -= (getpagesize() * 1000);
	while ((size_t)size_map < size + SIZE_HEADER * 2)
	{
		g_maps.size_allocs += getpagesize();
		if (g_maps.size_allocs > (long long int)g_maps.limits.rlim_cur)
			return (0);
		size_map += getpagesize();
	}
	return (size_map);
}
