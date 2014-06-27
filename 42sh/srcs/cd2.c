/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 16:38:23 by tmertz            #+#    #+#             */
/*   Updated: 2014/06/20 16:40:20 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cd.h"

int		check_if_nullvar1(t_sh *sh, int i, int k)
{
	if (sh->env[k] == NULL)
	{
		sh->env[k] = ft_strdup(sh->oldpwd);
		sh->env[k + 1] = 0;
	}
	i = (i == k) ? i + 1 : i;
	if (sh->env[i] == NULL)
	{
		sh->env[i] = ft_strdup(sh->pwd);
		sh->env[i + 1] = 0;
	}
	return (i);
}

int		check_if_nullvar2(t_sh *sh, int i, int j)
{
	if (sh->env[j] == NULL)
	{
		sh->env[j] = ft_strdup(sh->oldpwd);
		sh->env[j + 1] = 0;
	}
	i = (i == j) ? i + 1 : i;
	if (sh->env[i] == NULL)
	{
		sh->env[i] = ft_strdup(sh->home);
		sh->env[i + 1] = 0;
	}
	return (i);
}
