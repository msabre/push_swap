/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 23:28:10 by msabre            #+#    #+#             */
/*   Updated: 2019/11/29 16:16:27 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void		creat_stack_b(t_stac **a, t_stac **b,
				t_values *values, int size)
{
	int			digit;
	int			count;

	count = 0;
	while (count < size)
	{
		digit = (*a)->value;
		if (digit != values->max && digit != values->min)
		{
			stack_op_output(a, b, values, "pb");
			count++;
			if (digit >= values->middle)
				stack_op_output(a, b, values, "rb");
		}
		else
			stack_op_output(a, b, values, "ra");
	}
	if ((*a)->value != values->max)
		stack_op_output(a, b, values, "sa");
}

int				push_swap(int *stack_a, int size, t_values *val)
{
	t_stac		*a;
	t_stac		*b;

	b = NULL;
	val->size_a = size;
	val->size_b = 0;
	if (!(stack_a = get_min_max_middle_values(val, stack_a, size)))
		return (-1);
	if (!(a = stack_as_list(stack_a, val->order, size)))
	{
		free_stacklst(a);
		return (-1);
	}
	if (val->vz_flag == 1)
		ft_vz(a, b, val, "");
	if (size == 5 || size == 3)
		sort_little_count(&a, &b, val, size);
	else
	{
		creat_stack_b(&a, &b, val, (size - 2));
		insertion_sorting(&a, &b, val, size);
	}
	free_stacklst(a);
	return (1);
}
