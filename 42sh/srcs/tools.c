/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 17:19:29 by tmertz            #+#    #+#             */
/*   Updated: 2015/02/17 19:00:52 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/tools.h"

void		double_free_error(void)
{
	ft_putendl_fd("Error, double free", 2);
}

void		free_not_allocated_error(void)
{
	ft_putendl_fd("Pointer being freed without being allocated", 2);
}

void		realloc_not_allocated_error(void)
{
	ft_putendl_fd("Pointer being reallocated without being allocated", 2);
}

void		*memory_corruption(void)
{
	ft_putendl_fd("Error : memory corruption, you did something wrong", 2);
	return (NULL);
}
