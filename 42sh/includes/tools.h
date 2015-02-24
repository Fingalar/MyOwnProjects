/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 17:20:32 by tmertz            #+#    #+#             */
/*   Updated: 2015/02/17 19:00:49 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS
# define TOOLS

# include "../libft/libft.h"
# include "structs.h"
# include <unistd.h>

void		double_free_error();
void		free_not_allocated_error();
void		realloc_not_allocated_error();
void		show_mem_alloc();
void		*memory_corruption(void);
void		print_addresse(void *ptr);
void		print_mem_block(t_header *header);

#endif
