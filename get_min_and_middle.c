/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_and_middle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 20:47:24 by msabre            #+#    #+#             */
/*   Updated: 2019/11/29 16:19:27 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int		check_duplicates(const int *stack_a, int size)
{
	int			i;

	i = 0;
	while (i < (size - 1))
	{
		if (stack_a[i] == stack_a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int				*get_min_max_middle_values(t_values *val, int *stack_a,
				int size)
{
	int			*ptr;
	int			i;

	i = 0;
	if (!(ptr = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	while (i < size)
	{
		ptr[i] = stack_a[i];
		i++;
	}
	quick_sort(stack_a, 0, size - 1);
	val->order = stack_a;
	if (check_duplicates(stack_a, size) == 1)
	{
		free(stack_a);
		free(ptr);
		ft_printf("Error\n");
		return (NULL);
	}
	val->min = stack_a[0];
	val->second_min = (size == 1) ? stack_a[0] : stack_a[1];
	val->middle = stack_a[size / 2];
	val->max = stack_a[size - 1];
	return (ptr);
}
