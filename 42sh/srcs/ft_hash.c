/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaublan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 19:01:18 by cmaublan          #+#    #+#             */
/*   Updated: 2014/06/20 20:03:18 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_hash.h"
#include "../includes/ft_env.h"
#include "../libft/libft.h"

void			ft_hash(t_sh *sh, char *path, char *cmd)
{
	record_paths(path, cmd, sh->paths);
}

void			record_paths(char *path, char *cmd, t_list **hash)
{
	unsigned long	indice;

	indice = get_hash(cmd);
	hash[indice] = record_path(path, hash[indice]);
}

unsigned long	get_hash(char *str)
{
	unsigned long	hash;
	int				c;

	hash = 5381;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;
	return (hash % SIZE_TABLE);
}

t_list			*record_path(char *path, t_list *hash)
{
	if (!hash)
	{
		hash = ft_list_init(hash);
		ft_list_add(hash, ft_list_new(path, ft_strlen(path)));
	}
	else
		ft_list_add(hash, ft_list_new(path, ft_strlen(path)));
	return (hash);
}

char			*get_path_cmd(t_sh *sh, char *cmd)
{
	t_elem			*elem;
	int				cpt[2];
	char			*path;

	if (!sh->paths[get_hash(cmd)])
		return (NULL);
	elem = sh->paths[get_hash(cmd)]->first;
	if (!elem->next)
		return ((char *)elem->value);
	path = (char *)elem->value;
	cpt[0] = ft_strlen(cmd);
	cpt[1] = ft_strlen(path);
	while (path[cpt[1]] != '/')
	{
		if (cmd[cpt[0]--] != path[cpt[1]--])
		{
			if (elem->next)
				elem = elem->next;
			else
				return (NULL);
			cpt[0] = ft_strlen(cmd);
			cpt[1] = ft_strlen(path);
		}
	}
	return ((char *)elem->value);
}
