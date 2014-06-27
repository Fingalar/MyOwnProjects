/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newcard.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 21:04:27 by hvillain          #+#    #+#             */
/*   Updated: 2014/05/12 15:58:13 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wildcard.h"

int		is(char *prev)
{
	if (prev[0] == '.')
		return (1);
	return (0);
}

int		end_point(char *prev)
{
	int		i;

	i = 0;
	while (prev[i])
		i++;
	i--;
	while (i >= 0 && prev[i] != '/' && prev[i] != '.')
		i--;
	if (i == 0 || prev[i] == '/')
		return (1);
	return (0);
}

int		card2(char *s, char *prev, int type, t_list *tokens)
{
	struct dirent	*file;
	DIR				*ret;

	if (!*s && type == 1)
	{
		if (prev[ft_strlen(prev) - 1] != '.' && end_point(prev))
			ft_create_token(tokens, ft_strdup(prev), 0);
		return (0);
	}
	if ((ret = opendir(prev)) == NULL)
		return (0);
	while ((file = readdir(ret)) != NULL)
	{
		if (match(file->d_name, s) && !is(file->d_name))
		{
			if (prev[ft_strlen(prev) - 1] != '/')
				prev = ft_strjoin(prev, "/");
			if (ft_strncmp(prev, "././", 4) && type != 3 && !is(file->d_name))
				ft_create_token(tokens, ft_strjoin(prev, file->d_name), 0);
			else if (ft_strncmp(prev, "././", 4) && type == 3)
				ft_create_token(tokens, ft_strjoin(prev, file->d_name), 0);
		}
	}
	closedir(ret);
	return (0);
}

void	card(char *s, char *p, int type, t_list *tokens)
{
	struct dirent	*f;
	DIR				*ret;
	char			*t;
	int				i;

	if ((i = 0) && s[0] == '/')
		return (card(s + 1, "/", type, tokens));
	if ((ret = opendir(p)) == NULL)
		return ;
	if (((t = ft_strchr(s, '/')) != NULL))
	{
		while ((f = readdir(ret)) != NULL)
		{
			if ((match(f->d_name, ft_strsub(s, 0, t - s))) && (i = 1))
			{
				ft_putchar(p[s - t]);
				if (((p[s - t] != '.' && s[s - t - 1] != '.') &&
					!ft_strcmp(f->d_name, "..")) || end_point(f->d_name))
					continue ;
				card(t + 1, ft_strjoin(p, f->d_name), type, tokens);
			}
		}
	}
	i = (i == 0) ? card2(s, p, type, tokens) : i;
	closedir(ret);
}

void	wild_card(char *line, t_list *tokens)
{
	int		type;

	if (line[ft_strlen(line) - 1] == '/')
		type = 1;
	else
		type = 2;
	if (line[0] == '.' && line[1] && line[1] == '/')
	{
		opendir("./");
		card(line + 2, "./", type, tokens);
	}
	if (line[0] == '.' && line[1] && line[1] == '.' && line[2]
			&& line[2] == '/')
	{
		opendir("../");
		card(line + 3, "../", type, tokens);
	}
	else if (line[0] == '/')
	{
		opendir("/");
		card(line + 1, "/", type, tokens);
	}
	else if ((type = 3))
		card(line, "./", type, tokens);
}
