/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:38:38 by msabre            #+#    #+#             */
/*   Updated: 2020/07/01 15:34:16 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		free_stacklst(t_stac *stac)
{
	t_stac	*ptr;

	if (!stac)
		return ;
	while (stac != NULL)
	{
		ptr = stac->next;
		free(stac);
		stac = ptr;
	}
}
