/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:21:45 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/05 01:15:57 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_list_init(t_list *list)
{
	list = (t_list*)ft_memalloc(sizeof(t_list));
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	list->max = 0;
	return (list);
}
