/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 13:23:14 by tmertz            #+#    #+#             */
/*   Updated: 2015/02/17 17:40:01 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FREE
# define FT_FREE

# include "ft_malloc.h"
# include "tools.h"
# include "structs.h"

void		free(void *ptr);
void		do_free(t_header *header);
void		do_large_free(t_header *header);
void		check_if_empty_map(t_header *header);
void		bind_maps(t_header *header);
int			check_if_valid_address(void *ptr);
t_header	*check_prev_and_next(t_header *header);
int			check_in_large(void *ptr);

#endif
