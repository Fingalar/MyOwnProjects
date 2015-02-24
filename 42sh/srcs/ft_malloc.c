/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 13:22:59 by tmertz            #+#    #+#             */
/*   Updated: 2015/02/19 16:07:46 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

pthread_mutex_t		g_mem_mutex;
t_maps				g_maps;

void			*malloc(size_t size)
{
	void		*ptr;

	ft_putendl("MALLOC");
	if (size <= 0)
		return (NULL);
	pthread_mutex_lock(&g_mem_mutex);
	if (g_maps.tiny_maps == NULL && g_maps.small_maps == NULL)
		init_sizes();
	if (size <= SIZE_T)
	{
		if (g_maps.tiny_maps == NULL)
			g_maps.tiny_maps = map_init(TINY);
		ptr = m_alloc(g_maps.tiny_maps, size, TINY);
	}
	else if (size <= SIZE_S)
	{
		if (g_maps.small_maps == NULL)
			g_maps.small_maps = map_init(SMALL);
		ptr = m_alloc(g_maps.small_maps, size, SMALL);
	}
	else
		ptr = large_malloc(size);
	pthread_mutex_unlock(&g_mem_mutex);
	return (ptr);
}

void			init_sizes(void)
{
	g_maps.total_size_t = getpagesize() * 10;
	g_maps.total_size_s = getpagesize() * 20;
}

void			*map_init(unsigned char type)
{
	unsigned int			max_size;
	void					*ptr;
	t_header				*header;

	max_size = 0;
	if (type == TINY)
		max_size = g_maps.total_size_t;
	else if (type == SMALL)
		max_size = g_maps.total_size_s;
	ptr = mmap(0, max_size, PROT_WRITE | PROT_READ, MAP_ANON
			| MAP_PRIVATE, 0 ,0);
	ft_bzero(ptr, max_size);
	header = ptr;
	header->size = max_size - (SIZE_HEADER * 2);
	header->flag = FREE;
	header->prev_size = 0;
	header->ptr = ptr + SIZE_HEADER;
	header = (ptr + max_size - SIZE_HEADER);
	header->flag = END;
	header->ptr = NULL;
	return (ptr);
}

void			*m_alloc(void *ptr, size_t size, unsigned char type)
{
	t_header				*header;
	size_t					check_size;

	check_size = 0;
	while (42)
	{
		header = (t_header *)ptr;
		if ((type == TINY && check_size >= g_maps.total_size_t)
				|| (type == SMALL && check_size >= g_maps.total_size_s))
			return (memory_corruption());
		if (FREE == header->flag && header->size >= size)
		{
			header->flag = ALLOC;
			if ((header->size - size) > SIZE_HEADER)
				add_freed_zone(header, size);
			return (header->ptr);
		}
		else if (END == header->flag)
		{
			if (header->ptr == NULL)
			{
				ptr = map_init(type);
				if (ptr == NULL)
					return (NULL);
				header->ptr = ptr;
			}
			ptr = header->ptr;
			check_size = 0;
		}
		else
		{
			ptr = (ptr + header->size + SIZE_HEADER);
			check_size += header->size;
		}
	}
	return (NULL);
}

void		add_freed_zone(t_header *header, size_t size)
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

void		*large_malloc(size_t size)
{
	t_header		*header;
	t_header		*end_header;

	header = g_maps.large_maps;
	while (header != NULL)
	{
		end_header = (void *)header + header->size * SIZE_HEADER;
		header = end_header->ptr;
	}
	header = mmap(0, size + (SIZE_HEADER * 2), PROT_WRITE
		| PROT_READ, MAP_ANON | MAP_PRIVATE, 0 ,0);
	if (g_maps.large_maps == NULL)
		g_maps.large_maps = header;
	header->size = size;
	header->prev_size = 0;
	header->ptr = (void *)header + SIZE_HEADER;
	return (header->ptr);
}
