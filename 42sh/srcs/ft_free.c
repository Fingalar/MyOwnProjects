/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 13:23:43 by tmertz            #+#    #+#             */
/*   Updated: 2015/02/19 16:03:24 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_free.h"

extern pthread_mutex_t		g_mem_mutex;
extern t_maps				g_maps;

void		free(void *ptr)
{
	t_header		*header;

	ft_putendl("FREE");
	if (!ptr)
		return ;
	pthread_mutex_lock(&g_mem_mutex);
	if (!check_if_valid_address(ptr))
		return ;
	header = ptr - SIZE_HEADER;
	if (header->ptr == ptr)
	{
		if (1 == header->flag)
			double_free_error();
		else if (0 == header->flag)
			do_free(header);
		else
			free_not_allocated_error();
	}
	else
		free_not_allocated_error();
	pthread_mutex_unlock(&g_mem_mutex);
}

void		do_free(t_header *header)
{
	header->flag = 1;
	if (header->size > SIZE_S)
		do_large_free(header);
	ft_bzero((void *)header + SIZE_HEADER, header->size);
	header = check_prev_and_next(header);
	check_if_empty_map(header);
}

void		do_large_free(t_header *header)
{
	t_header		*end;
	t_header		*prev;
	t_header		*next_end;
	t_header		*map;

	end = (void *)header + header->size + SIZE_HEADER;
	if (g_maps.large_maps == header)
		g_maps.large_maps = end->ptr;
	else
	{
		map = g_maps.large_maps;
		while (map && map != header)
		{
			end = (void *)map + map->size + SIZE_HEADER;
			prev = map;
			map = end->ptr;
		}
		end = (void *)prev + prev->size + SIZE_HEADER;
		next_end = (void *)map + map->size + SIZE_HEADER;
		end->ptr = next_end->ptr;
	}
	munmap(header, header->size + SIZE_HEADER * 2);
}
