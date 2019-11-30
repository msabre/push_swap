/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:05:49 by msabre            #+#    #+#             */
/*   Updated: 2019/11/29 20:56:56 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int		bonus_define(char **args, int count, t_values *val)
{
	char		*ptr;

	if (ft_strcmp(args[1], "-v") == 0 || ft_strcmp(args[1], "-vz") == 0)
		count++;
	if (args[2] != NULL &&
		(ft_strcmp(args[2], "-v") == 0 || ft_strcmp(args[2], "-vz") == 0))
		count++;
	if (count > 1)
		return (-1);
	if (ft_strcmp(args[1], "-v") == 0)
	{
		ptr = (val)->line;
		ft_chrfill(&ptr, '-', 45);
		val->v_flag = 1;
	}
	else if (ft_strcmp(args[1], "-vz") == 0)
	{
		ptr = (val)->bloc;
		ft_chrfill(&ptr, '-', 200);
		ptr = (val)->spaces;
		ft_chrfill(&ptr, ' ', 200);
		val->vz_flag = 1;
	}
	return (0);
}

int				main(int argc, char **args)
{
	t_values	val;
	int			*stack_a;
	int			size;

	stack_a = NULL;
	val.v_flag = 0;
	val.vz_flag = 0;
	if (argc == 1 || check_args(args, argc) == 0)
		return (ft_printf("Error\n"));
	if (ft_strcmp(args[1], "-v") == 0 || ft_strcmp(args[1], "-vz") == 0)
	{
		if (bonus_define(args, 0, &val) == -1)
			return (ft_printf("select only one key please\n"));
		if (argc == 2 || (argc == 3 && args[2][0] == '\0'))
			return (ft_printf("enter arguments\n"));
		args++;
	}
	size = parse_stack(args, &stack_a, 'p');
	val.size = size;
	val.pw = cn_power(size);
	if (size > 0)
		push_swap(stack_a, size, &val);
	else if (size < 0)
		ft_printf("Error\n");
	return (0);
}
