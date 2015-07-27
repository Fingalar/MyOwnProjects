/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 17:20:32 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/29 12:26:02 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "../libft/libft.h"
# include "structs.h"
# include <unistd.h>

void		double_free_error();
void		free_not_allocated_error();
void		realloc_not_allocated_error();
void		show_alloc_mem();
void		*memory_corruption(void);
void		print_addresse(void *ptr);
void		print_mem_block(t_header *header);
void		*too_large_malloc(void);

#endif
