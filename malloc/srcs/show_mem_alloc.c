/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem_alloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 17:39:58 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/29 12:26:01 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tools.h"

extern pthread_mutex_t		g_mem_mutex;
extern t_maps				g_maps;

t_header	*look_flags(unsigned long long int *total_size,
		size_t *check_size, t_header *header)
{
	if (ALLOC == header->flag)
	{
		print_mem_block(header);
		*total_size += header->size;
	}
	if (END == header->flag)
	{
		header = header->ptr;
		check_size = 0;
	}
	else if (header)
	{
		header = (void *)header + SIZE_HEADER + header->size;
		check_size += header->size + SIZE_HEADER;
	}
	return (header);
}

void		show_tiny_alloc(unsigned long long int *total_size)
{
	size_t		check_size;
	t_header	*header;

	ft_putstr("TINY : ");
	print_addresse(g_maps.tiny_maps);
	ft_putchar('\n');
	if (g_maps.tiny_maps != NULL)
	{
		check_size = 0;
		header = g_maps.tiny_maps;
		while (header != NULL)
		{
			if (check_size > (g_maps.total_size_t - SIZE_HEADER))
			{
				memory_corruption();
				return ;
			}
			header = look_flags(total_size, &check_size, header);
		}
	}
}

void		show_small_alloc(unsigned long long int *total_size)
{
	size_t		check_size;
	t_header	*header;

	ft_putstr("SMALL : ");
	print_addresse(g_maps.small_maps);
	ft_putchar('\n');
	if (g_maps.small_maps != NULL)
	{
		check_size = 0;
		header = g_maps.small_maps;
		while (header != NULL)
		{
			if (check_size > (g_maps.total_size_s - SIZE_HEADER))
			{
				memory_corruption();
				return ;
			}
			header = look_flags(total_size, &check_size, header);
		}
	}
}

void		show_large_alloc(unsigned long long int *total_size)
{
	size_t		check_size;
	t_header	*header;

	ft_putstr("LARGE : ");
	print_addresse(g_maps.large_maps);
	ft_putchar('\n');
	if (g_maps.large_maps != NULL)
	{
		check_size = 0;
		header = g_maps.large_maps;
		while (header != NULL)
		{
			if (check_size > (g_maps.total_size_s - SIZE_HEADER))
			{
				memory_corruption();
				return ;
			}
			header = look_flags(total_size, &check_size, header);
		}
	}
}

void		show_alloc_mem(void)
{
	unsigned long long int		total_size;

	total_size = 0;
	show_tiny_alloc(&total_size);
	show_small_alloc(&total_size);
	show_large_alloc(&total_size);
	ft_putstr("Total : ");
	ft_putllnbr(total_size);
	ft_putendl(" octets");
}
