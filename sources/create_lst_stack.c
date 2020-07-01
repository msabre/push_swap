/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:42:03 by msabre            #+#    #+#             */
/*   Updated: 2020/07/01 15:02:09 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			add_to_stack(t_stac **alst, t_stac *new)
{
	t_stac		*ptr;

	ptr = *alst;
	if (!ptr)
	{
		*alst = new;
		(*alst)->prev = NULL;
	}
	else
	{
		if (ptr->prev != NULL)
			ptr = ptr->prev;
		ptr->next = new;
		new->next = NULL;
		new->prev = ptr;
		(*alst)->prev = new;
	}
}

t_stac			*stack_as_list(int *stack_a, int *order, int size)
{
	t_stac		*lst_stac;
	t_stac		*cur_value;
	int			i;
	int			pos;

	i = 0;
	lst_stac = NULL;
	while (i < size)
	{
		if (!(cur_value = (t_stac*)malloc(sizeof(t_stac))))
			return (NULL);
		pos = 0;
		cur_value->value = stack_a[i];
		cur_value->next = NULL;
		while (cur_value->value != order[pos])
			pos++;
		cur_value->pos = pos + 1;
		add_to_stack(&lst_stac, cur_value);
		i++;
	}
	free(order);
	free(stack_a);
	return (lst_stac);
}
