/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:55:05 by msabre            #+#    #+#             */
/*   Updated: 2019/11/27 22:33:35 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		select_op(t_stac **a, t_stac **b, char *op)
{
	if (ft_strcmp("sa", op) == 0)
		op_s(a);
	else if (ft_strcmp("sb", op) == 0)
		op_s(b);
	else if (ft_strcmp("ss", op) == 0)
		execute_together(a, b, op_s);
	else if (ft_strcmp("pa", op) == 0)
		op_p(b, a);
	else if (ft_strcmp("pb", op) == 0)
		op_p(a, b);
	else if (ft_strcmp("ra", op) == 0)
		op_r(a);
	else if (ft_strcmp("rb", op) == 0)
		op_r(b);
	else if (ft_strcmp("rr", op) == 0)
		execute_together(a, b, op_r);
	else if (ft_strcmp("rra", op) == 0)
		op_rr(a);
	else if (ft_strcmp("rrb", op) == 0)
		op_rr(b);
	else if (ft_strcmp("rrr", op) == 0)
		execute_together(a, b, op_rr);
	else
		exit(ft_printf("Error\n"));
}
