/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:37:58 by msabre            #+#    #+#             */
/*   Updated: 2020/07/01 15:02:09 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int				dupl_zero(int *stack_a, int size)
{
	int					i;
	int					count_z;

	i = 0;
	count_z = 0;
	while (i < size)
	{
		if (stack_a[i++] == 0)
		{
			count_z++;
			if (count_z > 1)
				return (1);
		}
	}
	return (0);
}

static int				check_order(int *stack, int **stack_a,
						int size, char programm)
{
	int					i;

	i = 0;
	if (dupl_zero(stack, size) == 1)
		return (-1);
	while (i < (size - 1))
	{
		if (stack[i] > stack[i + 1])
		{
			if (!(*stack_a = ft_digitmass_cpy(stack, size)))
				return (-1);
			return (size);
		}
		i++;
	}
	if (programm == 'c')
	{
		if (!(*stack_a = ft_digitmass_cpy(stack, size)))
			return (-1);
		return (size);
	}
	return (0);
}

static int				define_num(char ***a, int minus)
{
	char				*star;
	long				result;
	long				rank_count;

	star = **a;
	result = 0;
	while (***a >= 48 && ***a <= 57 && ***a != '\0')
		(**a)++;
	while (*star == '0' && *(star + 1) == '0' && *star)
		(star)++;
	if (***a != ' ' && ***a != '\0')
		exit(ft_printf("Error\n"));
	if (**a - star - 1 > 10)
		exit(ft_printf("Error\n"));
	rank_count = to_power(10, (**a - star - 1));
	while (rank_count > 0)
	{
		result += (*star - 48) * rank_count;
		star++;
		rank_count /= 10;
	}
	result *= (minus > 0) ? -1 : 1;
	if (result >= 2147483648 || result <= -2147483649)
		exit(ft_printf("Error\n"));
	return (result);
}

static int				check_minus(char ***a)
{
	int					minus;
	int					plus;

	minus = 0;
	plus = 0;
	while (!(***a >= 48 && ***a <= 57) && ft_memchr("+-", ***a, 2))
	{
		minus = (***a == '-') ? minus + 1 : minus;
		plus = (***a == '+') ? plus + 1 : plus;
		if ((plus && minus) || plus > 1 || minus > 1)
			return (-1);
		(**a)++;
	}
	if (!(***a >= 48 && ***a <= 57))
		return (-1);
	return (minus);
}

int						parse_stack(char **a, int **stack_a, char programm)
{
	int					stack[1500];
	int					minus;
	int					size;

	size = 0;
	a++;
	ft_bzero(stack, sizeof(int) * 1500);
	while (*a != NULL)
	{
		while (**a != '\0')
		{
			while (**a == ' ')
				(*a)++;
			if (**a == '\0')
				break ;
			if ((minus = check_minus(&a)) == -1)
				return (-1);
			stack[size++] = define_num(&a, minus);
		}
		a++;
	}
	size = check_order(stack, stack_a, size, programm);
	return (size);
}
