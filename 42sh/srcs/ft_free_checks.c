/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 17:25:42 by tmertz            #+#    #+#             */
/*   Updated: 2015/02/19 15:41:32 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_free.h"

extern pthread_mutex_t		g_mem_mutex;
extern t_maps				g_maps;

int			check_if_valid_address(void *ptr)
{
	void		*map;
	t_header	*end;

	map = g_maps.tiny_maps;
	while (map)
	{
		if ((ptr - g_maps.total_size_t) < map
				&& ptr < map + g_maps.total_size_t && ptr - SIZE_HEADER >= map)
			return (1);
		end = map + g_maps.total_size_t - SIZE_HEADER;
		map = end->ptr;
	}
	map = g_maps.small_maps;
	while (map)
	{
		if ((ptr - g_maps.total_size_s) < map
				&& ptr < map + g_maps.total_size_s && ptr - SIZE_HEADER >= map)
			return (1);
		end = map + g_maps.total_size_s - SIZE_HEADER;
		map = end->ptr;
	}
	return (check_in_large(ptr));
}

int			check_in_large(void *ptr)
{
	void		*map;
	t_header	*end;

	map = g_maps.large_maps;
	while (map)
	{
		if (ptr - SIZE_HEADER == map)
			return (1);
		end = map + ((t_header *)map)->size - SIZE_HEADER;
		map = end->ptr;
	}
	free_not_allocated_error();
	return (0);
}

void		check_if_empty_map(t_header *header)
{
	t_header	*next_header;

	next_header = (void *)header + header->size + SIZE_HEADER;
	if (0 == header->prev_size && END == next_header->flag)
	{
		if (header == g_maps.tiny_maps)
			g_maps.tiny_maps = next_header->ptr;
		else if (header == g_maps.small_maps)
			g_maps.small_maps = next_header->ptr;
		else if (header == g_maps.large_maps)
			g_maps.large_maps = next_header->ptr;
		else
		{
			bind_maps(header);
		}
		munmap(header, header->size + SIZE_HEADER * 2);
	}
}

void		bind_maps(t_header *header)
{
	t_header		*map;
	t_header		*prev;
	t_header		*end;
	t_header		*next_end;
	unsigned int	size;

	map = NULL;
	if (header->size < g_maps.total_size_t && (size = g_maps.total_size_t))
		map = g_maps.tiny_maps;
	else if (header->size < g_maps.total_size_s && (size = g_maps.total_size_s))
		map = g_maps.small_maps;
	while (map && map != header)
	{
		end = (void *)map + size - SIZE_HEADER;
		prev = map;
		map = end->ptr;
	}
	end = (void *)prev + size - SIZE_HEADER;
	next_end = (void *)map + size - SIZE_HEADER;
	end->ptr = next_end->ptr;
}

t_header	*check_prev_and_next(t_header *header)
{
	t_header		*next;
	t_header		*prev;

	next = (void *)header + header->size + SIZE_HEADER;
	if (1 == next->flag)
	{
		header->size += SIZE_HEADER + next->size;
		ft_bzero(next, SIZE_HEADER);
		next = (void *)header + header->size + SIZE_HEADER;
		if (header->flag != 2)
			next->prev_size = header->size;
	}
	if (0 != header->prev_size)
	{
		prev = (void *)header - header->prev_size - SIZE_HEADER;
		if (1 == prev->flag)
		{
			prev->size += SIZE_HEADER + header->size;
			ft_bzero(header, SIZE_HEADER + header->size);
			next = (void *)prev + prev->size + SIZE_HEADER;
			next->prev_size = prev->size;
			header = prev;
		}
	}
	return (header);
}
