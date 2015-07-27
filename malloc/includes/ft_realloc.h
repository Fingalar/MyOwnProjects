/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 13:48:37 by tmertz            #+#    #+#             */
/*   Updated: 2015/02/20 16:28:50 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REALLOC_H
# define FT_REALLOC_H

# include "ft_malloc.h"
# include "ft_free.h"
# include "tools.h"

void		*realloc(void *ptr, size_t size);
void		*do_realloc(t_header *header, size_t size);

#endif
