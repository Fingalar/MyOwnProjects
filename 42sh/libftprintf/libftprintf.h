/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 21:37:12 by tmertz            #+#    #+#             */
/*   Updated: 2015/02/15 14:03:21 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <string.h>
# include <stdarg.h>
# include "../libft/libft.h"

char	*ft_strrev(char *str);

char	*ft_printf_replace_by_adresse(va_list *arg, char *split, int i);
char	*ft_printf_replace_by_char(va_list *arg, char *split, int i);
char	*ft_printf_replace_by_string(va_list *arg, char *split, int i);
char	*ft_printf_replace_by_int(va_list *arg, char *split, int i);
char	*ft_printf_replace_by_long(va_list *arg, char *split, int i);
char	*ft_printf_replace_by_long_int(va_list *arg, char *split, int i);
char	*ft_printf_replace_by_longlong_int(va_list *arg, char *split, int i);
char	*ft_printf_convert_base(va_list *arg, char *split, int i, int base);
char	*ft_printf_replace_by_percent(char *split);

int		ft_printf_count_return_value(char **split_tab);
char	*ft_printf_parser(const char *format);
char	*ft_printf_which_replace(va_list *arg, char *split, char flag, int i);
char	*ft_printf_replace_arg(va_list *arg, char *split);
int		ft_printf(const char *format, ...)
	__attribute__((format(printf, 1 ,2)));

char	*ft_printf_number_before_d(int i, int j, va_list* arg, char *split);
char	*ft_printf_number_before_ld(int i, int j, va_list* arg, char *split);
char	*ft_printf_number_before_lld(int i, int j, va_list* arg, char *split);
char	*ft_printf_number_before_c(int i, int j, va_list* arg, char *split);
char	*ft_printf_number_before_s(int i, int j, char *str, char *split);
char	*ft_printf_spaces_before_plus(char *split, char *stock, int nbr);
char	*ft_printf_spaces_before_nbr(char *split, char *stock, int nbr);
char	*ft_printf_spaces_after_nbr(char *split, char *stock, int nbr);
char	*ft_printf_zeros_before_nbr(char *split, char *stock, int nbr);
char	*ft_printf_spaces_after_str(char *split, char *str, char *stock);
char	*ft_printf_spaces_before_str(char *split, char *str, char *stock);
char	*ft_printf_only_x_char_for_s(char *str, char *stock);

#endif
