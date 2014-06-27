/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 18:30:19 by tmertz            #+#    #+#             */
/*   Updated: 2014/06/19 15:51:58 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADD_VAR_H
# define ADD_VAR_H

# include "structs.h"
# include <stdlib.h>
# include "error_messages.h"

int			assign_variable(t_sh *sh, t_node *node);
void		add_var_to_env(t_sh *sh, char *name, void *value, int array);

#endif

