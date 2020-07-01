/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 23:15:56 by msabre            #+#    #+#             */
/*   Updated: 2020/07/01 15:02:14 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		output_alig(int a_size, int b_size, int size)
{
	int			cr;

	if (a_size >= b_size)
		cr = size - a_size;
	else if (b_size > a_size)
		cr = size - b_size;
	else
		cr = 0;
	while (cr > 0)
	{
		ft_printf("\n");
		cr--;
	}
}

static void		b_side_output(t_stac **b, t_values *val, int len, int *b_size)
{
	const char	*format;
	int			sp;

	ft_printf("%.*s", len, val->spaces);
	if ((sp = val->pw - cn_power((*b)->pos)) > 0)
		ft_printf("%.*s", sp, val->spaces);
	if (*b && (*b)->next && (((*b)->next)->pos - (*b)->pos == 1))
		format = "\033[01;38;05;35m%d %.*s\033[0m\n";
	else if (*b && (*b)->prev && ((*b)->pos - ((*b)->prev)->pos == 1))
		format = "\033[01;38;05;35m%d %.*s\033[0m\n";
	else
		format = "%d %.*s\n";
	ft_printf(format, (*b)->pos, (*b)->pos, val->bloc);
	*b = (*b)->next;
	(*b_size)--;
}

static int		a_side_output(t_stac **a, t_values *val,
				int *a_size, int *b_size)
{
	const char	*format;
	int			sp;
	int			len;

	len = 0;
	if ((*a)->pos == val->size_a + val->size_b)
		format = "\033[01;38;05;196m%d %.*s\033[0m";
	else if (*a && (*a)->next && (((*a)->next)->pos - (*a)->pos == 1))
		format = "\033[01;38;05;35m%d %.*s\033[0m";
	else if (*a && (*a)->prev && ((*a)->pos - ((*a)->prev)->pos == 1))
		format = "\033[01;38;05;35m%d %.*s\033[0m";
	else
		format = "%d %.*s";
	if ((sp = val->pw - cn_power((*a)->pos)) > 0)
		len = ft_printf("%.*s", (sp), val->spaces);
	len += ft_printf(format, (*a)->pos, (*a)->pos, val->bloc);
	if (*format == '\033')
		len -= ((*a)->pos == val->size) ? 19 : 18;
	if (*a_size > *b_size)
		ft_printf("\n");
	*a = (*a)->next;
	(*a_size)--;
	return (len);
}

void			ft_vz(t_stac *a, t_stac *b, t_values *val, char *command)
{
	const char	*speed;
	int			len;
	int			sz;
	int			a_size;
	int			b_size;

	speed = (val->size < 70) ? "sleep 0.07" : "sleep 0.01";
	a_size = val->size_a;
	b_size = val->size_b;
	sz = val->size + 30;
	system(speed);
	system("clear");
	output_alig(a_size, b_size, val->size);
	while (a_size > b_size && a)
		a_side_output(&a, val, &a_size, &b_size);
	while (a_size < b_size && b)
		b_side_output(&b, val, sz, &b_size);
	while (b_size > 0 && a_size > 0 && a && b)
	{
		len = a_side_output(&a, val, &a_size, &b_size);
		b_side_output(&b, val, (sz - len), &b_size);
	}
	ft_printf("CMD: %s", command);
}

void			ft_v(t_stac *a, t_stac *b, t_values *val, char *command)
{
	ft_printf("%s\n", val->line);
	ft_printf("Command - %s\n", command);
	ft_printf("%s", "STACK A: [ ");
	if (a != NULL)
	{
		while (a->next != NULL)
		{
			ft_printf("%d | ", a->value);
			a = a->next;
		}
		ft_printf("%d ", a->value);
	}
	ft_printf("]\n\n%s", "STACK B: [ ");
	if (b != NULL)
	{
		while (b->next != NULL)
		{
			ft_printf("%d | ", b->value);
			b = b->next;
		}
		ft_printf("%d ", b->value);
	}
	ft_printf("]\n\n");
}
