#ifndef COMPUTER_V1
# define COMPUTER_V1

# define PLUS 1
# define MINUS -1
# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_number
{
	double		number;
	int			power;
}				t_number;


t_list		*parse_arg(char *arg);
int		add_number(char *arg, t_list *expr, int i, int symbol);
int		add_power(t_number *num, int i, char *arg);
t_list		*reduced_form(t_list *expr_left, t_list *expr_right);
void		reduce_expr(t_list *expr);
void		reduce_right_to_zero(t_list *expr_right, t_list *expr_left);
void	display_reduced_form(t_list *expr);
void	sort_expr(t_list *expr);
void		swap_numbers(t_elem *elem, t_elem *elem2);
void		display_degree(t_list *expr);
void		display_two_solutions(t_number *a, t_number *b, double discrimiant);
void		find_discriminant_then_resolve(t_list *expr);
void		resolve_polynomial(t_list *expr);
double		ft_sqrt(double nb);
#endif
