#include "../libft/libft.h"

int			main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	parse_arg(argv[1]);
}

t_list		*parse_arg(char *arg)
{
	t_list		*expr_left;
	t_list		*expr_right;
	int			right;
	int			i;
	int			symbol;

	right = 0;
	expr_left = ft_list_init();
	expr_right = ft_list_init();
	while (arg[i] != '\0')
	{
		if (arg[i] == ' ')
			i++;
		if (arg[i] == '=')
		{
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
				i = add_number(*arg, expr_right, i, symbol);
			else
				i = add_number(*arg, expr_left, i, symbol);
		}
	}
	reduced_form(expr_right, expr_left);
	return (expr_right);
}


int		add_number(char *arg, t_list *expr, int i, int symbol)
{
	t_number		num;
	t_elem			*elem;

	if (arg[i] != 'X')
		num.number = atof(arg + i) * symbol;
	else
		num.number = 1 * symbol;
	num.power = 0;
	while (isdigit(arg[i]) || arg[i] == '.' || is_whitespace(arg[i]))
		i++;
	while (arg[i] != '\0' && arg[i] != '=' && arg[i] != '+' && arg[i] != '-')
	{
		if (arg[i] == '*' || arg[i] == 'X')
			i = add_power(&num, i, arg);
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

void		reduced_form(t_list *expr_left, t_list *expr_right)
{
	t_elem		*elem;

	if (expr_right->size == 1
			&& ((t_number *)expr_right->first->value)->number == 0)
		return (expr_left);
	if (expr_left->size == 1
			&& ((t_number *)expr_left->first->value)->number == 0)
		return (expr->right);
	reduce_expr(expr_left);
	reduce_expr(expr_right);
	reduce_right_to_zero(expr_right, expr_left);
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
				ft_list_delone(tmp);
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

	elem_right = expr_right->first;
	while (elem_right)
	{
		num_right = (t_number *)elem_right->value;
		elem_left = expr_left->first;
		while (elem_left)
		{
			num_left = (t_number *)elem_left->value;
			if (num_left->power == num_right->power)
			{
				num_left->number += num_right->number;
				tmp = elem_right->left;
				ft_list_delone(expr_right, elem_right);
				break;
				elem_right = tmp;
			}
			elem_left = elem_left->next;
		}
		if (elem_left == NULL)
		{
			num_right *= -1;
			ft_list_add(expr_left, elem_right);
		}
		elem_right = elem_right->next;
	}
}


