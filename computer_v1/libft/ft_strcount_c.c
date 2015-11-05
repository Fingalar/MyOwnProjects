/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 21:05:19 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/14 21:08:09 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcount_c(char *str, char c)
{
	int		i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}