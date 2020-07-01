/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_or_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 23:23:54 by msabre            #+#    #+#             */
/*   Updated: 2020/07/01 15:02:09 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void			define_mid_and_min(t_stac **a, int *middle, int *min)
{
	if (((*a)->next)->value > (*a)->value
		&& (*a)->value < ((*a)->prev)->value)
	{
		(*min) = (*a)->value;
		(*middle) = (((*a)->next)->value > ((*a)->prev)->value)
			? ((*a)->prev)->value : ((*a)->next)->value;
	}
	else if ((*a)->value > ((*a)->next)->value
			&& ((*a)->next)->value < ((*a)->prev)->value)
	{
		(*min) = ((*a)->next)->value;
		(*middle) = ((*a)->value > ((*a)->prev)->value)
			? ((*a)->prev)->value : (*a)->value;
	}
	else if (((*a)->prev)->value < ((*a)->next)->value
		&& ((*a)->prev)->value < (*a)->value)
	{
		(*min) = ((*a)->prev)->value;
		(*middle) = ((*a)->value > ((*a)->next)->value)
			? ((*a)->next)->value : (*a)->value;
	}
}

static void			sort_three_digit(t_stac **a, t_stac **b, t_values *values)
{
	int				min;
	int				middle;

	define_mid_and_min(a, &middle, &min);
	if ((*a)->value > ((*a)->next)->value && ((*a)->prev)->value == middle)
		stack_op_output(a, b, values, "ra");
	else if ((*a)->value < ((*a)->next)->value
		&& ((*a)->prev)->value == middle)
	{
		stack_op_output(a, b, values, "rra");
		stack_op_output(a, b, values, "sa");
	}
	else if ((*a)->value < ((*a)->next)->value
		&& ((*a)->prev)->value == min)
		stack_op_output(a, b, values, "rra");
	else if ((*a)->value > ((*a)->next)->value
		&& ((*a)->prev)->value == min)
	{
		stack_op_output(a, b, values, "sa");
		stack_op_output(a, b, values, "rra");
	}
	else if ((*a)->value > ((*a)->next)->value
			&& ((*a)->prev)->value != min
				&& ((*a)->prev)->value != middle)
		stack_op_output(a, b, values, "sa");
}

void				push_min_to_b(t_stac **a, t_stac **b, t_values *val)
{
	t_stac			*ptr;
	char			*command;
	int				steps;

	command = "ra";
	steps = 0;
	ptr = *a;
	while (ptr->value != val->min)
	{
		ptr = ptr->next;
		steps++;
	}
	if (steps > 2)
	{
		steps = val->size_a - steps;
		command = "rra";
	}
	while (steps > 0)
	{
		stack_op_output(a, b, val, command);
		steps--;
	}
	stack_op_output(a, b, val, "pb");
}

void				sort_little_count(t_stac **a, t_stac **b, t_values *val,
					int size)
{
	if (size == 5)
	{
		push_min_to_b(a, b, val);
		val->min = val->second_min;
		push_min_to_b(a, b, val);
	}
	sort_three_digit(a, b, val);
	if (size == 5)
	{
		stack_op_output(a, b, val, "pa");
		stack_op_output(a, b, val, "pa");
	}
}
