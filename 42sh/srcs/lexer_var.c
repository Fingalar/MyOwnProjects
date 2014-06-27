/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 15:58:12 by tmertz            #+#    #+#             */
/*   Updated: 2014/06/19 16:01:05 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"
#include "../includes/lexing_tools.h"

int			looking_for_var(t_word **w, char *var, t_sh *sh)
{
	int		k;
	t_elem	*vars;

	k = 0;
	while (sh->env[k])
	{
		if (!ft_strncmp(var, sh->env[k], ft_strlen(var)))
		{
			(*w)->var = ft_strdup(sh->env[k] + (ft_strlen(var) + 1));
			return (1);
		}
		k++;
	}
	vars = sh->var->first;
	while (vars)
	{
		if (!ft_strcmp(var, ((t_var *)vars->value)->name))
		{
			(*w)->var = ft_strdup(((t_var *)vars->value)->value);
			return (1);
		}
		vars = vars->next;
	}
	return (0);
}

int			check_if_variable(t_word **w, char *line, int *i, t_sh *sh)
{
	char	*var;
	int		j;

	*i = *i + 1;
	var = ft_memalloc(sizeof(char) * (ft_strlen(line) - *i + 1));
	j = 0;
	while (line[*i] && ft_isletter(line[*i]) && line[*i] != '"'
			&& line[*i] != '\'')
		var[j++] = line[(*i)++];
	(*w)->var = ft_strdup(var);
	return (looking_for_var(w, var, sh));
}
