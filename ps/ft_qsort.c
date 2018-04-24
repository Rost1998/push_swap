/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 12:53:31 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/02 19:10:54 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define SHIFT_RIGHT 0
#define SHIFT_LEFT 1

static void		repushing_a(t_list **stack_a, t_list **stack_b, t_vars *vars)
{
	int		q;
	int		half;
	int		go_rra;

	q = 0;
	half = (vars->parts_a)[0] % 2 ? (vars->parts_a)[0] / 2 + 1 :\
									(vars->parts_a)[0] / 2;
	vars->piv = ft_getmed(*stack_a, (vars->parts_a)[0]);
	shift_part_b(vars, SHIFT_RIGHT);
	vars->need_rev = !(vars->parts_b)[1] ? ft_isrev(*stack_a) : 0;
	go_rra = ft_isuseful_rrr(*stack_a, vars->piv, 0);
	while (half)
	{
		if (go_rra && *(int*)((ft_lstn(*stack_a,\
							ft_lstlen(*stack_a)))->content) <= vars->piv)
			get_rev_rotate(stack_a, vars, "rra\n");
		if (*(int*)((*stack_a)->content) <= vars->piv &&\
				((vars->parts_a)[0])-- && ++((vars->parts_b)[0]) && half--)
			ft_kost(stack_a, stack_b, vars);
		else if (++q)
			get_rotate(stack_a, vars, "ra\n");
	}
	if ((vars->parts_a)[0] != (int)ft_lstlen(*stack_a))
		while (q--)
			get_rev_rotate(stack_a, vars, "rra\n");
}

static void		pushing_remainder_b(t_list **stack_a, t_list **stack_b,\
																t_vars *vars)
{
	while (((vars->parts_b)[0])-- && ++((vars->parts_a)[0]))
	{
		if ((vars->parts_b)[0] >= 1 && *(int*)((*stack_b)->content) <\
								*(int*)((*stack_b)->next->content))
			get_swap(stack_b, vars, "sb\n");
		if ((*stack_a)->next && *(int*)((*stack_a)->content) >\
				*(int*)((*stack_a)->next->content))
			get_swap(stack_a, vars, "sa\n");
		get_push(stack_a, stack_b, vars, "pa\n");
	}
	ft_sort3(stack_a, vars);
	shift_part_b(vars, SHIFT_LEFT);
}

static void		return_of_repush_b(t_list **stack_a, t_list **stack_b,\
														t_vars *vars, int q)
{
	if ((vars->parts_b)[1])
		while (q--)
		{
			get_rev_rotate(stack_b, vars, "rrb\n");
			if (!ft_isbetween(*stack_a, *stack_b,\
				*(int*)((*stack_b)->content), *(int*)((*stack_a)->content)) &&\
					((vars->parts_b)[0])-- && ((vars->parts_a)[0])++)
				get_push(stack_a, stack_b, vars, "pa\n");
		}
	if ((vars->parts_b)[0] <= 0)
		shift_part_b(vars, SHIFT_LEFT);
}

static void		repushing_b(t_list **stack_a, t_list **stack_b, t_vars *vars,\
																		int q)
{
	int		i;
	int		go_rrb;
	int		half;

	i = (vars->parts_b)[0];
	half = (vars->parts_b)[0] / 2;
	vars->piv = ft_getmed(*stack_b, (vars->parts_b)[0]);
	go_rrb = ft_isuseful_rrr(*stack_b, vars->piv, 1);
	while (i-- > 0 && half)
	{
		if (go_rrb && *(int*)((ft_lstn(*stack_b,\
						ft_lstlen(*stack_b)))->content) > vars->piv)
			get_rev_rotate(stack_b, vars, "rrb\n");
		if (!ft_random_sort(*stack_b, (vars->parts_b)[0], 0))
			while (i-- && ++q)
				get_rotate(stack_b, vars, "rb\n");
		if ((*(int*)((*stack_b)->content) > vars->piv) &&\
				((vars->parts_b)[0])-- && ++((vars->parts_a)[0]) && half--)
			get_push(stack_a, stack_b, vars, "pa\n");
		else if (++q)
			get_rotate(stack_b, vars, "rb\n");
		ft_isneed_swap(stack_a, stack_b, vars);
	}
	return_of_repush_b(stack_a, stack_b, vars, q);
}

int				ft_qsort(t_list **stack_a, t_list **stack_b, t_vars *vars)
{
	if (ft_random_sort(*stack_a, (vars->parts_a)[0], 0))
	{
		while ((vars->parts_a)[0] > 3)
			repushing_a(stack_a, stack_b, vars);
		ft_sort3(stack_a, vars);
	}
	(vars->parts_a)[0] = 0;
	if (ft_random_sort(*stack_b, (vars->parts_b)[0], 1))
	{
		if ((vars->parts_b)[0] <= 3)
			pushing_remainder_b(stack_a, stack_b, vars);
		else
			repushing_b(stack_a, stack_b, vars, 0);
	}
	else
	{
		while (((vars->parts_b)[0])--)
			get_push(stack_a, stack_b, vars, "pa\n");
		shift_part_b(vars, SHIFT_LEFT);
	}
	if ((vars->parts_b)[0])
		ft_qsort(stack_a, stack_b, vars);
	return (0);
}
