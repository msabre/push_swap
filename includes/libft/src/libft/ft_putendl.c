/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 02:01:30 by andrejskobe       #+#    #+#             */
/*   Updated: 2019/10/30 22:51:10 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_putendl(char const *s)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
		ft_putchar(s[i++]);
	ft_putchar('\n');
}
