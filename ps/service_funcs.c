/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 14:02:32 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/02 13:28:36 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		shift_part_b(t_vars *vars, _Bool code)
{
	int		i;
	int		n;

	i = 0;
	if (!(vars->parts_b)[0])
		++i;
	while ((vars->parts_b)[i])
		++i;
	if (!code)
	{
		while (i-- > 0)
			(vars->parts_b)[i + 1] = (vars->parts_b)[i];
		(vars->parts_b)[0] = 0;
	}
	else
	{
		n = 0;
		while (n < i)
		{
			(vars->parts_b)[n] = (vars->parts_b)[n + 1];
			++n;
		}
	}
}

void		ft_sort3(t_list **stack_a, t_vars *vars)
{
	int		n;

	n = 0;
	while (n++ < 4)
		ft_backtrack(stack_a, n, vars, 0);
	if ((*stack_a)->next &&\
			*(int*)((*stack_a)->content) > *(int*)((*stack_a)->next->content))
		get_swap(stack_a, vars, "sa\n");
	if (!ft_check_sort(*stack_a, 0))
	{
		get_rotate(stack_a, vars, "ra\n");
		if (*(int*)((*stack_a)->content) > *(int*)((*stack_a)->next->content))
			get_swap(stack_a, vars, "sa\n");
		get_rev_rotate(stack_a, vars, "rra\n");
		if (*(int*)((*stack_a)->content) > *(int*)((*stack_a)->next->content))
			get_swap(stack_a, vars, "sa\n");
	}
}

int			ft_random_sort(t_list *stack, int len, _Bool code)
{
	int		n;

	n = 0;
	if (stack)
		while (stack->next && --len)
		{
			if (!code &&\
					*(int*)(stack->content) > *(int*)(stack->next->content))
				++n;
			else if (code &&\
					*(int*)(stack->content) < *(int*)(stack->next->content))
				++n;
			stack = stack->next;
		}
	return (n);
}

_Bool		ft_isrev(t_list *stack)
{
	t_list	*middle;
	int		sum1;
	int		sum2;
	int		n;

	sum1 = 0;
	sum2 = 0;
	middle = ft_lstn(stack, ft_lstlen(stack) / 2);
	n = ft_lstlen(stack) / 2;
	while (n--)
	{
		sum1 += *(int*)(stack->content);
		stack = stack->next;
	}
	while (stack)
	{
		sum2 += *(int*)(stack->content);
		stack = stack->next;
	}
	if (sum1 > sum2 && ft_random_sort(middle, ft_lstlen(middle), 0) >\
						(int)((double)ft_lstlen(middle) * 0.75))
		return (1);
	return (0);
}

_Bool		ft_isbetween(t_list *stack_a, t_list *stack_b, int num1, int num2)
{
	int		n;

	n = 0;
	while (stack_a || stack_b)
	{
		if (stack_a && *(int*)(stack_a->content) < num2 &&\
								*(int*)(stack_a->content) > num1)
			++n;
		if (stack_b && *(int*)(stack_b->content) < num2 &&\
								*(int*)(stack_b->content) > num1)
			++n;
		if (stack_a)
			stack_a = stack_a->next;
		if (stack_b)
			stack_b = stack_b->next;
	}
	return (n);
}
