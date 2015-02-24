/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 18:59:43 by tmertz            #+#    #+#             */
/*   Updated: 2015/02/19 17:18:48 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tools.h"

extern pthread_mutex_t		g_mem_mutex;
extern t_maps				g_maps;

void		set_tab(char *result)
{
	result[0] = '0';
	result[1] = 'x';
	result[2] = '0';
	result[3] = '0';
	result[4] = '0';
	result[5] = '0';
	result[6] = '0';
	result[7] = '0';
	result[8] = '0';
	result[9] = '0';
	result[10] = '0';
	result[11] = '0';
	result[12] = '0';
	result[13] = '0';
	result[14] = '0';
	result[15] = '0';
	result[16] = '0';
	result[17] = '0';
}

void		print_addresse(void *ptr)
{
	unsigned long int		addr;
	int						count;
	char					result[18];

	set_tab(&result[0]);
	addr = (unsigned long int)ptr;
	count = 17;
	while (addr > 0)
	{
		if ((addr % 16) < 10)
			result[count--] = (char)(addr % 16 + 48);
		else
			result[count--] = (char)(addr % 16 + 87);
		addr = addr / 16;
	}
	write(1, &result, 18);
}

void		print_mem_block(t_header *header)
{
	print_addresse(header->ptr);
	ft_putstr(" - ");
	print_addresse(header->ptr + header->size - 1);
	ft_putstr(": ");
	ft_putnbr(header->size);
	ft_putendl(" octets");
}
