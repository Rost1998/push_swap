/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:38:07 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/01/27 21:51:44 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		otkat(t_vars *vars)
{
	--(vars->index);
	free((vars->opers)[vars->index]);
	(vars->opers)[vars->index] = 0;
	return (1);
}

static void		check_stack(char **sw, char **rot, char **rrot, _Bool code)
{
	if (code)
	{
		*sw = "sb\n";
		*rot = "rb\n";
		*rrot = "rrb\n";
	}
	else
	{
		*sw = "sa\n";
		*rot = "ra\n";
		*rrot = "rra\n";
	}
}

int				ft_backtrack(t_list **stack, int n, t_vars *vars, _Bool code)
{
	char	*sw;
	char	*rot;
	char	*rrot;

	check_stack(&sw, &rot, &rrot, code);
	if (ft_check_sort(*stack, 0) || !(*stack))
		return (1);
	if (n <= 0)
		return (0);
	get_swap(stack, vars, sw);
	if (!ft_backtrack(stack, n - 1, vars, code) && otkat(vars))
		o_swap(stack);
	else
		return (1);
	get_rotate(stack, vars, rot);
	if (!ft_backtrack(stack, n - 1, vars, code) && otkat(vars))
		o_rev_rotate(stack);
	else
		return (1);
	get_rev_rotate(stack, vars, rrot);
	if (!ft_backtrack(stack, n - 1, vars, code) && otkat(vars))
		o_rotate(stack);
	else
		return (1);
	return (0);
}
