/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 02:44:27 by andrejskobe       #+#    #+#             */
/*   Updated: 2019/10/30 23:00:37 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		len;
	char	*ptr;

	len = 0;
	i = 0;
	if (s && f)
	{
		while (s[len] != '\0')
			len++;
		if (!(ptr = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (s[i] != '\0')
		{
			ptr[i] = f(s[i]);
			i++;
		}
		ptr[i] = '\0';
	}
	else
		return (NULL);
	return (ptr);
}
