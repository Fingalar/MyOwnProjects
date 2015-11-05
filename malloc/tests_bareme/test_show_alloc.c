/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_show_alloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 15:56:57 by ymohl-cl          #+#    #+#             */
/*   Updated: 2015/04/29 12:26:08 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_realloc.h"
#include "../includes/tools.h"

int main()
{
	malloc(1024);
	malloc(1024 * 32);
	malloc(1024 * 1024);
	malloc(1024 * 1024 * 16);
	malloc(1024 * 1024 * 128);
	show_alloc_mem();
	return (0);
}