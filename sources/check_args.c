/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 20:56:45 by msabre            #+#    #+#             */
/*   Updated: 2020/07/01 15:02:09 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_args(char **args, int argc)
{
	int			j;
	int			i;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (args[i][j] != '\0')
		{
			if (args[i][j] > 32 && args[i][j] < 127)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}