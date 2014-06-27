/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:55:59 by hvillain          #+#    #+#             */
/*   Updated: 2014/05/12 15:57:49 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		only_wild(char *s)
{
	if (s[0] == '*' && !s[1])
		return (1);
	return (0);
}

int		match(char *s1, char *s2)
{
	if (only_wild(s2))
		return (1);
	if (*s1 && *s2 == '?')
		return (match(s1 + 1, s2 + 1));
	if (*s1 == '\0' && *s2 != *s1 && *s2 != '*')
		return (0);
	if (*s1 == '\0' && *s1 == *s2)
		return (1);
	else if (*s1 == *s2)
		return (match(s1 + 1, s2 + 1));
	else if (*s1 == '\0' && *s2 == '*')
		return (match(s1, s2 + 1));
	else if (*s2 == '*' && *(s2 + 1) == '*')
		return (match(s1, s2 + 1));
	else if (*s2 == '*' && *s1 != '\0')
	{
		if (match(s1, s2 + 1) || match(s1 + 1, s2) || match(s1 + 1, s2 + 1))
			return (1);
	}
	return (0);
}
