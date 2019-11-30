/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:31:49 by msabre            #+#    #+#             */
/*   Updated: 2019/11/29 20:55:58 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/headers/libft.h"

typedef	struct		s_values
{
	int				min;
	int				second_min;
	int				middle;
	int				max;
	int				size_a;
	int				size_b;
	int				v_flag;
	int				vz_flag;
	int				c_flag;
	int				size;
	int				pw;
	int				*order;
	int				miss_a;
	int				miss_b;
	char			bloc[200];
	char			line[46];
	char			spaces[200];
}					t_values;

typedef struct		s_actions
{
	int				a_pos;
	int				b_pos;
	int				move_a;
	int				move_b;
	t_values		*val;
}					t_actions;

typedef struct		s_stac
{
	int				value;
	int				pos;
	struct s_stac	*next;
	struct s_stac	*prev;
}					t_stac;

void				op_s(t_stac	**stack);
void				op_p(t_stac	**stack_a, t_stac **stack_b);
void				op_r(t_stac	**stack);
void				op_rr(t_stac **stack);
void				execute_together(t_stac **stack_a, t_stac **stack_b,
									void(function)(t_stac **));
int					parse_stack(char **a, int **stack_a, char programm);
void				select_op(t_stac **a, t_stac **b, char *op);
t_stac				*stack_as_list(int *stack_a, int *order, int size);
void				ft_vz(t_stac *a, t_stac *b, t_values *val,
					char *command);
void				ft_v(t_stac *a, t_stac *b, t_values *val,
					char *command);
void				insertion_sorting(t_stac **a, t_stac **b,
					t_values *val,
					int size);
void				sort_little_count(t_stac **a, t_stac **b,
					t_values *val, int size);
int					push_swap(int *stack_a, int size, t_values *val);
void				stack_op_output(t_stac **a, t_stac **b, t_values *val,
					char *command);
void				add_to_stack(t_stac **alst, t_stac *new);
void				free_stacklst(t_stac *stac);
int					*get_min_max_middle_values(t_values *val,
										int *stack_a, int size);
int					check_args(char **args, int argc);

#endif
