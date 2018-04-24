/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service2_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:59:50 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/02 20:59:51 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_isneed_swap(t_list **stack_a, t_list **stack_b, t_vars *vars)
{
	if (*(int*)((*stack_a)->content) > *(int*)((*stack_a)->next->content)
			&& !ft_isbetween(*stack_a, *stack_b,\
		*(int*)((*stack_a)->next->content), *(int*)((*stack_a)->content)))
		get_swap(stack_a, vars, "sa\n");
}

void		ft_kost(t_list **stack_a, t_list **stack_b, t_vars *vars)
{
	get_push(stack_b, stack_a, vars, "pb\n");
	if (vars->need_rev && *stack_b)
		get_rotate(stack_b, vars, "rb\n");
}
