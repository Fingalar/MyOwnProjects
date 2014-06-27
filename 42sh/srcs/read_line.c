/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyguel <nyguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 19:01:23 by nyguel            #+#    #+#             */
/*   Updated: 2014/06/20 16:52:52 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read.h"
#include <unistd.h>
#include <fcntl.h>
#include "term.h"
#include <sys/time.h>

static char	*ft_add_char(char c, char *line)
{
	int			j;
	char		*line2;

	j = ft_strlen(line);
	line2 = ft_strnew(j + 2);
	ft_strcpy(line2, line);
	free(line);
	line2[j] = c;
	line2[j + 1] = '\0';
	return (line2);
}

static char	ft_read_char2(t_read *opt, int *i)
{
	char	c[1];

	c[0] = 0;
	if (read(opt->u, c, 1) == 1)
	{
		*i = *i + 1;
		if (opt->s == 0)
			ft_putchar(c[0]);
		return (c[0]);
	}
	return (-1);
}

static t_t	*ft_init_var(char **line, t_read *opt, char *c)
{
	int		flags;
	t_t		*t;

	flags = fcntl(opt->u, F_GETFL, 0);
	fcntl(opt->u, F_SETFL, flags | O_NONBLOCK);
	*line = (char *)malloc(sizeof(char));
	*line[0] = '\0';
	*c = '\0';
	t = (t_t *)malloc(sizeof(t_t));
	gettimeofday(&(t->t1), NULL);
	gettimeofday(&(t->t2), NULL);
	return (t);
}

static void	ft_unset_read(t_t *t, t_read *opt, char *line)
{
	int		i;

	ft_unset_term();
	i = fcntl(opt->u, F_GETFL, 0);
	fcntl(opt->u, F_SETFL, i & ~O_NONBLOCK);
	if (opt->e == 1)
		ft_putendl(line);
	if ((double)t->t2.tv_sec >= (double)t->t1.tv_sec + (double)opt->t)
		ft_putchar('\n');
	free(t);
	opt->line = ft_strdup(line);
	free(line);
}

int			ft_read_line(t_read *opt)
{
	int		i;
	int		max_len;
	char	c;
	char	*line;
	t_t		*t;

	ft_set_term();
	t = ft_init_var(&line, opt, &c);
	i = 0;
	max_len = (opt->k == -1) ? 99999999 : opt->k;
	while (i < max_len && c != opt->d && (double)t->t2.tv_sec
		< (double)t->t1.tv_sec + (double)opt->t)
	{
		c = ft_read_char2(opt, &i);
		if (c != -1 && c != opt->d)
			line = ft_add_char(c, line);
		gettimeofday(&(t->t2), NULL);
	}
	ft_unset_read(t, opt, line);
	return (0);
}
