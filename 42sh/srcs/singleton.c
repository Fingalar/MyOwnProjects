/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 15:10:38 by tmertz            #+#    #+#             */
/*   Updated: 2014/05/24 15:19:30 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/singleton.h"

t_sh	*get_sh(void)
{
	static t_sh		*singleton;

	if (singleton == NULL)
		singleton = ft_memalloc(sizeof(t_sh) * 1);
	return (singleton);
}
