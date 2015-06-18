#include "computer_v1.h"
#include <stdlib.h>
#include <math.h>

int			main(int argc, char **argv)
{
	t_list 		*expr;

	if (argc != 2)
		return (1);
	expr = parse_arg(argv[1]);
	resolve_polynomial(expr);
}

void		resolve_polynomial(t_list *expr)
{
	t_elem 		*elem;
	int		max;
	t_number	*value;

	elem = expr->first;
	value = ((t_number *)elem->value);
	max = value->power;
	while (elem != NULL)
	{
		value = ((t_number *)elem->value);
		if (value->power > max && value->number != 0)
			max = value->power;
		elem = elem->next;
	}
//	if (max == 1)
//		resolve_equation();
	if (max == 2)
		find_discriminant_then_resolve(expr);
}

void		find_discriminant_then_resolve(t_list *expr)
{
	double		discriminant;
	t_elem 		*elemA;
	t_elem 		*elemB;
	t_elem 		*elemC;

	elemA = expr->first;
	elemB = elemA->next;
	elemC = elemB->next;
	discriminant = ((t_number *)elemB->value)->number 
		* ((t_number *)elemB->value)->number - 4.0
		* (((t_number *)elemA->value)->number 
		* ((t_number *)elemC->value)->number);
	//if (discrimant == 0)
	//	display_single_solution(expr);
	if (discriminant > 0)
		display_two_solutions((t_number *)elemA->value, (t_number *)elemB->value, discriminant);
	//if (discriminant < 0)
	//	no_solution();
}

void		display_two_solutions(t_number *a, t_number *b, double discrimiant)
{
	double		solution1;
	double		solution2;

	solution1 = ((b->number * -1.0) - ft_sqrt(a->number)) / (a->number * 2.0);
	solution2 = ((b->number * -1.0) + ft_sqrt(a->number)) / (a->number * 2.0);
	printf("Discriminant is strictly positive, the two solutions are:\n");
	printf("%.3g\n%.3g\n", solution1, solution2);
}

int		is_whitespace(char c)
{
	if (c == '\t' || c == ' ' || c == '\n')
	{
		return (1);	
	}
	return (0);
}

t_list		*parse_arg(char *arg)
{
	t_list		*expr_left;
	t_list		*expr_right;
	int			right;
	int			i;
	int			symbol;

	i = 0;
	symbol = PLUS;
	right = 0;
	expr_left = ft_list_init(expr_left);
	expr_right = ft_list_init(expr_right);
	while (arg[i] != '\0')
	{
		if (arg[i] == ' ')
			i++;
		if (arg[i] == '=')
		{
			symbol = PLUS;
			right = 1;
			i++;
		}
		else if (arg[i] == '-')
		{
			symbol = MINUS;
			i++;
		}
		else if (arg[i] == '+')
		{
			symbol = PLUS;
			i++;
		}
		else
		{
			if (right == 0)
				i = add_number(arg, expr_right, i, symbol);
			else
				i = add_number(arg, expr_left, i, symbol);
		}
	}
	expr_left = reduced_form(expr_right, expr_left);
	return (expr_left);
}


int		add_number(char *arg, t_list *expr, int i, int symbol)
{
	t_number		*num;
	t_elem			*elem;
	char			*str;
	int			j;

	j = i;
	num = ft_memalloc(sizeof(t_number));
	if (arg[i] != 'X')
	{
		while (isdigit(arg[i]) || arg[i] == '.')
			i++;
		str = ft_strsub(arg, j, i -j);
		num->number = atof(str) * symbol;
		free(str);
	}
	else
		num->number = 1 * symbol;
	num->power = 0;
	while (isdigit(arg[i]) || arg[i] == '.' || is_whitespace(arg[i]))
		i++;
	while (arg[i] != '\0' && arg[i] != '=' && arg[i] != '+' && arg[i] != '-')
	{
		if (arg[i] == '*' || arg[i] == 'X')
			i = add_power(num, i, arg);
		else
			i++;
	}
	if (arg[i] != '\0')
		i--;
	elem = ft_list_new(num, sizeof(t_number));
	ft_list_add(expr, elem);
	return (i);
}


int		add_power(t_number *num, int i, char *arg)
{
	while (arg[i] != 'X')
		i++;
	if (arg[i + 1] == '^')
	{
		num->power = arg[i + 2] - '0';
		i += 2;
	}
	else
		num->power = 1;
	return (i);
}

t_list		*reduced_form(t_list *expr_left, t_list *expr_right)
{
	t_elem		*elem;

	if (expr_right->size == 1
			&& ((t_number *)expr_right->first->value)->number == 0)
	{
		display_reduced_form(expr_left);
		return (expr_left);
	}
	if (expr_left->size == 1
			&& ((t_number *)expr_left->first->value)->number == 0)
	{
		display_reduced_form(expr_right);
		return (expr_right);
	}
	reduce_expr(expr_left);
	reduce_expr(expr_right);
	reduce_right_to_zero(expr_right, expr_left);
	display_reduced_form(expr_left);
	return (expr_left);
}

void		reduce_expr(t_list *expr)
{
	t_elem		*elem;
	t_elem		*tmp;
	t_elem		*tmp2;
	t_number	*num;

	elem = expr->first;
	while (elem != NULL)
	{
		num = elem->value;
		tmp = elem->next;
		while (tmp != NULL)
		{
			if (((t_number *)tmp->value)->power == num->power)
			{
				num->number += ((t_number *)tmp->value)->number;
				tmp2 = tmp->next;
				ft_list_delone(expr, tmp);
				tmp = tmp2;
			}
			else
				tmp = tmp->next;
		}
		elem = elem->next;
	}
}

void		reduce_right_to_zero(t_list *expr_right, t_list *expr_left)
{
	t_elem		*elem_right;
	t_elem		*tmp;
	t_elem		*elem_left;
	t_number	*num_right;
	t_number	*num_left;
	int		reduced;

	elem_right = expr_right->first;
	while (elem_right)
	{
		reduced = 0;
		num_right = (t_number *)elem_right->value;
		elem_left = expr_left->first;
		while (elem_left)
		{
			num_left = (t_number *)elem_left->value;
			if (num_left->power == num_right->power)
			{
				num_left->number -= num_right->number;
				tmp = elem_right->next;
				ft_list_delone(expr_right, elem_right);
				break;
				elem_right = tmp;
				reduced = 1;
			}
			elem_left = elem_left->next;
		}
		if (elem_left == NULL)
		{
			num_right->number *= 1;
			elem_right->previous->next = elem_right->next;
			elem_right->next->previous = elem_right->previous;
			ft_list_add(expr_left, elem_right);
		}
		if (!reduced) 
			elem_right = elem_right->next;
	}
}


void	display_reduced_form(t_list *expr)
{
	t_elem		*elem;
	t_number	*value;

	sort_expr(expr);
	printf("Reduced form : ");
	elem = expr->first;
	while(elem != NULL)
	{
		value = ((t_number *)elem->value);
		if (elem != expr->first)
			printf(" + ");
		printf("%.2g", value->number);
		if (value->power >= 1)
			printf("X");
		if (value->power >= 2)
			printf("^%d", value->power);
		elem = elem->next;
	}
	printf(" = 0\n");
	display_degree(expr);
}


void	sort_expr(t_list *expr)
{
	t_elem		*elem;
	t_elem		*elem2;

	elem = expr->first;
	while (elem != NULL)
	{
		elem2 = expr->first->next;
		while (elem2 != NULL)
		{
			if (((t_number *)elem2->value)->power > ((t_number *)elem->value)->power)
			{
				swap_numbers(elem, elem2);	
			}
			elem2 = elem2->next;
		}
		elem = elem->next;
	}
}

void		swap_numbers(t_elem *elem, t_elem *elem2)
{
	int		pow;
	double		nbr;
	
	pow = ((t_number *)elem2->value)->power;
	nbr = ((t_number *)elem2->value)->number;
	((t_number *)elem2->value)->power = ((t_number *)elem->value)->power;
	((t_number *)elem2->value)->number = ((t_number *)elem->value)->number;
	((t_number *)elem2->value)->power = pow;
	((t_number *)elem2->value)->number = nbr;
}

void		display_degree(t_list *expr)
{
	t_elem 		*elem;
	int		max;
	t_number	*value;

	elem = expr->first;
	value = ((t_number *)elem->value);
	max = value->power;
	while (elem != NULL)
	{
		value = ((t_number *)elem->value);
		if (value->power > max && value->number != 0)
			max = value->power;
		elem = elem->next;
	}
	printf("Polynomial degree: %d\n", max);			
	if (max >= 3)
	{
		printf("Polynomial degree est greater than 2, i can't solve it\n");
		exit(0);
	}
}

