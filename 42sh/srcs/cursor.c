/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-lacr <pde-lacr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 19:05:06 by pde-lacr          #+#    #+#             */
/*   Updated: 2014/03/27 18:45:12 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cursor.h>

void			ft_beginend(char c, char *line, int *i)
{
	while (c == 72 && *i > 0)
	{
		tputs(tgetstr("le", NULL), 1, tputs_putchar);
		*i -= 1;
	}
	while (c == 70 && *i < (int)ft_strlen(line))
	{
		tputs(tgetstr("nd", NULL), 1, tputs_putchar);
		*i += 1;
	}
}

int				ft_wordmove(char c, char *line, int *i)
{
	char		*cap;

	cap = (c == 68) ? "le" : "nd";
	while (*i <= (int)ft_strlen(line) && *i >= 0
			&& (line[*i] == ' ' || line[*i] == '\t'))
	{
		tputs(tgetstr(cap, NULL), 1, tputs_putchar);
		*i += (c == 68) ? -1 : 1;
	}
	while ((*i < (int)ft_strlen(line)
				|| (*i == (int)ft_strlen(line) && c == 68))
			&& (*i > 0 || (*i == 0 && c == 67))
			&& line[*i] != ' ' && line[*i] != '\t')
	{
		tputs(tgetstr(cap, NULL), 1, tputs_putchar);
		*i += (c == 68) ? -1 : 1;
	}
	return (0);
}

char			*ft_arrow_up(char *line, int *i, t_sh *sh)
{
	char		*newline;

	newline = get_hist(KEY_UP, sh);
	if (newline)
	{
		ft_beginend(70, line, i);
		while (*i > 0)
			ft_delchar(line, i);
		*i += ft_strlen(newline);
		ft_putstr(newline);
		return (newline);
	}
	return (line);
}

char			*ft_arrow_down(char *line, int *i, t_sh *sh)
{
	char		*newline;

	newline = get_hist(KEY_DOWN, sh);
	if (newline)
	{
		ft_beginend(70, line, i);
		while (*i > 0)
			ft_delchar(line, i);
		*i += ft_strlen(newline);
		ft_putstr(newline);
		line = ft_strdup(newline);
	}
	return (line);
}

char			*ft_handlekey(char *key, char *line, int *i, t_sh *sh)
{
	static int	alt = 0;

	if (key[0] == 27 && key[1] == 91 && key[2] == 65)
		return (ft_arrow_up(line, i, sh));
	if (key[0] == 27 && key[1] == 91 && key[2] == 66)
		return (ft_arrow_down(line, i, sh));
	if (key[0] == 27 && key[1] == 91 && key[2] == 68 && *i > 0)
	{
		tputs(tgetstr("le", NULL), 1, tputs_putchar);
		*i -= 1;
	}
	else if (key[0] == 27 && key[1] == 91 && key[2] == 67
			&& *i <= (int)ft_strlen(line) - 1)
	{
		tputs(tgetstr("nd", NULL), 1, tputs_putchar);
		*i += 1;
	}
	else if (key[0] == 27 && key[1] == 91 && (key[2] == 72 || key[2] == 70))
		ft_beginend(key[2], line, i);
	else if (alt && key[0] == 57 && (key[1] == 68 || key[1] == 67))
		alt = ft_wordmove(key[1], line, i);
	else if (key[0] == 27 && key[1] == 91 && key[2] == 49 && key[3] == 59)
		alt = 1;
	return (line);
}
