/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 22:16:18 by tmertz            #+#    #+#             */
/*   Updated: 2014/05/24 15:24:41 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "main.h"
# include <signal.h>
# include "term.h"
# include "singleton.h"
# include "../libft/libft.h"

void	handle_segfault(void);
void	ft_handle_signals(int signum);
void	catch_signals(void);

#endif
