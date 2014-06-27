/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 20:06:56 by tmertz            #+#    #+#             */
/*   Updated: 2014/02/09 21:47:05 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <signal.h>

# include "../libft/libft.h"

typedef struct		s_id
{
	char	*bin;
	int		index;
	int		id;
}					t_id;

typedef struct		s_car
{
	char	*bin;
	int		index;
	char	car;
}					t_car;

void		*ft_get_t_car(void);
void		*ft_get_t_id(void);
void		ft_send_pid(pid_t pid, int server_pid);
int			ft_check_arg(char **av);
int			ft_check_mess(char **av);

# endif /* MINITALK_H */
