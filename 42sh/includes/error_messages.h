/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 19:17:51 by tmertz            #+#    #+#             */
/*   Updated: 2014/06/22 19:40:13 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H
# include "../libft/libft.h"

int		ft_nofile(char *file);
int		ft_parse_error(char c);
int		ft_too_much_parenthesis(void);
int		ft_badly_placed_parenthesis(void);
int		ft_invalid_null_cmd(void);
int		ft_missing_name_redirect(void);
int		ft_unmatched_quote(char c);
int		ft_anbiguous_redirect_out(void);
int		ft_anbiguous_redirect_in(void);
int		ft_cmd_not_found(char *cmd);
int		ft_puterror_nofile(char *arg);
int		ft_puterror_nopermission(char *arg);
int		ft_puterror_notdir(char *arg);
int		ft_puterror_noenv(void);
int		illegal_option(char flag);

#endif
