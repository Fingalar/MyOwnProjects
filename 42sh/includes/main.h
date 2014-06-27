/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-lacr <pde-lacr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 20:34:24 by pde-lacr          #+#    #+#             */
/*   Updated: 2014/05/24 15:25:24 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "structs.h"
# include <unistd.h>
# include "../libft/libft.h"
# include "signals.h"
# include "exec.h"
# include "history.h"
# define __UNUSED__ __attribute__((__unused__))

int			ft_display_prompt(t_sh *sh);

#endif
