/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:35:26 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/09 04:15:39 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# define BUFF_SIZE 1
# define FT_PI 3.1415926535897932384626433832795

typedef struct		s_elem
{
	void			*value;
	int				size_value;
	int				selected;
	int				cursed;
	struct s_elem	*next;
	struct s_elem	*previous;
}					t_elem;

typedef struct		s_list
{
	t_elem			*first;
	t_elem			*last;
	int				size;
	int				max;
}					t_list;

void*				ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void*				ft_memcpy(void *s1, const void* s2, size_t n);
void*				ft_memccpy(void *s1, const void *s2, int c, size_t n);
void*				ft_memmove(void *s1, const void *s2, size_t n);
void*				ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char*				ft_strdup(const char *s);
char*				ft_strcpy(char *s1, const char *s2);
char*				ft_strncpy(char* s1, const char *s2, size_t n);
char*				ft_strcat(char *s1, const char *s2);
char*				ft_strncat(char* s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char*				ft_strchr(const char *s, int c);
char*				ft_strrchr(const char *s, int c);
char*				ft_strstr(const char *s1, const char *s2);
char*				ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void*				ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char*				ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char*				ft_strmap(char const *s, char (*f)(char));
char*				ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char*				ft_strsub(char const *s, unsigned int start, size_t len);
char*				ft_strjoin(char const *s1, char const *s2);
char*				ft_strtrim(char const *s);
char**				ft_strsplit(char const *s, char c);
char*				ft_itoa(int n);
int					ft_putchar(int c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

int					get_next_line(int const fd, char **line);
int					end_of_line(char *buffer1);
char*				ft_strjoin_for_gnl(char *s1, char *s2);
char*				ft_strsub_for_gnl(char *s, size_t len);

t_list				*ft_list_init(t_list *list);
void				ft_list_add(t_list *list, t_elem *new);
void				ft_list_push(t_list *list, t_elem *new);
t_elem				*ft_list_new(void *value, int size_value);
void				ft_list_swap(t_elem *elem1, t_elem *elem2);
void				ft_list_unpush(t_list *list);
void				ft_list_unadd(t_list *list);
void				ft_list_delone(t_list *list, t_elem *this);
void				ft_list_print(t_list *list, char *str);
void				ft_list_rprint(t_list *list, char *str);
/*
** Libftmath
** Implementation of the maths.h lib.
*/
unsigned int		ft_power(int number, int power);
long				ft_factorial(int number);
int					ft_max(int *sizes, int size);

#endif /* !LIBFT_H  */
