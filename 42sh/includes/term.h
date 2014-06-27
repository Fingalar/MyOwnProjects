/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-lacr <pde-lacr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 17:05:13 by pde-lacr          #+#    #+#             */
/*   Updated: 2014/03/23 22:18:06 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_H
# define TERM_H

# include "../libft/libft.h"
# include <termios.h>
# include <termcap.h>
# include "main.h"

int		tputs_putchar(int c);
int		ft_set_term(void);
int		ft_unset_term(void);

#endif
