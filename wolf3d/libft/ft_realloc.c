/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 14:33:56 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 06:36:11 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "libft.h"

void	*ft_realloc(void *mem, int size, int size_to_copy)
{
	char	*new_mem;

	new_mem = ft_memalloc(size);
	if (mem)
	{
		new_mem = ft_memcpy(new_mem, mem, size_to_copy);
	}
	return (new_mem);
}
