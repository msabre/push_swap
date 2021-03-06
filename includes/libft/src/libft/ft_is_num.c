/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:51:56 by msabre            #+#    #+#             */
/*   Updated: 2019/10/30 22:50:09 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int		ft_isnum(char c, int exception)
{
	if (c >= 48 && c <= 57)
	{
		if (c != exception + 48)
			return (1);
	}
	return (0);
}
