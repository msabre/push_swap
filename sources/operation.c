/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:34:15 by msabre            #+#    #+#             */
/*   Updated: 2020/07/01 15:02:09 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			op_rr(t_stac **stack)
{
	t_stac		*new_first;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	new_first = (*stack)->prev;
	new_first->next = *stack;
	(new_first->prev)->next = NULL;
	(*stack)->prev = new_first;
	*stack = new_first;
}

void			op_r(t_stac **stack)
{
	t_stac		*new_first;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	new_first = (*stack)->next;
	(*stack)->next = NULL;
	((*stack)->prev)->next = *stack;
	*stack = new_first;
}

void			op_p(t_stac **stack_a, t_stac **stack_b)
{
	t_stac		*ptr;

	if (!(*stack_a))
		return ;
	ptr = (*stack_a)->next;
	if (ptr)
		ptr->prev = (*stack_a)->prev;
	(*stack_a)->next = (*stack_b != NULL) ? *stack_b : NULL;
	(*stack_a)->prev = (*stack_b != NULL) ? (*stack_b)->prev : NULL;
	(*stack_b != NULL) ? (*stack_b)->prev = (*stack_a) : NULL;
	*stack_b = *stack_a;
	if ((*stack_b)->next && ((*stack_b)->next)->next == NULL)
		(*stack_b)->prev = (*stack_b)->next;
	*stack_a = ptr;
}

void			op_s(t_stac **stack)
{
	t_stac		*ptr;

	if (!(*stack && (*stack)->next))
		return ;
	ptr = (*stack)->next;
	(*stack)->next = ptr->next;
	ptr->next = *stack;
	ptr->prev = ((*stack)->next != NULL) ? (*stack)->prev : *stack;
	if ((*stack)->next != NULL)
		((*stack)->next)->prev = *stack;
	(*stack)->prev = ptr;
	*stack = ptr;
}

void			execute_together(t_stac **stack_a,
				t_stac **stack_b, void (f)(t_stac **))
{
	f(stack_a);
	f(stack_b);
}
