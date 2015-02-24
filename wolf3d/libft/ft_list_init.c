/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:21:45 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/14 23:08:41 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_list_init(t_list *list)
{
	list = (t_list*)ft_memalloc(sizeof(t_list));
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	return (list);
}
