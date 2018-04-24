/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanopers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:55:42 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/01/28 17:31:52 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_delelems(t_vars *vars, int n)
{
	free((vars->opers)[n]);
	free((vars->opers)[n + 1]);
	while ((vars->opers)[n] && (vars->opers)[n + 1])
	{
		(vars->opers)[n] = (vars->opers)[n + 2];
		(vars->opers)[n + 1] = (vars->opers)[n + 3];
		n += 2;
	}
}

static void	ft_check_push_or_rotate(t_vars *vars, int *i)
{
	while ((vars->opers)[*i] == (vars->opers)[*i + 1])
		++(*i);
	while ((vars->opers)[*i + 1] &&\
			((!ft_strcmp((vars->opers)[*i], "pa\n") &&\
				!ft_strcmp((vars->opers)[*i + 1], "pb\n")) ||
			(!ft_strcmp((vars->opers)[*i], "pb\n") &&\
				!ft_strcmp((vars->opers)[*i + 1], "pa\n")) ||
			(!ft_strcmp((vars->opers)[*i], "ra\n") &&\
				!ft_strcmp((vars->opers)[*i + 1], "rra\n")) ||
			(!ft_strcmp((vars->opers)[*i], "rra\n") &&\
				!ft_strcmp((vars->opers)[*i + 1], "ra\n")) ||
			(!ft_strcmp((vars->opers)[*i], "rb\n") &&\
				!ft_strcmp((vars->opers)[*i + 1], "rrb\n")) ||
			(!ft_strcmp((vars->opers)[*i], "rrb\n") &&\
				!ft_strcmp((vars->opers)[*i + 1], "rb\n"))))
		ft_delelems(vars, (*i)--);
}

void		ft_cleanopers(t_vars *vars)
{
	int		i;

	i = 0;
	while ((vars->opers)[i] && (vars->opers)[i + 1])
	{
		if ((!ft_strcmp((vars->opers)[i], "sa\n") ||\
			!ft_strcmp((vars->opers)[i], "sb\n")) &&\
				!ft_strcmp((vars->opers)[i], (vars->opers)[i + 1]))
			ft_delelems(vars, i--);
		else if (!ft_strcmp((vars->opers)[i], "pa\n") ||\
					!ft_strcmp((vars->opers)[i], "pb\n") ||
				!ft_strcmp((vars->opers)[i], "ra\n") ||\
					!ft_strcmp((vars->opers)[i], "rra\n") ||
				!ft_strcmp((vars->opers)[i], "rrb\n") ||\
					!ft_strcmp((vars->opers)[i], "rb\n"))
			ft_check_push_or_rotate(vars, &i);
		++i;
	}
}
