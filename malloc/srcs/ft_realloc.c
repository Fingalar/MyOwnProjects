/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 13:23:50 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/29 13:34:15 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_realloc.h"

extern pthread_mutex_t		g_mem_mutex;
extern t_maps				g_maps;

void		*realloc(void *ptr, size_t size)
{
	t_header		*header;

	if (NULL == ptr)
		return (malloc(size));
	if (!check_if_valid_address(ptr))
		return (NULL);
	header = ptr - SIZE_HEADER;
	if (header->ptr == ptr)
	{
		if (header->flag != ALLOC)
			realloc_not_allocated_error();
		else if (ALLOC == header->flag)
		{
			if (0 == size)
			{
				free(ptr);
				return (malloc(1));
			}
			return (do_realloc(header, size));
		}
		else
			realloc_not_allocated_error();
		return (ptr);
	}
	return (NULL);
}

void		*do_realloc(t_header *header, size_t size)
{
	void		*old_ptr;
	void		*ptr;

	old_ptr = header->ptr;
	if (size > header->size)
	{
		ptr = malloc(size);
		pthread_mutex_lock(&g_mem_mutex);
		ft_memcpy(ptr, old_ptr, header->size);
		pthread_mutex_unlock(&g_mem_mutex);
		free(old_ptr);
		return (ptr);
	}
	else
	{
		pthread_mutex_lock(&g_mem_mutex);
		if (size - header->size > SIZE_HEADER)
			add_freed_zone(header, size);
		pthread_mutex_unlock(&g_mem_mutex);
		header->size = size;
	}
	return (header);
}
