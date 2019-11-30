/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_output_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 23:32:23 by msabre            #+#    #+#             */
/*   Updated: 2019/11/26 17:58:24 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	stack_op_output(t_stac **a, t_stac **b, t_values *val, char *command)
{
	if (command[0] == 'p')
	{
		if (command[1] == 'a')
		{
			val->size_b--;
			val->size_a++;
		}
		else if (command[1] == 'b')
		{
			val->size_b++;
			val->size_a--;
		}
	}
	select_op(a, b, command);
	if (val->v_flag == 1)
		ft_v(*a, *b, val, command);
	else if (val->vz_flag == 1)
		ft_vz(*a, *b, val, command);
	else
		ft_printf("%s\n", command);
}
