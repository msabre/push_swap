/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:10:43 by msabre            #+#    #+#             */
/*   Updated: 2019/11/30 16:24:55 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static t_stac	*creat_lst(int *stack_a, int size)
{
	t_stac		*lst_stac;
	t_stac		*cur_value;
	int			i;
	int			pos;

	i = 0;
	pos = 0;
	lst_stac = NULL;
	while (i < size)
	{
		if (!(cur_value = (t_stac*)malloc(sizeof(t_stac))))
			break ;
		cur_value->value = stack_a[i];
		cur_value->next = NULL;
		cur_value->pos = pos++;
		add_to_stack(&lst_stac, cur_value);
		i++;
	}
	free(stack_a);
	return ((cur_value != NULL) ? lst_stac : NULL);
}

static int		check_order_lst(int size, t_stac *a, t_stac *b)
{
	int			i;

	i = 0;
	if (b != NULL)
	{
		free_stacklst(b);
		return (1);
	}
	while (i < (size - 1))
	{
		if (a->value > (a->next)->value)
			return (1);
		a = a->next;
		i++;
	}
	return (0);
}

static void		checker(int *stack_a, int size, t_values *val)
{
	t_stac		*a;
	t_stac		*b;
	char		*op;

	if (stack_a != NULL)
	{
		if (!(stack_a = get_min_max_middle_values(val, stack_a, size)))
			return ;
		if (!(a = creat_lst(stack_a, size)))
		{
			free_stacklst(a);
			return ;
		}
		free(val->order);
	}
	b = NULL;
	while (get_next_line(0, &op) == 1)
	{
		select_op(&a, &b, op);
		(val->v_flag == 1) ? ft_v(a, b, val, op) : NULL;
		free(op);
	}
	(check_order_lst(size, a, b) == 0) ? ft_printf("OK\n") : ft_printf("KO\n");
	free_stacklst(a);
}

static void		v_def(char ***argv, t_values *val)
{
	char		*ptr;

	if (ft_strcmp((*argv)[1], "-v") == 0)
	{
		(*argv)++;
		ptr = val->line;
		ft_chrfill(&ptr, '-', 45);
		val->v_flag = 1;
	}
	else
		val->v_flag = 0;
}

int				main(int argc, char **argv)
{
	t_values	val;
	int			*stack_a;
	int			size;

	size = -2;
	stack_a = NULL;
	if (argc == 1 || check_args(argv, argc) == 0)
		return (0);
	v_def(&argv, &val);
	(argc >= 2) ? size = parse_stack(argv, &stack_a, 'c') : 1;
	if (size == -1)
	{
		ft_printf("Error\n");
		return (0);
	}
	checker(stack_a, size, &val);
	return (0);
}
